/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "sc-agents-common/utils/GenerationUtils.hpp"

#include "keynodes/UserKeynodes.hpp"

#include "UserDiseasesGenerator.hpp"

using namespace userModule;

UserDiseasesGenerator::UserDiseasesGenerator(ScMemoryContext *context)
    : context(context) {}

ScAddrVector
UserDiseasesGenerator::addDiseasesToUser(const ScAddr &userAddr,
                                         const ScAddrVector &diseases) {
  SC_LOG_DEBUG("UserDiseasesGenerator: start");

  ScAddr diseaseSet = context->CreateNode(ScType::NodeConstTuple);
  ScAddrVector answerVector = {userAddr, diseaseSet};

  ScAddr relationPairEdge =
      context->CreateEdge(ScType::EdgeDCommonConst, userAddr, diseaseSet);
  ScAddr relationAccessArc =
      context->CreateEdge(ScType::EdgeAccessConstPosPerm,
                          UserKeynodes::nrel_disease_list, relationPairEdge);

  answerVector.push_back(relationPairEdge);
  answerVector.push_back(relationAccessArc);

  for (const ScAddr &item : diseases) {
    answerVector.push_back(
        context->CreateEdge(ScType::EdgeAccessConstPosPerm, diseaseSet, item));
    answerVector.push_back(item);
  }

  SC_LOG_DEBUG("UserDiseasesGenerator: finish");

  return answerVector;
}
