/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_template.hpp"

namespace userModule {
class DiseaseListTemplates {
public:
  static std::string const USER_ALIAS;
  static std::string const DISEASE_LIST_RELATION_PAIR_ALIAS;
  static std::string const DISEASE_LIST_ALIAS;
  static std::string const DISEASE_LIST_ACCESS_ARC_ALIAS;

  static std::unique_ptr<ScTemplate>
  receiveUserDiseasesTemplate(ScAddr const &userAddr);
};
} // namespace userModule
