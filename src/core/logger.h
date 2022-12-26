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

namespace SyrDB {
    /**
     * @brief Logger level enumeration
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
            LoggerLevel consoleLevel;
            LoggerLevel fileLevel;
            std::string folder;
            std::string filename;
            bool consoleEnable;
            bool fileEnable;

            void print(
                LoggerLevel level,
                std::string content,
                const std::string from,
                const std::string color,
                const std::string name
            );

            std::string getFilename();

        public:
            Logger();
            Logger(
                LoggerLevel consoleLevel,
                LoggerLevel fileLevel,
                std::string folder,
                std::string filename,
                bool consoleEnable,
                bool fileEnable
            );

            /**
             * @brief Print information content to console
             * @param content Content of information
             */
            void info(const std::string content);

            /**
             * @brief Print information content to console
             * @param content Content of information
             * @param from Log from ... component
             */
            void info(const std::string content, const std::string from);

            /**
             * @brief Print warning content to console
             * @param content Content of warning
             */
            void warn(std::string content);

            /**
             * @brief Print warning content to console
             * @param content Content of warning
             * @param from Log from ... component
             */
            void warn(std::string content, std::string from);

            /**
             * @brief Print error content to console
             * @param content Content of error
             */
            void error(std::string content);

            /**
             * @brief Print error content to console
             * @param content Content of error
             * @param from Log from ... component
             */
            void error(std::string content, std::string from);

            /**
             * @brief Print debug content to console
             * @param content Content of debug
             */
            void debug(std::string content);

            /**
             * @brief Print debug content to console
             * @param content Content of debug
             * @param from Log from ... component
             */
            void debug(std::string content, std::string from);
    };
}

#endif