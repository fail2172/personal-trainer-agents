/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

namespace userModule {
class LoginSearcher {
private:
  ScMemoryContext *context;

public:
  explicit LoginSearcher(ScMemoryContext *context);

  ScAddr searchLogin(const ScStreamPtr &loginLinkValue);
};
} // namespace userModule
