/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "keynodes/UserKeynodes.hpp"

#include "CreateUserManager.hpp"

using namespace userModule;

CreateUserManager::CreateUserManager(ScMemoryContext *context)
    : AgentManager(context) {
  this->userGenerator = std::make_unique<UserGenerator>(context);
  this->userSearcher = std::make_unique<UserSearcher>(context);
}

ScAddrVector
CreateUserManager::manage(const ScAddrVector &processParameters) const {
  SC_LOG_DEBUG("CreateUserManager: start");

  ScAddr loginLink = processParameters[0];
  ScAddr passwordLink = processParameters[1];

  if (!userSearcher->searchUserByLogin(loginLink).empty())
    SC_THROW_EXCEPTION(
        utils::ExceptionInvalidParams,
        "CreateUserManager: User with this login already exists");

  ScAddrVector answerVector =
      userGenerator->createUser(loginLink, passwordLink);

  SC_LOG_DEBUG("CreateUserManager: finish");

  return answerVector;
}
