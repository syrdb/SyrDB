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

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>

namespace TheStngularity::SyrDB {
    /**
     * @brief Logger level enum
     */
    enum class LoggerLevel : short {
        INFO = 0,
        WARN = 1,
        ERROR = 2,
        DEBUG = 3
    };

    /**
     * @brief Logger class
     */
    class Logger {
        private:
            bool enable;
            LoggerLevel level;
            std::string file;
            std::string fileFormat;

            void print(LoggerLevel lvl, std::string content, const std::string from, const std::string color, const std::string name);

        public:
            Logger();
            Logger(LoggerLevel maxLevel, std::string file, std::string fileFormat, bool enable);

            /**
             * @brief Log information content to console
             * @param content Content of information
             */
            void info(const std::string content);

            /**
             * @brief Log information content to console
             * @param content Content of information
             * @param from Log from ...
             */
            void info(const std::string content, const std::string from);

            /**
             * @brief Log warning content to console
             * @param content Content of warning
             */
            void warn(std::string content);

            /**
             * @brief Log warning content to console
             * @param content Content of warning
             * @param from Log from ...
             */
            void warn(std::string content, std::string from);

            /**
             * @brief Log error content to console
             * @param content Content of error
             */
            void error(std::string content);

            /**
             * @brief Log error content to console
             * @param content Content of error
             * @param from Log from ...
             */
            void error(std::string content, std::string from);

            /**
             * @brief Log debug content to console
             * @param content Content of debug
             */
            void debug(std::string content);

            /**
             * @brief Log debug content to console
             * @param content Content of debug
             * @param from Log from ...
             */
            void debug(std::string content, std::string from);
    };
}

#endif