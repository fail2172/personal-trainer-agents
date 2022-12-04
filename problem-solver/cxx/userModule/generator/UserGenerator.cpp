/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "sc-agents-common/utils/CommonUtils.hpp"

#include "keynodes/UserKeynodes.hpp"

#include "UserGenerator.hpp"

using namespace userModule;

UserGenerator::UserGenerator(ScMemoryContext *context) : context(context) {
  this->userTemplates = std::make_unique<UserTemplates>();
}

ScAddrVector UserGenerator::createUser(const ScAddr &loginLink,
                                       const ScAddr &passwordLink) {
  std::unique_ptr<ScTemplate> userConstructionTemplate =
      userTemplates->receiveUserTemplate(loginLink, passwordLink);

  if (userConstructionTemplate->IsEmpty())
    SC_THROW_EXCEPTION(
        utils::ExceptionCritical,
        "UserGenerator: User construction template has not been created");

  ScTemplateGenResult userConstructionTemplateResult;
  context->HelperGenTemplate(*userConstructionTemplate,
                             userConstructionTemplateResult);

  if (!userConstructionTemplateResult.Size())
    SC_THROW_EXCEPTION(utils::ExceptionCritical,
                       "UserGenerator: User has not been created");

  SC_LOG_DEBUG("UserGenerator: User created");

  return {
      UserKeynodes::concept_user,
      userConstructionTemplateResult[UserTemplates::USER_ACCESS_ARC_ALIAS],
      userConstructionTemplateResult[UserTemplates::USER_ALIAS],
      userConstructionTemplateResult[UserTemplates::LOGIN_RELATION_PAIR_ALIAS],
      loginLink,
      userConstructionTemplateResult[UserTemplates::LOGIN_ACCESS_ARC_ALIAS],
      UserKeynodes::nrel_login,
      userConstructionTemplateResult
          [UserTemplates::PASSWORD_RELATION_PAIR_ALIAS],
      passwordLink,
      userConstructionTemplateResult[UserTemplates::PASSWORD_ACCESS_ARC_ALIAS],
      UserKeynodes::nrel_password};
}
