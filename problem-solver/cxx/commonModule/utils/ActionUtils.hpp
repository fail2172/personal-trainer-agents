/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_memory.hpp"

using namespace std;

class ActionUtils {
public:
  static bool initAgentAndWaitForActionSuccessfulFinish(
      ScMemoryContext *context, ScAddr const &actionAddr, int const &waitTime);

  static bool isActionDeactivated(ScMemoryContext *context,
                                  ScAddr const &actionAddr);
};
