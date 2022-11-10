#include <iostream>
#include "core/logger.h"
#include <string>
#include "resources/verinfo.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;
    TheStngularity::SyrDB::Logger logger = TheStngularity::SyrDB::Logger(
        TheStngularity::SyrDB::LoggerLevel::DEBUG, "", "none", true);
    logger.info("Welcome to SyrDB v"+std::string(VERSION));
#if DEBUG
    logger.warn("test");
    logger.error("test");
    logger.debug("test");
#endif
    return 0;
}