#include <iostream>
#include "core/logger.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    TheStngularity::SyrDB::Logger logger = TheStngularity::SyrDB::Logger(
        TheStngularity::SyrDB::LoggerLevel::DEBUG, "", "none", true);
    logger.info("test");
    logger.warn("test");
    logger.error("test");
    logger.debug("test");
    return 0;
}