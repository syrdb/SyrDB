/*
    SyrDB/Logger - Logger lib
    [logger.cpp] - Main file
    Made with ❤ for you
    Distributed under the BSL license (see LICENSE file)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <ctime>
#include "../utils/stringutils.h"
#include "logger.h"

namespace TheStngularity::SyrDB {
    const std::string getTime(const char* format) {
        std::time_t raw = std::time(0);
        std::tm ltime = *std::localtime(&raw);

        char buffer[80];
        strftime(buffer, sizeof(buffer), format, &ltime);
        return buffer;
    }

    void Logger::print(
        LoggerLevel lvl,
        std::string content,
        const std::string from,
        const std::string color,
        const std::string name
    ) {
        if(this->enable && this->level >= lvl) {
            std::string* spaces = new std::string("");
            for(short i = 0; i < from.length() / 2 && i < 16; i++) *spaces += " ";
            
            std::string* fromText = new std::string("[" + *spaces + from + *spaces + "]");
            std::string* time = new std::string(getTime("%d.%m.%Y %H:%M:%S"));
            std::string* out = new std::string("\x1B[32m[" + *time + "] " + *fromText
                                               + " \x1B[" + color + "m" + name + ": " + (name.length() == 4 ? " " : "")
                                               + "\x1B[0m" + content);
            std::cout << *out << std::endl;
            delete fromText; delete spaces; delete out;

            // Write to file
            if(this->fileFormat != "none") {
                std::ofstream writer (this->file, std::ofstream::app);
                writer << "[" + *time + "] [" + from + "] [" + name + "] " + content << "\n";
                writer.close();
            }

            delete time;
        }
    }

    Logger::Logger() {
        this->file = "";
        this->fileFormat = "none";
        this->enable = true;
        this->level = LoggerLevel::DEBUG;
    }

    Logger::Logger(LoggerLevel maxLevel, std::string file, std::string fileFormat, bool enable) {
        this->level = maxLevel;
        this->file = std::move(file);
        this->fileFormat = std::move(fileFormat);
        this->enable = enable;
    }

    // Log information content to console
    void Logger::info(const std::string content) {
        this->info(content, "Core");
    }

    void Logger::info(const std::string content, const std::string from) {
        this->print(LoggerLevel::INFO, content, from, "36", "INFO");
    }

    // Log warning cotent to console
    void Logger::warn(const std::string content) {
        this->warn(content, "Core");
    }

    void Logger::warn(const std::string content, const std::string from) {
        this->print(LoggerLevel::WARN, content, from, "33", "WARN");
    }

    // Log error cotent to console
    void Logger::error(const std::string content) {
        this->error(content, "Core");
    }

    void Logger::error(const std::string content, const std::string from) {
        this->print(LoggerLevel::ERROR, content, from, "31", "ERROR");
    }

    // Log debug cotent to console
    void Logger::debug(const std::string content) {
        this->debug(content, "Core");
    }

    void Logger::debug(const std::string content, const std::string from) {
        this->print(LoggerLevel::DEBUG, content, from, "30;1", "DEBUG");
    }
}