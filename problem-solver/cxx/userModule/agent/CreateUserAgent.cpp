/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "sc-agents-common/utils/AgentUtils.hpp"

#include "keynodes/UserKeynodes.hpp"

#include "CreateUserAgent.hpp"

using namespace userModule;

SC_AGENT_IMPLEMENTATION(CreateUserAgent) {
  ScAddr actionAddr = otherAddr;

  if (checkActionClass(actionAddr) == SC_FALSE)
    return SC_RESULT_OK;

  SC_LOG_DEBUG("CreateUserAgent: CreateUserAgent started");

  ScAddrVector answerVector;
  initFields();

  ScAddr loginLink = argumentExtractor->extractParameter(actionAddr);
  ScAddr passwordLink = argumentExtractor->extractParameter(
      actionAddr, scAgentsCommon::CoreKeynodes::rrel_2);

  try {
    if (loginLink.IsValid() && passwordLink.IsValid())
      answerVector = userRegistrationManager->manage({loginLink, passwordLink});
    else
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams,
                         "CreateUserAgent: Invalid arguments");
  } catch (utils::ScException &) {
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                       false);
    SC_LOG_ERROR("CreateUserAgent: CreateUserAgent finished with exception");
    return SC_RESULT_ERROR;
  }

  utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                     true);
  SC_LOG_DEBUG("CreateUserAgent: CreateUserAgent finished");
  return SC_RESULT_OK;
}

bool CreateUserAgent::checkActionClass(const ScAddr &actionNode) {
  return m_memoryCtx.HelperCheckEdge(UserKeynodes::action_create_user,
                                     actionNode,
                                     ScType::EdgeAccessConstPosPerm);
}

void CreateUserAgent::initFields() {
  this->userRegistrationManager =
      std::make_unique<CreateUserManager>(&m_memoryCtx);
  this->argumentExtractor =
      std::make_unique<commonModule::ArgumentExtractor>(&m_memoryCtx);
}
