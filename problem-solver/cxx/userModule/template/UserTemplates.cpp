/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "UserTemplates.hpp"

#include "keynodes/UserKeynodes.hpp"

namespace userModule {
std::string const UserTemplates::USER_ACCESS_ARC_ALIAS =
    "_user_access_arc_alias";
std::string const UserTemplates::USER_ALIAS = "_user";
std::string const UserTemplates::LOGIN_ALIAS = "_login";
std::string const UserTemplates::PASSWORD_ALIAS = "_password";
std::string const UserTemplates::LOGIN_RELATION_PAIR_ALIAS =
    "_login_relation_pair_alias";
std::string const UserTemplates::LOGIN_ACCESS_ARC_ALIAS =
    "_login_access_arc_alias";
std::string const UserTemplates::PASSWORD_RELATION_PAIR_ALIAS =
    "_password_relation_pair_alias";
std::string const UserTemplates::PASSWORD_ACCESS_ARC_ALIAS =
    "_password_access_arc_alias";

std::unique_ptr<ScTemplate>
UserTemplates::receiveUserTemplate(const ScAddr &loginLink,
                                   const ScAddr &passwordLink) {
  std::unique_ptr<ScTemplate> userTemplate = std::make_unique<ScTemplate>();

  userTemplate->Triple(UserKeynodes::concept_user,
                       ScType::EdgeAccessVarPosPerm >> USER_ACCESS_ARC_ALIAS,
                       ScType::NodeVar >> USER_ALIAS);

  userTemplate->Triple(UserKeynodes::concept_registered_login,
                       ScType::EdgeAccessVarPosPerm, loginLink);

  userTemplate->TripleWithRelation(
      USER_ALIAS, ScType::EdgeDCommonVar >> LOGIN_RELATION_PAIR_ALIAS,
      loginLink >> LOGIN_ALIAS,
      ScType::EdgeAccessVarPosPerm >> LOGIN_ACCESS_ARC_ALIAS,
      UserKeynodes::nrel_login);

  userTemplate->TripleWithRelation(
      USER_ALIAS, ScType::EdgeDCommonVar >> PASSWORD_RELATION_PAIR_ALIAS,
      passwordLink.IsValid() ? passwordLink : ScType::LinkVar >> PASSWORD_ALIAS,
      ScType::EdgeAccessVarPosPerm >> PASSWORD_ACCESS_ARC_ALIAS,
      UserKeynodes::nrel_password);

  return userTemplate;
}

std::unique_ptr<ScTemplate>
UserTemplates::receiveUserTemplate(const ScAddr &loginLink) {
  return receiveUserTemplate(loginLink, {});
}
} // namespace userModule
