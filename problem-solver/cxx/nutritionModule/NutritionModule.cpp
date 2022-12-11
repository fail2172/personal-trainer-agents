/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "utils/ActionUtils.hpp"

#include "agent/CreateNutritionAgent.hpp"
#include "agent/SearchNutritionAgent.hpp"

#include "keynodes/NutritionKeynodes.hpp"

#include "NutritionModule.hpp"

using namespace nutritionModule;

SC_IMPLEMENT_MODULE(NutritionModule)

sc_result NutritionModule::InitializeImpl() {
  if (NutritionKeynodes::InitGlobal() == SC_FALSE)
    return SC_RESULT_ERROR;

  ScMemoryContext ctx(sc_access_lvl_make_min, "nutritionModule");

  if (ActionUtils::isActionDeactivated(
          &ctx, NutritionKeynodes::action_create_nutrition))
    SC_LOG_DEBUG("action_create_nutrition is deactivated");
  else
    SC_AGENT_REGISTER(CreateNutritionAgent);

  if (ActionUtils::isActionDeactivated(
          &ctx, NutritionKeynodes::action_search_nutrition))
    SC_LOG_DEBUG("action_search_nutrition is deactivated");
  else
    SC_AGENT_REGISTER(SearchNutritionAgent);

  return SC_RESULT_OK;
}

sc_result NutritionModule::ShutdownImpl() {
  SC_AGENT_UNREGISTER(CreateNutritionAgent)
  SC_AGENT_UNREGISTER(SearchNutritionAgent)

  return SC_RESULT_OK;
}
