/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_object.hpp"

#include "NutritionKeynodes.generated.hpp"

namespace nutritionModule {
class NutritionKeynodes : public ScObject {
  SC_CLASS()
  SC_GENERATED_BODY()

public:
  SC_PROPERTY(Keynode("action_create_nutrition"), ForceCreate)
  static ScAddr action_create_nutrition;

  SC_PROPERTY(Keynode("action_search_nutrition"), ForceCreate)
  static ScAddr action_search_nutrition;

  SC_PROPERTY(Keynode("concept_default_healthy_eating"), ForceCreate)
  static ScAddr concept_default_healthy_eating;

  SC_PROPERTY(Keynode("concept_default_mass_eating"), ForceCreate)
  static ScAddr concept_default_mass_eating;

  SC_PROPERTY(Keynode("concept_default_drying_eating"), ForceCreate)
  static ScAddr concept_default_drying_eating;

  SC_PROPERTY(Keynode("concept_healthy_eating"), ForceCreate)
  static ScAddr concept_healthy_eating;

  SC_PROPERTY(Keynode("concept_mass_eating"), ForceCreate)
  static ScAddr concept_mass_eating;

  SC_PROPERTY(Keynode("concept_drying_eating"), ForceCreate)
  static ScAddr concept_drying_eating;

  SC_PROPERTY(Keynode("concept_eating_from_trainer"), ForceCreate)
  static ScAddr concept_eating_from_trainer;

  SC_PROPERTY(Keynode("concept_nutrition_id"), ForceCreate)
  static ScAddr concept_nutrition_id;

  SC_PROPERTY(Keynode("nrel_breakfast"), ForceCreate)
  static ScAddr nrel_breakfast;

  SC_PROPERTY(Keynode("nrel_lunch"), ForceCreate)
  static ScAddr nrel_lunch;

  SC_PROPERTY(Keynode("nrel_dinner"), ForceCreate)
  static ScAddr nrel_dinner;
};
} // namespace nutritionModule
