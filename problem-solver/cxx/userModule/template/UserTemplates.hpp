/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_template.hpp"

namespace userModule {
class UserTemplates {
public:
  static std::string const USER_ACCESS_ARC_ALIAS;
  static std::string const USER_ALIAS;
  static std::string const LOGIN_ALIAS;
  static std::string const PASSWORD_ALIAS;
  static std::string const LOGIN_RELATION_PAIR_ALIAS;
  static std::string const LOGIN_ACCESS_ARC_ALIAS;
  static std::string const PASSWORD_RELATION_PAIR_ALIAS;
  static std::string const PASSWORD_ACCESS_ARC_ALIAS;

  static std::unique_ptr<ScTemplate>
  receiveUserTemplate(ScAddr const &loginLink, ScAddr const &passwordLink);

  static std::unique_ptr<ScTemplate>
  receiveUserTemplate(ScAddr const &loginLink);
};
} // namespace userModule
