/*
 * Copyright (c) 2022 Project Healthy Life Style, All rights reserved.
 * Author: Artsiom Salauyou
 */

#include "sc-agents-common/utils/GenerationUtils.hpp"
#include "sc-builder/src/scs_loader.hpp"
#include "sc-memory/kpm/sc_agent.hpp"
#include "sc-memory/sc_wait.hpp"
#include "sc_test.hpp"

#include "agent/CreateUserAgent.hpp"

#include "keynodes/Keynodes.hpp"
#include "keynodes/UserKeynodes.hpp"

#include "template/UserTemplates.hpp"

namespace testUserRegistrationAgent {
ScsLoader loader;
const std::string TEST_FILES_DIR_PATH =
    USER_CONTROL_MODULE_TEST_SRC_PATH "/TestStructures/userRegistration/";
const int WAIT_TIME = 5000;

using UserRegistrationTest = ScMemoryTest;

void initializedClasses() {
  commonModule::Keynodes::InitGlobal();
  scAgentsCommon::CoreKeynodes::InitGlobal();
  userModule::UserKeynodes::InitGlobal();
}

TEST_F(UserRegistrationTest, Test) {
  ScMemoryContext &context = *m_ctx;

  loader.loadScsFile(context,
                     TEST_FILES_DIR_PATH + "userRegistrationTestStructure.scs");
  ScAddr test_question_node =
      context.HelperFindBySystemIdtf("test_question_node");
  EXPECT_TRUE(test_question_node.IsValid());

  ScAgentInit(true);
  initializedClasses();

  SC_AGENT_REGISTER(userModule::CreateUserAgent)

  context.CreateEdge(ScType::EdgeAccessConstPosPerm,
                     scAgentsCommon::CoreKeynodes::question_initiated,
                     test_question_node);

  EXPECT_TRUE(
      ScWaitEvent<ScEventAddOutputEdge>(
          context, scAgentsCommon::CoreKeynodes::question_finished_successfully)
          .Wait(WAIT_TIME));

  SC_AGENT_UNREGISTER(userModule::CreateUserAgent)
}
} // namespace testUserRegistrationAgent
