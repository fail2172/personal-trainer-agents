/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "sc-memory/sc_memory.hpp"

#include "keynodes/NutritionKeynodes.hpp"

namespace nutritionModule {

ScAddr NutritionKeynodes::action_create_nutrition;
ScAddr NutritionKeynodes::action_search_nutrition;

ScAddr NutritionKeynodes::concept_default_healthy_eating;
ScAddr NutritionKeynodes::concept_default_mass_eating;
ScAddr NutritionKeynodes::concept_default_drying_eating;
ScAddr NutritionKeynodes::concept_healthy_eating;
ScAddr NutritionKeynodes::concept_mass_eating;
ScAddr NutritionKeynodes::concept_drying_eating;
ScAddr NutritionKeynodes::concept_eating_from_trainer;
ScAddr NutritionKeynodes::concept_nutrition_id;

ScAddr NutritionKeynodes::nrel_breakfast;
ScAddr NutritionKeynodes::nrel_lunch;
ScAddr NutritionKeynodes::nrel_dinner;
ScAddr NutritionKeynodes::nrel_diet_id;

} // namespace nutritionModule
