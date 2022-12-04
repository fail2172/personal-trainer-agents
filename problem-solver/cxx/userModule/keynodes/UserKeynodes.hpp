/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_object.hpp"

#include "UserKeynodes.generated.hpp"

namespace userModule {
class UserKeynodes : public ScObject {
  SC_CLASS()
  SC_GENERATED_BODY()

public:
  SC_PROPERTY(Keynode("action_create_user"), ForceCreate)
  static ScAddr action_create_user;

  SC_PROPERTY(Keynode("action_search_user"), ForceCreate)
  static ScAddr action_search_user;

  SC_PROPERTY(Keynode("concept_user"), ForceCreate)
  static ScAddr concept_user;

  SC_PROPERTY(Keynode("nrel_login"), ForceCreate)
  static ScAddr nrel_login;

  SC_PROPERTY(Keynode("nrel_password"), ForceCreate)
  static ScAddr nrel_password;

  SC_PROPERTY(Keynode("concept_registered_login"), ForceCreate)
  static ScAddr concept_registered_login;
};
} // namespace userModule
