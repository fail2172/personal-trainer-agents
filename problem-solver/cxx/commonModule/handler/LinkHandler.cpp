/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "LinkHandler.hpp"

using namespace commonModule;

LinkHandler::LinkHandler(ScMemoryContext *context) : context(context) {}

ScAddr LinkHandler::createLink(const std::string &text) {
  ScAddr addr = context->CreateLink();
  context->SetLinkContent(addr, ScStreamConverter::StreamFromString(text));
  return addr;
}

ScAddr LinkHandler::createLink(const std::string &text, ScAddr lang) {
  ScAddr addr = createLink(text);
  context->CreateEdge(ScType::EdgeAccessConstPosPerm, addr, lang);
  return addr;
}
