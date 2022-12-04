/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "keynodes/UserKeynodes.hpp"

#include "LoginSearcher.hpp"

using namespace userModule;

LoginSearcher::LoginSearcher(ScMemoryContext *context) : context(context) {}

ScAddr LoginSearcher::searchLogin(const ScStreamPtr &loginLinkValue) {
  ScAddrVector links = context->FindLinksByContent(loginLinkValue);

  for (ScAddr link : links) {
    if (context->HelperCheckEdge(UserKeynodes::concept_registered_login, link,
                                 ScType::EdgeAccessConstPosPerm))
      return link;
  }

  SC_LOG_WARNING("LoginSearcher: No such login");

  return {};
}
