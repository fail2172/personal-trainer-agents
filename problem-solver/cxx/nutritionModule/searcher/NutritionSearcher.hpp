/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

#include "searcher/IdLinkSearcher.hpp"

#include "template/NutritionTemplates.hpp"

namespace nutritionModule {
class NutritionSearcher {
private:
  ScMemoryContext *context;

  std::unique_ptr<NutritionTemplates> nutritionTemplates;
  std::unique_ptr<commonModule::IdLinkSearcher> idLinkSearcher;

public:
  explicit NutritionSearcher(ScMemoryContext *context);

  ScAddrVector searchNutrition(const ScAddr &idLink);
};

} // namespace nutritionModule
