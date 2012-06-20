#ifndef CLOG_H
#define CLOG_H

#include <iostream>

#ifdef CONFIG_DEBUG
#   define log_debug(format, ...)   Common::CLog::log(Common::CLog::LOG_DEBUG, format, ##__VA_ARGS__) ///< Debug log
#   define log_info(format, ...)    Common::CLog::log(Common::CLog::LOG_INFO, format, ##__VA_ARGS__)  ///< Info log
#   define CONFIG_LOG_BUFFER        10240
#else
#   define log_debug(format, ...)   /* not logged */                         ///< Disabled Debug log
#   define log_info(format, ...)    /* not logged */                         ///< Disabled Info log
#   define CONFIG_LOG_BUFFER        2048
#endif

#define log_notice(format, ...)  Common::CLog::log(Common::CLog::LOG_NOTICE, format, ##__VA_ARGS__) ///< Notice log
#define log_warn(format, ...)    Common::CLog::log(Common::CLog::LOG_WARN, format, ##__VA_ARGS__)   ///< Warning log
#define log_error(format, ...)   Common::CLog::log(Common::CLog::LOG_ERROR, format, ##__VA_ARGS__)  ///< Error log
#define log_crit(format, ...)    Common::CLog::log(Common::CLog::LOG_CRIT, format, ##__VA_ARGS__)   ///< Critical log
#define log_alert(format, ...)   Common::CLog::log(Common::CLog::LOG_ALERT, format, ##__VA_ARGS__)  ///< Alert log
#define log_emerg(format, ...)   Common::CLog::log(Common::CLog::LOG_EMERG, format, ##__VA_ARGS__)  ///< Emergency log

namespace Common
{
    /** @brief Logging class
     */
    class CLog
    {
    public:
        /** @brief Log message level priority
         */
        enum LogLevel
        {
            LOG_NONE   = 0, ///< Won't be logged
            LOG_DEBUG  = 1, ///< Debug level
            LOG_INFO   = 2, ///< Trivial information
            LOG_NOTICE = 3, ///< Normal, but significant, condition
            LOG_WARN   = 4, ///< Warning conditions
            LOG_ERROR  = 5, ///< Error conditions
            LOG_CRIT   = 6, ///< Critical conditions
            LOG_ALERT  = 7, ///< Action must be taken immediately
            LOG_EMERG  = 8  ///< Program is unusable
        };

        /** @brief Log message
         *
         * @param level - Level of message
         * @param format - format of message like printf
         * @param ... - Message or printf format + parameters
         * @return bool - false, if level > 4
         *
         */
        static bool log(LogLevel level, const char* format, ...);

        /** @brief Get or set current displaying log level
         *
         * @param level - Set level of displaying message
         * @return LogLevel - Current displaying log level
         *
         */
        static LogLevel displayLogLevel(LogLevel level = LOG_NONE);

    protected:
        CLog();
        ~CLog();
        static LogLevel      s_displayLevel; ///< Display messages with >= this level
        static unsigned long s_logTime;      ///< Last log time
    };
}

#endif // CLOG_H
