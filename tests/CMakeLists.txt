# Checking the launchability
add_test(NAME LaunchabilityTest
         COMMAND ${PROJECT_NAME}
         WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})