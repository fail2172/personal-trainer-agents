/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_object.hpp"

#include "Keynodes.generated.hpp"

namespace commonModule {
class Keynodes : public ScObject {
  SC_CLASS()
  SC_GENERATED_BODY()

public:
  SC_PROPERTY(Keynode("concept_processed_entity"), ForceCreate)
  static ScAddr concept_processed_entity;

  SC_PROPERTY(Keynode("concept_processed_entity"), ForceCreate)
  static ScAddr action_deactivated;

  SC_PROPERTY(Keynode("nrel_id"), ForceCreate)
  static ScAddr nrel_id;
};
} // namespace commonModule
