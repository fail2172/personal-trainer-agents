/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

#include "template/UserTemplates.hpp"

namespace userModule {
class UserGenerator {
private:
  ScMemoryContext *context;

  std::unique_ptr<UserTemplates> userTemplates;

public:
  explicit UserGenerator(ScMemoryContext *context);

  ScAddrVector createUser(const ScAddr &loginLink, const ScAddr &passwordLink);
};
} // namespace userModule
