/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Nikita Semchenkov Andreevich
 */

#include "handler/LinkHandler.hpp"

#include "IdGenerator.hpp"

using namespace commonModule;

IdGenerator::IdGenerator(ScMemoryContext *context) : context(context) {
  this->linkHandler = std::make_unique<LinkHandler>(context);
}

ScAddr IdGenerator::createId(ScAddr const &idClass) {

  SC_LOG_DEBUG("IdGenerator: start");

  int id = rand() % 10000 + 1;
  ScAddr idGenerated = linkHandler->createLink(std::to_string(id));

  context->CreateEdge(ScType::EdgeAccessConstPosPerm, idClass, idGenerated);

  SC_LOG_DEBUG("IdGenerator: finish");

  return idGenerated;
}
