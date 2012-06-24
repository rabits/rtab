#ifndef CLOG_H
#define CLOG_H

#ifdef CONFIG_DEBUG
#   define log_debug(format, ...)   Common::CLog::log("DEBUG ", format, ##__VA_ARGS__)   ///< Debug log
#   define log_info(format, ...)    Common::CLog::log("INFO  ", format, ##__VA_ARGS__)   ///< Info log
#else
#   define log_debug(format, ...)   /* not logged */                                     ///< Disabled Debug log
#   define log_info(format, ...)    /* not logged */                                     ///< Disabled Info log
#endif

#define log_notice(format, ...)     Common::CLog::log("NOTICE", format, ##__VA_ARGS__)   ///< Notice log
#define log_warn(format, ...)       Common::CLog::log("WARNING", format, ##__VA_ARGS__)  ///< Warning log
#define log_error(format, ...)      Common::CLog::log("ERROR", format, ##__VA_ARGS__)    ///< Error log
#define log_crit(format, ...)       Common::CLog::log("CRITICAL", format, ##__VA_ARGS__) ///< Critical log
#define log_alert(format, ...)      Common::CLog::log("ALERT", format, ##__VA_ARGS__)    ///< Alert log
#define log_emerg(format, ...)      Common::CLog::log("EMERG", format, ##__VA_ARGS__)    ///< Emergency log

#include <QList>

namespace Common
{
    /** @brief Logging class
     */
    class CLog
    {
    public:
        static const char* log(const char *level, const char *format, QString &arg1);
        static const char* log(const char *level, const char *format, QString &arg1, QString arg2);
        static const char* log(const char *level, const char *format, QString &arg1, QString &arg2, QString &arg3);
        static const char* log(const char *level, const char *format, ...);

    protected:
        CLog();
        ~CLog();
        static QList<QByteArray> s_msg_stack;
    };
}

#endif // CLOG_H
