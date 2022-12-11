/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "sc-agents-common/utils/AgentUtils.hpp"

#include "keynodes/NutritionKeynodes.hpp"

#include "CreateNutritionAgent.hpp"

using namespace nutritionModule;

SC_AGENT_IMPLEMENTATION(CreateNutritionAgent) {
  ScAddr actionAddr = otherAddr;

  if (checkActionClass(actionAddr) == SC_FALSE)
    return SC_RESULT_OK;

  SC_LOG_DEBUG("CreateNutritionAgent: start");

  ScAddrVector answerVector;
  initFields();

  ScAddr productsForBreakfast = argumentExtractor->extractParameter(actionAddr);
  ScAddr productsForLunch = argumentExtractor->extractParameter(
      actionAddr, scAgentsCommon::CoreKeynodes::rrel_2);
  ScAddr productsForDinner = argumentExtractor->extractParameter(
      actionAddr, scAgentsCommon::CoreKeynodes::rrel_3);

  try {
    if (productsForBreakfast.IsValid() && productsForLunch.IsValid() &&
        productsForDinner.IsValid())
      answerVector = createNutritionManager->manage(
          {productsForBreakfast, productsForLunch, productsForDinner});
    else
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams,
                         "CreateNutritionAgent: Invalid arguments");
  } catch (utils::ScException &e) {
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                       false);
    SC_LOG_ERROR(e.Description());
    return SC_RESULT_ERROR;
  }

  utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, answerVector,
                                     true);

  SC_LOG_DEBUG("CreateNutritionAgent: finish");

  return SC_RESULT_OK;
}

bool CreateNutritionAgent::checkActionClass(const ScAddr &actionNode) {
  return m_memoryCtx.HelperCheckEdge(NutritionKeynodes::action_create_nutrition,
                                     actionNode,
                                     ScType::EdgeAccessConstPosPerm);
}

void CreateNutritionAgent::initFields() {
  this->createNutritionManager =
      std::make_unique<CreateNutritionManager>(&m_memoryCtx);
  this->argumentExtractor =
      std::make_unique<commonModule::ArgumentExtractor>(&m_memoryCtx);
}
