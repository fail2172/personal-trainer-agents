/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#pragma once

#include "sc-memory/sc_module.hpp"

#include "NutritionModule.generated.hpp"

namespace nutritionModule {

class NutritionModule : public ScModule {
  SC_CLASS(LoadOrder(100))
  SC_GENERATED_BODY()

  virtual sc_result InitializeImpl() override;

  virtual sc_result ShutdownImpl() override;
};

} // namespace nutritionModule
