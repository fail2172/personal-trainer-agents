/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "keynodes/UserKeynodes.hpp"

#include "UserParamsTemplates.hpp"

namespace userModule {
std::string const UserParamsTemplates::USER_PARAMS_ACCESS_ARC_ALIAS =
    "_user_params_access_arc";
std::string const UserParamsTemplates::USER_PARAMS_SET_ALIAS =
    "_user_params_set";
std::string const UserParamsTemplates::DISEASES_PARAM_RELATION_PAIR_ALIAS =
    "_disease_param_relation_pair";
std::string const UserParamsTemplates::DISEASES_SET_ALIAS = "_disease_set";
std::string const UserParamsTemplates::DISEASES_PARAM_ACCESS_ARC_ALIAS =
    "_disease_param_access_arc";

std::unique_ptr<ScTemplate>
UserParamsTemplates::receiveDiseasesParamTemplate(const ScAddr &userParamsSet) {
  std::unique_ptr<ScTemplate> userParamTemplates =
      std::make_unique<ScTemplate>();

  userParamTemplates->Triple(UserKeynodes::nrel_user_params,
                             ScType::EdgeAccessVarPosPerm >>
                                 USER_PARAMS_ACCESS_ARC_ALIAS,
                             userParamsSet >> USER_PARAMS_SET_ALIAS);

  userParamTemplates->TripleWithRelation(
      USER_PARAMS_SET_ALIAS,
      ScType::EdgeDCommonVar >> DISEASES_PARAM_RELATION_PAIR_ALIAS,
      ScType::NodeVarTuple >> DISEASES_SET_ALIAS,
      ScType::EdgeAccessVarPosPerm >> DISEASES_PARAM_ACCESS_ARC_ALIAS,
      UserKeynodes::nrel_diseases_param);

  return userParamTemplates;
}
} // namespace userModule
