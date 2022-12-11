/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "sc-agents-common/utils/AgentUtils.hpp"

#include "keynodes/NutritionKeynodes.hpp"

#include "SearchNutritionAgent.hpp"

using namespace nutritionModule;

SC_AGENT_IMPLEMENTATION(SearchNutritionAgent) {

  ScAddr actionAddr = otherAddr;

  if (checkActionClass(actionAddr) == SC_FALSE)
    return SC_RESULT_OK;

  SC_LOG_DEBUG("SearchNutritionAgent:  start");

  ScAddrVector answerVector;
  initFields();

  ScAddr idLink = argumentExtractor->extractParameter(actionAddr);

  try {
    if (idLink.IsValid())
      answerVector = nutritionSearcher->searchNutrition(idLink);
    else
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams,
                         "SearchNutritionAgent: Invalid arguments");
  } catch (utils::ScException &) {
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                       false);
    SC_LOG_ERROR("SearchNutritionAgent: finished with exception");
    return SC_RESULT_ERROR;
  }

  utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                     true);

  SC_LOG_DEBUG("SearchNutritionAgent:  finished");

  return SC_RESULT_OK;
}

bool nutritionModule::SearchNutritionAgent::checkActionClass(
    const ScAddr &actionNode) {
  return m_memoryCtx.HelperCheckEdge(NutritionKeynodes::action_search_nutrition,
                                     actionNode,
                                     ScType::EdgeAccessConstPosPerm);
}

void nutritionModule::SearchNutritionAgent::initFields() {
  this->argumentExtractor =
      std::make_unique<commonModule::ArgumentExtractor>(&m_memoryCtx);
  this->nutritionSearcher = std::make_unique<NutritionSearcher>(&m_memoryCtx);
}
