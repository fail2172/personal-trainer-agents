/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */
#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

#include "generator/NutritionGenerator.hpp"

#include "manager/AgentManager.hpp"

#include "searcher/NutritionSearcher.hpp"
#include "searcher/UserSearcher.hpp"

namespace nutritionModule {
class CreateNutritionManager : public commonModule::AgentManager {
private:
  std::unique_ptr<NutritionGenerator> nutritionGenerator;

public:
  explicit CreateNutritionManager(ScMemoryContext *context);

  ScAddrVector manage(ScAddrVector const &processParameters) const override;
};
} // namespace nutritionModule
