/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

#include "template/UserTemplates.hpp"

namespace userModule {
class UserDiseasesGenerator {
private:
  ScMemoryContext *context;

public:
  explicit UserDiseasesGenerator(ScMemoryContext *context);

  ScAddrVector addDiseasesToUser(ScAddr const &userAddr,
                                 ScAddrVector const &diseases);
};
} // namespace userModule
