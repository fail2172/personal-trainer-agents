/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

#include "generator/UserGenerator.hpp"

#include "manager/AgentManager.hpp"

#include "searcher/LoginSearcher.hpp"

namespace userModule {
class CreateUserManager : public commonModule::AgentManager {
private:
  std::unique_ptr<UserGenerator> userGenerator;
  std::unique_ptr<LoginSearcher> loginSearcher;

public:
  explicit CreateUserManager(ScMemoryContext *context);

  ScAddrVector manage(ScAddrVector const &processParameters) const override;
};
} // namespace userModule
