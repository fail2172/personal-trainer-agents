/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

#include "searcher/LoginSearcher.hpp"

#include "template/UserTemplates.hpp"

namespace userModule {
class UserSearcher {
private:
  ScMemoryContext *context;

  std::unique_ptr<UserTemplates> userTemplates;
  std::unique_ptr<LoginSearcher> loginSearcher;

public:
  explicit UserSearcher(ScMemoryContext *context);

  ScAddrVector searchUserByLogin(const ScAddr &loginLink);
};
} // namespace userModule
