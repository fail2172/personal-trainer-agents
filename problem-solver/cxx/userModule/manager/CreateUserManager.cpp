/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "CreateUserManager.hpp"

#include "keynodes/UserKeynodes.hpp"

using namespace userModule;

CreateUserManager::CreateUserManager(ScMemoryContext *context)
    : AgentManager(context) {
  this->userGenerator = std::make_unique<UserGenerator>(context);
  this->loginSearcher = std::make_unique<LoginSearcher>(context);
}

ScAddrVector userModule::CreateUserManager::manage(
    const ScAddrVector &processParameters) const {
  ScAddr loginLink = processParameters[0];
  ScAddr passwordLink = processParameters[1];

  if (loginSearcher->searchLogin(context->GetLinkContent(loginLink)).IsValid())
    SC_THROW_EXCEPTION(
        utils::ExceptionInvalidParams,
        "CreateUserManager: User with this login already exists");

  return userGenerator->createUser(loginLink, passwordLink);
}
