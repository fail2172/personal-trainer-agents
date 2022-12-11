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

  SC_PROPERTY(Keynode("action_update_user"), ForceCreate)
  static ScAddr action_update_user;

  SC_PROPERTY(Keynode("concept_user"), ForceCreate)
  static ScAddr concept_user;

  SC_PROPERTY(Keynode("nrel_login"), ForceCreate)
  static ScAddr nrel_login;

  SC_PROPERTY(Keynode("nrel_password"), ForceCreate)
  static ScAddr nrel_password;

  SC_PROPERTY(Keynode("concept_registered_login"), ForceCreate)
  static ScAddr concept_registered_login;

  SC_PROPERTY(Keynode("nrel_diseases_param"), ForceCreate)
  static ScAddr nrel_diseases_param;

  SC_PROPERTY(Keynode("nrel_user_params"), ForceCreate)
  static ScAddr nrel_user_params;

  SC_PROPERTY(Keynode("concept_diastasis"), ForceCreate)
  static ScAddr concept_diastasis;

  SC_PROPERTY(Keynode("concept_scoliosis"), ForceCreate)
  static ScAddr concept_scoliosis;

  SC_PROPERTY(Keynode("concept_herniated_disc"), ForceCreate)
  static ScAddr concept_herniated_disc;

  SC_PROPERTY(Keynode("concept_meniscus_injury"), ForceCreate)
  static ScAddr concept_meniscus_injury;

  SC_PROPERTY(Keynode("concept_varicose_veins"), ForceCreate)
  static ScAddr concept_varicose_veins;

  SC_PROPERTY(Keynode("nrel_disease_list"), ForceCreate)
  static ScAddr nrel_disease_list;

  SC_PROPERTY(Keynode("concept_user_id"), ForceCreate)
  static ScAddr concept_user_id;
};
} // namespace userModule
