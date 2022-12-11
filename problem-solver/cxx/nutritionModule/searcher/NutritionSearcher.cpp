/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "keynodes/NutritionKeynodes.hpp"

#include "NutritionSearcher.hpp"

using namespace nutritionModule;

NutritionSearcher::NutritionSearcher(ScMemoryContext *context)
    : context(context) {
  this->nutritionTemplates = std::make_unique<NutritionTemplates>();
  this->idLinkSearcher =
      std::make_unique<commonModule::IdLinkSearcher>(context);
}

ScAddrVector NutritionSearcher::searchNutrition(const ScAddr &idLink) {

  SC_LOG_DEBUG("NutritionSearcher: start");

  ScAddr idLinNecessary = idLinkSearcher->searchIdLink(
      context->GetLinkContent(idLink), NutritionKeynodes::concept_nutrition_id);
  if (!idLinNecessary.IsValid()) {
    SC_LOG_WARNING("NutritionSearcher: idLink not found");
    return {};
  }

  std::unique_ptr<ScTemplate> nutritionConstructionTemplate =
      nutritionTemplates->receiveNutritionTemplate(idLinNecessary);

  if (nutritionConstructionTemplate->IsEmpty())
    SC_THROW_EXCEPTION(utils::ExceptionCritical,
                       "NutritionSearcher: nutrition construction template has "
                       "not been created");

  ScTemplateSearchResult productsConstructionTemplateResults;
  context->HelperSearchTemplate(*nutritionConstructionTemplate,
                                productsConstructionTemplateResults);

  if (productsConstructionTemplateResults.IsEmpty()) {
    SC_LOG_DEBUG("NutritionSearcher: nutrition not found");
    return {};
  }

  ScTemplateSearchResultItem productsConstructionTemplateResult =
      productsConstructionTemplateResults[0];

  ScAddrVector resultVector = {
      idLink,
      NutritionKeynodes::nrel_diet_id,
      NutritionKeynodes::nrel_breakfast,
      NutritionKeynodes::nrel_lunch,
      NutritionKeynodes::nrel_dinner,
      productsConstructionTemplateResult[NutritionTemplates::DIET_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::ID_LINK_TYPE_RELATION_PAIR_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::ID_LINK_TYPE_ACCESS_ARC_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::NUTRITION_BREAKFAST_TYPE_RELATION_PAIR_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::PRODUCT_SET_BREAKFAST_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::NUTRITION_BREAKFAST_TYPE_ACCESS_ARC_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::NUTRITION_LUNCH_TYPE_RELATION_PAIR_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::PRODUCT_SET_LUNCH_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::NUTRITION_LUNCH_TYPE_ACCESS_ARC_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::NUTRITION_DINNER_TYPE_RELATION_PAIR_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::PRODUCT_SET_DINNER_ALIAS],
      productsConstructionTemplateResult
          [NutritionTemplates::NUTRITION_DINNER_TYPE_ACCESS_ARC_ALIAS]};

  std::shared_ptr<TIterator3<ScAddr, ScType, ScType>> it_breakfast =
      context->Iterator3(productsConstructionTemplateResult
                             [NutritionTemplates::PRODUCT_SET_BREAKFAST_ALIAS],
                         ScType::EdgeAccessVarPosPerm, ScType::NodeVar);

  while (it_breakfast->Next()) {
    resultVector.push_back(it_breakfast->Get(1));
    resultVector.push_back(it_breakfast->Get(2));
  }

  std::shared_ptr<TIterator3<ScAddr, ScType, ScType>> it_lunch =
      context->Iterator3(productsConstructionTemplateResult
                             [NutritionTemplates::PRODUCT_SET_LUNCH_ALIAS],
                         ScType::EdgeAccessVarPosPerm, ScType::NodeVar);

  while (it_lunch->Next()) {
    resultVector.push_back(it_lunch->Get(1));
    resultVector.push_back(it_lunch->Get(2));
  }

  std::shared_ptr<TIterator3<ScAddr, ScType, ScType>> it_dinner =
      context->Iterator3(productsConstructionTemplateResult
                             [NutritionTemplates::PRODUCT_SET_DINNER_ALIAS],
                         ScType::EdgeAccessVarPosPerm, ScType::NodeVar);

  while (it_dinner->Next()) {
    resultVector.push_back(it_dinner->Get(1));
    resultVector.push_back(it_dinner->Get(2));
  }

  SC_LOG_DEBUG("NutritionSearcher: finish");

  return resultVector;
}
