/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#pragma once

#include "sc-agents-common/keynodes/coreKeynodes.hpp"
#include "sc-memory/kpm/sc_agent.hpp"

#include "extractor/ArgumentExtractor.hpp"

#include "searcher/NutritionSearcher.hpp"

#include "SearchNutritionAgent.generated.hpp"

namespace nutritionModule {
class SearchNutritionAgent : public ScAgent {
  SC_CLASS(Agent, Event(scAgentsCommon::CoreKeynodes::question_initiated,
                        ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()

private:
  std::unique_ptr<commonModule::ArgumentExtractor> argumentExtractor;
  std::unique_ptr<NutritionSearcher> nutritionSearcher;

private:
  bool checkActionClass(ScAddr const &actionNode);

  void initFields();
};
} // namespace nutritionModule
