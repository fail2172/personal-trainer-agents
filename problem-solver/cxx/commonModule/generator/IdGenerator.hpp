/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#pragma once

#include "handler/LinkHandler.hpp"
#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_memory.hpp>
namespace commonModule {
class IdGenerator {
private:
  ScMemoryContext *context;
  std::unique_ptr<LinkHandler> linkHandler;

public:
  explicit IdGenerator(ScMemoryContext *context);

  ScAddr createId(ScAddr const &idType);
};

} // namespace commonModule