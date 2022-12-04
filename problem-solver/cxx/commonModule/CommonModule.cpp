/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "CommonModule.hpp"

using namespace commonModule;

SC_IMPLEMENT_MODULE(CommonModule)

sc_result CommonModule::InitializeImpl() {

  ScMemoryContext ctx(sc_access_lvl_make_min, "commonModule");

  return SC_RESULT_OK;
}

sc_result CommonModule::ShutdownImpl() { return SC_RESULT_OK; }
