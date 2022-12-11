/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */
#include "NutritionTemplates.hpp"

#include "keynodes/NutritionKeynodes.hpp"

namespace nutritionModule {

std::string const NutritionTemplates::DIET_ALIAS = "_diet_alias";
std::string const NutritionTemplates::ID_LINK_TYPE_RELATION_PAIR_ALIAS =
    "_id_link_type_relation_pair_alias";
std::string const NutritionTemplates::ID_LINK_TYPE_ACCESS_ARC_ALIAS =
    "_id_link_type_access_arc_alias";
std::string const
    NutritionTemplates::NUTRITION_BREAKFAST_TYPE_RELATION_PAIR_ALIAS =
        "_nutrition_breakfast_type_relation_pair_alias";
std::string const NutritionTemplates::PRODUCT_SET_BREAKFAST_ALIAS =
    "_products_set_breakfast_alias";
std::string const
    NutritionTemplates::NUTRITION_BREAKFAST_TYPE_ACCESS_ARC_ALIAS =
        "_nutrition_breakfast_type_access_arc_alias";
std::string const NutritionTemplates::NUTRITION_LUNCH_TYPE_RELATION_PAIR_ALIAS =
    "_nutrition_lunch_type_relation_pair_alias";
std::string const NutritionTemplates::PRODUCT_SET_LUNCH_ALIAS =
    "_products_set_lunch_alias";
std::string const NutritionTemplates::NUTRITION_LUNCH_TYPE_ACCESS_ARC_ALIAS =
    "_nutrition_lunch_type_access_arc_alias";
std::string const
    NutritionTemplates::NUTRITION_DINNER_TYPE_RELATION_PAIR_ALIAS =
        "_nutrition_dinner_type_relation_pair_alias";
std::string const NutritionTemplates::PRODUCT_SET_DINNER_ALIAS =
    "_products_set_dinner_alias";
std::string const NutritionTemplates::NUTRITION_DINNER_TYPE_ACCESS_ARC_ALIAS =
    "_nutrition_dinner_type_access_arc_alias";

std::unique_ptr<ScTemplate>
NutritionTemplates::receiveNutritionTemplate(const ScAddr &idLink) {

  std::unique_ptr<ScTemplate> NutritionTemplate =
      std::make_unique<ScTemplate>();

  NutritionTemplate->TripleWithRelation(
      ScType::NodeVar >> DIET_ALIAS,
      ScType::EdgeDCommonVar >> ID_LINK_TYPE_RELATION_PAIR_ALIAS, idLink,
      ScType::EdgeAccessVarPosPerm >> ID_LINK_TYPE_ACCESS_ARC_ALIAS,
      NutritionKeynodes::nrel_diet_id);

  NutritionTemplate->TripleWithRelation(
      DIET_ALIAS,
      ScType::EdgeDCommonVar >> NUTRITION_BREAKFAST_TYPE_RELATION_PAIR_ALIAS,
      ScType::NodeVarTuple >> PRODUCT_SET_BREAKFAST_ALIAS,
      ScType::EdgeAccessVarPosPerm >> NUTRITION_BREAKFAST_TYPE_ACCESS_ARC_ALIAS,
      NutritionKeynodes::nrel_breakfast);

  NutritionTemplate->TripleWithRelation(
      DIET_ALIAS,
      ScType::EdgeDCommonVar >> NUTRITION_LUNCH_TYPE_RELATION_PAIR_ALIAS,
      ScType::NodeVarTuple >> PRODUCT_SET_LUNCH_ALIAS,
      ScType::EdgeAccessVarPosPerm >> NUTRITION_LUNCH_TYPE_ACCESS_ARC_ALIAS,
      NutritionKeynodes::nrel_lunch);

  NutritionTemplate->TripleWithRelation(
      DIET_ALIAS,
      ScType::EdgeDCommonVar >> NUTRITION_DINNER_TYPE_RELATION_PAIR_ALIAS,
      ScType::NodeVarTuple >> PRODUCT_SET_DINNER_ALIAS,
      ScType::EdgeAccessVarPosPerm >> NUTRITION_DINNER_TYPE_ACCESS_ARC_ALIAS,
      NutritionKeynodes::nrel_dinner);

  return NutritionTemplate;
}

} // namespace nutritionModule
