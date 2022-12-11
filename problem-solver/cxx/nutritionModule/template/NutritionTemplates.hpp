/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_template.hpp"

namespace nutritionModule {
class NutritionTemplates {
public:
  static std::string const DIET_ALIAS;
  static std::string const ID_LINK_TYPE_RELATION_PAIR_ALIAS;
  static std::string const ID_LINK_TYPE_ACCESS_ARC_ALIAS;
  static std::string const NUTRITION_BREAKFAST_TYPE_RELATION_PAIR_ALIAS;
  static std::string const PRODUCT_SET_BREAKFAST_ALIAS;
  static std::string const NUTRITION_BREAKFAST_TYPE_ACCESS_ARC_ALIAS;
  static std::string const NUTRITION_LUNCH_TYPE_RELATION_PAIR_ALIAS;
  static std::string const PRODUCT_SET_LUNCH_ALIAS;
  static std::string const NUTRITION_LUNCH_TYPE_ACCESS_ARC_ALIAS;
  static std::string const NUTRITION_DINNER_TYPE_RELATION_PAIR_ALIAS;
  static std::string const PRODUCT_SET_DINNER_ALIAS;
  static std::string const NUTRITION_DINNER_TYPE_ACCESS_ARC_ALIAS;

  static std::unique_ptr<ScTemplate>
  receiveNutritionTemplate(ScAddr const &idLink);
};
} // namespace nutritionModule
