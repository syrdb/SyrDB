#include <iostream>
#include <string>
#include "resources/verinfo.h"
#include "core/logger.h"
#include "types/dictionary.h"

int main() {
    TheStngularity::SyrDB::Logger logger = TheStngularity::SyrDB::Logger(
        TheStngularity::SyrDB::LoggerLevel::DEBUG, "", "none", true);
    
    logger.info("SyrDB v" + std::string(VERSION));
    logger.info("Project URL: " + std::string(URL) + "\n");

    #if IS_DEBUG == 1
    logger.info("test");
    logger.warn("test");
    logger.error("test");
    logger.debug("test");

    TheStngularity::SyrDB::Dictionary dict = TheStngularity::SyrDB::Dictionary();
    //dict.set<std::string>("text", "Hello, World");
    //dict.set<short>("short", 5);
    //dict.set<bool>("bool", true);
    //dict.set<TheStngularity::SyrDB::Dictionary>("dict", dict);
    //dict.get<std::string>("text");
    //logger.info(dict.get<std::string>("text"));
    //logger.info(std::to_string(dict.get<short>("short")));
    //logger.info(dict.get<bool>("bool") ? "true" : "false");
    //std::cout << dict.get<TheStngularity::SyrDB::Dictionary>("dict").asMap().empty() << std::endl;
    #endif

    return 0;
}