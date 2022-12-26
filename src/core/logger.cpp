/*
    This file is part of SyrDB.

    SyrDB is free software: you can redistribute it and/or modify it under the terms
    of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version.

    SyrDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License along with SyrDB.
    If not, see <https://www.gnu.org/licenses/>.    
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <regex>
#include <filesystem>
#include "../utils/string.h"
#include "logger.h"

namespace SyrDB {
    const std::string getTime(const char* format) {
        std::time_t raw = std::time(0);
        std::tm ltime = *std::localtime(&raw);

        char buffer[80];
        strftime(buffer, sizeof(buffer), format, &ltime);
        return buffer;
    }

    void Logger::print(
        LoggerLevel level,
        std::string content,
        const std::string from,
        const std::string color,
        const std::string name
    ) {
        std::string* time = new std::string(getTime("%d.%m.%Y %H:%M:%S"));
        if(this->consoleEnable && this->consoleLevel >= level) {  // Write to console
            std::string* spaces = new std::string(from.length()/2, ' ');
            std::string* fromText = new std::string("[" + *spaces + from + *spaces + "]");
            std::string* out = new std::string("\x1B[32m[" + *time + "] " + *fromText
                                               + " \x1B[" + color + "m" + name + ": " + (name.length() == 4 ? " " : "")
                                               + "\x1B[0m" + content);
            std::cout << *out << std::endl;
            delete fromText; delete spaces; delete out;
        }

        if(this->fileEnable && this->fileLevel >= level) {  // Write to file
            if(!std::filesystem::exists(this->folder))
                std::filesystem::create_directory(this->folder);

            std::ofstream writer(this->folder + "/" + this->getFilename(), std::ofstream::app);
            writer << "[" + *time + "] [" + from + "] [" + name + "] " + content << "\n";
            writer.close();
        }

        delete time;
    }

    std::string Logger::getFilename() {
        std::string output = this->filename;
        const std::regex regex(R"(^\[[a-zA-Z.]+\])");
        std::smatch match;
        if(std::regex_search(this->filename, match, regex)) {
            std::vector<std::string> splited = SyrDB::Utils::split(this->filename, '.');
            std::string placeholder = std::string(match[0]).substr(1, match[0].length()-2);
            output = SyrDB::Utils::replace(
                output,
                match[0],
                getTime(SyrDB::Utils::replace(  // e.g. dd.mm.yyyy -> 22.02.2022
                    SyrDB::Utils::replace(
                        SyrDB::Utils::replace(
                            SyrDB::Utils::replace(
                                SyrDB::Utils::replace(
                                    SyrDB::Utils::replace(
                                        SyrDB::Utils::replace(placeholder, "yyyy", "%Y"),
                                        "yy", "%y"
                                    ), "mm", "%m"
                                ), "dd", "%d"
                            ), "HH", "%H"
                        ), "MM", "%M"
                    ), "SS", "%S").c_str()  // Woo-hoo, ladder
                )
            );
        }

        return output;
    }

    Logger::Logger() : consoleLevel(LoggerLevel::ERROR),
                       fileLevel(LoggerLevel::ERROR),
                       folder("logs"),
                       filename("[DD.MM.YYYY].log"),
                       consoleEnable(true),
                       fileEnable(false) {}

    Logger::Logger(
        LoggerLevel consoleLevel,
        LoggerLevel fileLevel,
        std::string folder,
        std::string filename,
        bool consoleEnable,
        bool fileEnable
    ) : consoleLevel(consoleLevel),
        fileLevel(fileLevel),
        folder(folder),
        filename(filename),
        consoleEnable(consoleEnable),
        fileEnable(fileEnable) {}

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