/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "sc-agents-common/utils/IteratorUtils.hpp"

#include "keynodes/UserKeynodes.hpp"

#include "UpdateUserManager.hpp"

using namespace userModule;

UpdateUserManager::UpdateUserManager(ScMemoryContext *context)
    : AgentManager(context) {
  this->userSearcher = std::make_unique<UserSearcher>(context);
  this->addUserDiseases = std::make_unique<UserDiseasesGenerator>(context);
}

ScAddrVector
UpdateUserManager::manage(const ScAddrVector &processParameters) const {
  SC_LOG_DEBUG("UpdateUserManager: start");

  ScAddr loginLink = processParameters[0];
  ScAddr userParamSet = processParameters[1];
  ScAddrVector answerVector;

  ScAddrVector userElements = userSearcher->searchUserByLogin(loginLink);
  ScAddr userAddr = userElements.at(UserSearcher::USER_INDEX);

  for (const ScAddr &item : userElements)
    answerVector.push_back(item);

  ScAddr diseaseSet = utils::IteratorUtils::getAnyByOutRelation(
      context, userParamSet, UserKeynodes::nrel_diseases_param);

  if (diseaseSet.IsValid()) {
    ScAddrVector diseases = utils::IteratorUtils::getAllWithType(
        context, diseaseSet, ScType::NodeConst);
    ScAddrVector userWithDiseases =
        addUserDiseases->addDiseasesToUser(userAddr, diseases);

    for (const ScAddr &item : userWithDiseases)
      answerVector.push_back(item);
  }

  SC_LOG_DEBUG("UpdateUserManager: finish");

  return answerVector;
}
