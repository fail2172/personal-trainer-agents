/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "utils/ActionUtils.hpp"

#include "agent/CreateUserAgent.hpp"
#include "agent/SearchUserAgent.hpp"

#include "keynodes/UserKeynodes.hpp"

#include "UserModule.hpp"

using namespace userModule;

SC_IMPLEMENT_MODULE(UserModule)

sc_result UserModule::InitializeImpl() {
  if (userModule::UserKeynodes::InitGlobal() == SC_FALSE)
    return SC_RESULT_ERROR;

  ScMemoryContext ctx(sc_access_lvl_make_min, "userModule");
  if (ActionUtils::isActionDeactivated(&ctx, UserKeynodes::action_create_user))
    SC_LOG_DEBUG("action_create_user is deactivated");
  else
    SC_AGENT_REGISTER(CreateUserAgent);

  if (ActionUtils::isActionDeactivated(&ctx, UserKeynodes::action_search_user))
    SC_LOG_DEBUG("action_search_user is deactivated");
  else
    SC_AGENT_REGISTER(SearchUserAgent);

  return SC_RESULT_OK;
}

sc_result UserModule::ShutdownImpl() {
  SC_AGENT_UNREGISTER(CreateUserAgent)
  SC_AGENT_UNREGISTER(SearchUserAgent)

  return SC_RESULT_OK;
}
