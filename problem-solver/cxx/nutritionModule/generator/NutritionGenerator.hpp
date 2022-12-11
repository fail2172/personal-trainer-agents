/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

#include "generator/IdGenerator.hpp"
#include "searcher/NutritionSearcher.hpp"
#include "template/NutritionTemplates.hpp"

namespace nutritionModule {
class NutritionGenerator {
private:
  ScMemoryContext *context;

  std::unique_ptr<NutritionTemplates> nutritionTemplates;
  std::unique_ptr<commonModule::IdGenerator> idGenerator;

public:
  explicit NutritionGenerator(ScMemoryContext *context);

  ScAddrVector createFoodIntake(const ScAddrVector &productsBreakfast,
                                const ScAddrVector &productsLunch,
                                const ScAddrVector &productsDinner);
};

} // namespace nutritionModule
