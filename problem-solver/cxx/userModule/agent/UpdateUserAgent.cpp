/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "sc-agents-common/utils/AgentUtils.hpp"

#include "keynodes/UserKeynodes.hpp"

#include "UpdateUserAgent.hpp"

using namespace userModule;

SC_AGENT_IMPLEMENTATION(UpdateUserAgent) {
  ScAddr actionAddr = otherAddr;

  if (checkActionClass(actionAddr) == SC_FALSE)
    return SC_RESULT_OK;

  SC_LOG_DEBUG("UpdateUserAgent: start");

  ScAddrVector answerVector;
  initFields();

  ScAddr loginLink = argumentExtractor->extractParameter(actionAddr);
  ScAddr userParamsSet = argumentExtractor->extractParameter(
      actionAddr, scAgentsCommon::CoreKeynodes::rrel_2);

  try {
    if (loginLink.IsValid())
      answerVector = updateUserManager->manage({loginLink, userParamsSet});
    else
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams,
                         "UpdateUserAgent: Invalid arguments");
  } catch (utils::ScException &) {
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                       false);
    SC_LOG_ERROR("UpdateUserAgent: UpdateUserAgent finished with exception");
    return SC_RESULT_ERROR;
  }

  utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                     true);
  SC_LOG_DEBUG("UpdateUserAgent: finish");
  return SC_RESULT_OK;
}

bool UpdateUserAgent::checkActionClass(const ScAddr &actionNode) {
  return m_memoryCtx.HelperCheckEdge(UserKeynodes::action_update_user,
                                     actionNode,
                                     ScType::EdgeAccessConstPosPerm);
}

void UpdateUserAgent::initFields() {
  this->argumentExtractor =
      std::make_unique<commonModule::ArgumentExtractor>(&m_memoryCtx);
  this->updateUserManager = std::make_unique<UpdateUserManager>(&m_memoryCtx);
}
