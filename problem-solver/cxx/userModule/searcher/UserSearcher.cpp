/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "keynodes/UserKeynodes.hpp"

#include "UserSearcher.hpp"

using namespace userModule;

UserSearcher::UserSearcher(ScMemoryContext *context) : context(context) {
  this->userTemplates = std::make_unique<UserTemplates>();
  this->loginSearcher = std::make_unique<LoginSearcher>(context);
}

ScAddrVector UserSearcher::searchUserByLogin(const ScAddr &loginLink) {
  ScAddr registeredLogin =
      loginSearcher->searchLogin(context->GetLinkContent(loginLink));

  if (!registeredLogin.IsValid()) {
    SC_LOG_WARNING("UserSearcher: User not found");
    return {};
  }

  std::unique_ptr<ScTemplate> userConstructionTemplate =
      userTemplates->receiveUserTemplate(registeredLogin);

  if (userConstructionTemplate->IsEmpty())
    SC_THROW_EXCEPTION(
        utils::ExceptionCritical,
        "UserSearcher: User construction template has not been created");

  ScTemplateSearchResult userConstructionTemplateResults;
  context->HelperSearchTemplate(*userConstructionTemplate,
                                userConstructionTemplateResults);

  ScTemplateSearchResultItem userConstructionTemplateResult =
      userConstructionTemplateResults[0];

  SC_LOG_DEBUG("UserSearcher: User found");

  return {
      UserKeynodes::concept_user,
      userConstructionTemplateResult[UserTemplates::USER_ACCESS_ARC_ALIAS],
      userConstructionTemplateResult[UserTemplates::USER_ALIAS],
      userConstructionTemplateResult[UserTemplates::LOGIN_RELATION_PAIR_ALIAS],
      registeredLogin,
      userConstructionTemplateResult[UserTemplates::LOGIN_ACCESS_ARC_ALIAS],
      UserKeynodes::nrel_login,
      userConstructionTemplateResult
          [UserTemplates::PASSWORD_RELATION_PAIR_ALIAS],
      userConstructionTemplateResult[UserTemplates::PASSWORD_ALIAS],
      userConstructionTemplateResult[UserTemplates::PASSWORD_ACCESS_ARC_ALIAS],
      UserKeynodes::nrel_password};
}
