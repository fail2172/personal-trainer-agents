/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_memory.hpp"

namespace commonModule {
/*! The AgentManager contains a basic description of the manager,
 * namely, it contains the context and function for calling it.
 * The other managers should inherit from it and override the manage function.
 */
class AgentManager {
public:
  explicit AgentManager(ScMemoryContext *context) : context(context) {}

  virtual ~AgentManager() = default;

  /*! Function for implementing agent logic.
   * @param processParameters The vector of the agent's input parameters.
   * @returns The vector of generated entities.
   */
  virtual ScAddrVector manage(ScAddrVector const &processParameters) const = 0;

  ScMemoryContext *context;
};
} // namespace commonModule
