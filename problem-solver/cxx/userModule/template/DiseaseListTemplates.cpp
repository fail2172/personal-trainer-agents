//
// Created by sova on 08.12.22.
//

#include "keynodes/UserKeynodes.hpp"

#include "DiseaseListTemplates.hpp"

namespace userModule {
std::string const DiseaseListTemplates::USER_ALIAS = "_user_params_access_arc";
std::string const DiseaseListTemplates::DISEASE_LIST_RELATION_PAIR_ALIAS =
    "_user_params_set";
std::string const DiseaseListTemplates::DISEASE_LIST_ALIAS =
    "_disease_param_relation_pair";
std::string const DiseaseListTemplates::DISEASE_LIST_ACCESS_ARC_ALIAS =
    "_disease_set";

std::unique_ptr<ScTemplate>
DiseaseListTemplates::receiveUserDiseasesTemplate(const ScAddr &userAddr) {
  std::unique_ptr<ScTemplate> userParamTemplates =
      std::make_unique<ScTemplate>();

  userParamTemplates->TripleWithRelation(
      userAddr >> USER_ALIAS,
      ScType::EdgeDCommonVar >> DISEASE_LIST_RELATION_PAIR_ALIAS,
      ScType::NodeVarTuple >> DISEASE_LIST_ALIAS,
      ScType::EdgeAccessVarPosPerm >> DISEASE_LIST_ACCESS_ARC_ALIAS,
      UserKeynodes::nrel_disease_list);

  return userParamTemplates;
}
} // namespace userModule
