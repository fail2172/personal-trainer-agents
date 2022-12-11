/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>

namespace commonModule {

class IdLinkSearcher {
private:
  ScMemoryContext *context;

public:
  explicit IdLinkSearcher(ScMemoryContext *context);

  ScAddr searchIdLink(const ScStreamPtr &loginLinkValue, ScAddr const &idType);
};

} // namespace commonModule
