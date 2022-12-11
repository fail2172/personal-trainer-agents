/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

#include "generator/UserDiseasesGenerator.hpp"

#include "manager/AgentManager.hpp"

#include "searcher/UserSearcher.hpp"

namespace userModule {
class UpdateUserManager : public commonModule::AgentManager {
private:
  std::unique_ptr<UserSearcher> userSearcher;
  std::unique_ptr<UserDiseasesGenerator> addUserDiseases;

public:
  explicit UpdateUserManager(ScMemoryContext *context);

  ScAddrVector manage(ScAddrVector const &processParameters) const override;
};
} // namespace userModule
