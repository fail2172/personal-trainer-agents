/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "sc-agents-common/utils/GenerationUtils.hpp"
#include "sc-agents-common/utils/IteratorUtils.hpp"

#include "CreateNutritionManager.hpp"

using namespace nutritionModule;

CreateNutritionManager::CreateNutritionManager(ScMemoryContext *context)
    : AgentManager(context) {
  this->nutritionGenerator = std::make_unique<NutritionGenerator>(context);
}

ScAddrVector nutritionModule::CreateNutritionManager::manage(
    const ScAddrVector &processParameters) const {
  SC_LOG_DEBUG("CreateNutritionManager: start");

  ScAddr breakfastSet = processParameters[0];
  ScAddr lunchSet = processParameters[1];
  ScAddr dinnerSet = processParameters[2];

  ScAddrVector productsBreakfast = utils::IteratorUtils::getAllWithType(
      context, breakfastSet, ScType::NodeConst);
  ScAddrVector productsLunch = utils::IteratorUtils::getAllWithType(
      context, lunchSet, ScType::NodeConst);
  ScAddrVector productsDinner = utils::IteratorUtils::getAllWithType(
      context, dinnerSet, ScType::NodeConst);
  ScAddrVector resultVector = nutritionGenerator->createFoodIntake(
      productsBreakfast, productsLunch, productsDinner);

  SC_LOG_DEBUG("CreateNutritionManager: finish");

  return resultVector;
}
