/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "sc-agents-common/utils/AgentUtils.hpp"

#include "keynodes/UserKeynodes.hpp"

#include "SearchUserAgent.hpp"

using namespace userModule;

SC_AGENT_IMPLEMENTATION(SearchUserAgent) {
  ScAddr actionAddr = otherAddr;

  if (checkActionClass(actionAddr) == SC_FALSE)
    return SC_RESULT_OK;

  SC_LOG_DEBUG("SearchUserAgent: SearchUserAgent started");

  ScAddrVector answerVector;
  initFields();

  ScAddr loginLink = argumentExtractor->extractParameter(actionAddr);

  try {
    if (loginLink.IsValid())
      answerVector = userSearcher->searchUserByLogin(loginLink);
    else
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams,
                         "SearchUserAgent: Invalid arguments");
  } catch (utils::ScException &) {
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                       false);
    SC_LOG_ERROR("SearchUserAgent: SearchUserAgent finished with exception");
    return SC_RESULT_ERROR;
  }

  utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                     true);
  SC_LOG_DEBUG("SearchUserAgent: SearchUserAgent finished");
  return SC_RESULT_OK;
}

bool userModule::SearchUserAgent::checkActionClass(const ScAddr &actionNode) {
  return m_memoryCtx.HelperCheckEdge(UserKeynodes::action_search_user,
                                     actionNode,
                                     ScType::EdgeAccessConstPosPerm);
}

void userModule::SearchUserAgent::initFields() {
  this->argumentExtractor =
      std::make_unique<commonModule::ArgumentExtractor>(&m_memoryCtx);
  this->userSearcher = std::make_unique<UserSearcher>(&m_memoryCtx);
}
