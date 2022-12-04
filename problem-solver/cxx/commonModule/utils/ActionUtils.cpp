/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "ActionUtils.hpp"

#include "sc-agents-common/keynodes/coreKeynodes.hpp"
#include "sc-agents-common/utils/AgentUtils.hpp"

#include "keynodes/Keynodes.hpp"

using namespace commonModule;

bool ActionUtils::initAgentAndWaitForActionSuccessfulFinish(
    ScMemoryContext *context, ScAddr const &actionAddr, int const &waitTime) {
  return utils::AgentUtils::applyAction(context, actionAddr, waitTime) &&
         context->HelperCheckEdge(
             scAgentsCommon::CoreKeynodes::question_finished_successfully,
             actionAddr, ScType::EdgeAccessConstPosPerm);
}

bool ActionUtils::isActionDeactivated(ScMemoryContext *context,
                                      ScAddr const &action) {
  return context->HelperCheckEdge(commonModule::Keynodes::action_deactivated,
                                  action, ScType::EdgeAccessConstPosPerm);
}
