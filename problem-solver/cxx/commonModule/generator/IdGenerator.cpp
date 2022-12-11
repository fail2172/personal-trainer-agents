/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "IdGenerator.hpp"
#include "handler/LinkHandler.hpp"
#include "sc-agents-common/utils/CommonUtils.hpp"

using namespace commonModule;

IdGenerator::IdGenerator(ScMemoryContext *context) : context(context) {
  this->linkHandler = std::make_unique<LinkHandler>(context);
}

ScAddr IdGenerator::createId(ScAddr const &idType) {

  SC_LOG_DEBUG("IdGenerator: start");

  int id = rand() % 10000 + 1;
  cout << id;

  ScAddr idGenerated = linkHandler->createLink(to_string(id));

  context->CreateEdge(ScType::EdgeAccessConstPosPerm, idType, idGenerated);

  SC_LOG_DEBUG("IdGenerator: finish");

  return idGenerated;
}
