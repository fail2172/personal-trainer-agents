/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "sc-agents-common/utils/IteratorUtils.hpp"

#include "ArgumentExtractor.hpp"

using namespace commonModule;

ArgumentExtractor::ArgumentExtractor(ScMemoryContext *context)
    : context(context) {}

ScAddr ArgumentExtractor::extractParameter(const ScAddr &actionAddr,
                                           const ScAddr &relation) {
  return utils::IteratorUtils::getAnyByOutRelation(context, actionAddr,
                                                   relation);
}

ScAddr ArgumentExtractor::extractParameter(const ScAddr &actionAddr) {
  return utils::IteratorUtils::getFirstFromSet(context, actionAddr, true);
}
