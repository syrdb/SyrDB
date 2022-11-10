/*
    SyrDB/Logger - Logger lib
    [logger.h] - Main file (Annotation)
    Made with ❤ for you
    Distributed under the BSL license (see LICENSE file)
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