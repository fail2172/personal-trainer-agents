/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "IdLinkSearcher.hpp"

using namespace commonModule;

IdLinkSearcher::IdLinkSearcher(ScMemoryContext *context) : context(context) {}

ScAddr IdLinkSearcher::searchIdLink(const ScStreamPtr &loginLinkValue,
                                    const ScAddr &idType) {

  SC_LOG_DEBUG("IdLinkSearcher: start");

  ScAddrVector links = context->FindLinksByContent(loginLinkValue);

  for (ScAddr link : links) {
    if (context->HelperCheckEdge(idType, link, ScType::EdgeAccessConstPosPerm))
      SC_LOG_DEBUG("NutritionIdGenerator: finish");
    return link;
  }

  SC_LOG_WARNING("IdLinkSearcher: No such idLink");
  SC_LOG_DEBUG("NutritionIdGenerator: finish");

  return {};
}
