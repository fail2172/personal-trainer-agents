/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_memory.hpp"

namespace commonModule {
class ArgumentExtractor {
private:
  ScMemoryContext *context;

public:
  explicit ArgumentExtractor(ScMemoryContext *context);

  ScAddr extractParameter(ScAddr const &actionAddr);

  ScAddr extractParameter(ScAddr const &actionAddr, ScAddr const &relation);
};
} // namespace commonModule
