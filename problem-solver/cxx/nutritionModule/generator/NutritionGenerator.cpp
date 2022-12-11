/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "NutritionGenerator.hpp"
#include "keynodes/NutritionKeynodes.hpp"
#include "sc-agents-common/utils/CommonUtils.hpp"

using namespace nutritionModule;

NutritionGenerator::NutritionGenerator(ScMemoryContext *context)
    : context(context) {
  this->nutritionTemplates = std::make_unique<NutritionTemplates>();
  this->idGenerator = std::make_unique<commonModule::IdGenerator>(context);
}

ScAddrVector
NutritionGenerator::createFoodIntake(const ScAddrVector &productsBreakfast,
                                     const ScAddrVector &productsLunch,
                                     const ScAddrVector &productsDinner) {

  SC_LOG_DEBUG("NutritionGenerator: start");

  ScAddr id = idGenerator->createId(NutritionKeynodes::concept_nutrition_id);

  std::unique_ptr<ScTemplate> foodIntakeConstructionTemplate =
      nutritionTemplates->receiveNutritionTemplate(id);

  if (foodIntakeConstructionTemplate->IsEmpty())
    SC_THROW_EXCEPTION(utils::ExceptionCritical,
                       "NutritionGenerator: food intake construction template "
                       "has not been created");

  ScTemplateGenResult foodIntakeConstructionTemplateResult;
  context->HelperGenTemplate(*foodIntakeConstructionTemplate,
                             foodIntakeConstructionTemplateResult);

  ScAddrVector resultConstruction = {
      foodIntakeConstructionTemplateResult[NutritionTemplates::DIET_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::ID_LINK_TYPE_RELATION_PAIR_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::ID_LINK_TYPE_ACCESS_ARC_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::NUTRITION_BREAKFAST_TYPE_RELATION_PAIR_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::PRODUCT_SET_BREAKFAST_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::NUTRITION_BREAKFAST_TYPE_ACCESS_ARC_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::NUTRITION_LUNCH_TYPE_RELATION_PAIR_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::PRODUCT_SET_LUNCH_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::NUTRITION_LUNCH_TYPE_ACCESS_ARC_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::NUTRITION_DINNER_TYPE_RELATION_PAIR_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::PRODUCT_SET_DINNER_ALIAS],
      foodIntakeConstructionTemplateResult
          [NutritionTemplates::NUTRITION_DINNER_TYPE_ACCESS_ARC_ALIAS],
      NutritionKeynodes::nrel_breakfast,
      NutritionKeynodes::nrel_lunch,
      NutritionKeynodes::nrel_dinner,
      NutritionKeynodes::nrel_diet_id,
      id};

  resultConstruction.push_back(context->CreateEdge(
      ScType::EdgeAccessConstPosPerm,
      NutritionKeynodes::concept_eating_from_trainer,
      foodIntakeConstructionTemplateResult[NutritionTemplates::DIET_ALIAS]));

  for (ScAddr productAddr : productsBreakfast)
    resultConstruction.push_back(productAddr);

  for (ScAddr productAddr : productsBreakfast)
    resultConstruction.push_back(context->CreateEdge(
        ScType::EdgeAccessConstPosPerm,
        foodIntakeConstructionTemplateResult
            [NutritionTemplates::PRODUCT_SET_BREAKFAST_ALIAS],
        productAddr));

  for (ScAddr productAddr : productsLunch)
    resultConstruction.push_back(productAddr);

  for (ScAddr productAddr : productsLunch)
    resultConstruction.push_back(
        context->CreateEdge(ScType::EdgeAccessConstPosPerm,
                            foodIntakeConstructionTemplateResult
                                [NutritionTemplates::PRODUCT_SET_LUNCH_ALIAS],
                            productAddr));

  for (ScAddr productAddr : productsDinner)
    resultConstruction.push_back(productAddr);

  for (ScAddr productAddr : productsDinner)
    resultConstruction.push_back(
        context->CreateEdge(ScType::EdgeAccessConstPosPerm,
                            foodIntakeConstructionTemplateResult
                                [NutritionTemplates::PRODUCT_SET_DINNER_ALIAS],
                            productAddr));

  SC_LOG_DEBUG("NutritionGenerator: finish");

  return resultConstruction;
}
