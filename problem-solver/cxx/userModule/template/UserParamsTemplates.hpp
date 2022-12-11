/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_template.hpp"

namespace userModule {
class UserParamsTemplates {
public:
  static std::string const USER_PARAMS_ACCESS_ARC_ALIAS;
  static std::string const USER_PARAMS_SET_ALIAS;
  static std::string const DISEASES_PARAM_RELATION_PAIR_ALIAS;
  static std::string const DISEASES_PARAM_ACCESS_ARC_ALIAS;
  static std::string const DISEASES_SET_ALIAS;

  static std::unique_ptr<ScTemplate>
  receiveDiseasesParamTemplate(ScAddr const &userParamsSet);
};
} // namespace userModule
