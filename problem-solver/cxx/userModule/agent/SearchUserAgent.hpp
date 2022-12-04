/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-agents-common/keynodes/coreKeynodes.hpp"
#include "sc-memory/kpm/sc_agent.hpp"

#include "extractor/ArgumentExtractor.hpp"

#include "searcher/UserSearcher.hpp"

#include "SearchUserAgent.generated.hpp"

namespace userModule {
class SearchUserAgent : public ScAgent {
  SC_CLASS(Agent, Event(scAgentsCommon::CoreKeynodes::question_initiated,
                        ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()

private:
  std::unique_ptr<commonModule::ArgumentExtractor> argumentExtractor;
  std::unique_ptr<UserSearcher> userSearcher;

private:
  bool checkActionClass(ScAddr const &actionNode);

  void initFields();
};
} // namespace userModule
