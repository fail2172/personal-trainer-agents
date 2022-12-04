/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_memory.hpp"

namespace commonModule {
class LinkHandler {
private:
  ScMemoryContext *context;

public:
  explicit LinkHandler(ScMemoryContext *context);

  ScAddr createLink(const std::string &text);

  ScAddr createLink(const std::string &text, ScAddr lang);
};
} // namespace commonModule
