#ifndef COMMON_H
#define COMMON_H

#ifdef CONFIG_DEBUG
#   define log_debug(format, ...)   Common::CLog::log("DEBUG ", format, ##__VA_ARGS__)   ///< Debug log
#   define log_info(format, ...)    Common::CLog::log("INFO  ", format, ##__VA_ARGS__)   ///< Info log
#   define EXCEPTION(message)       Common::CException(message, __FUNCTION__, __FILE__, __LINE__) ///< Hard exception
#else
#   define log_debug(format, ...)   /* not logged */                                     ///< Disabled Debug log
#   define log_info(format, ...)    /* not logged */                                     ///< Disabled Info log
#   define EXCEPTION(message)       Common::CException(message, __FUNCTION__)                     ///< Simple exception
#endif

#define log_notice(format, ...)     Common::CLog::log("NOTICE", format, ##__VA_ARGS__)   ///< Notice log
#define log_warn(format, ...)       Common::CLog::log("WARNING", format, ##__VA_ARGS__)  ///< Warning log
#define log_error(format, ...)      Common::CLog::log("ERROR", format, ##__VA_ARGS__)    ///< Error log
#define log_crit(format, ...)       Common::CLog::log("CRITICAL", format, ##__VA_ARGS__) ///< Critical log
#define log_alert(format, ...)      Common::CLog::log("ALERT", format, ##__VA_ARGS__)    ///< Alert log
#define log_emerg(format, ...)      Common::CLog::log("EMERG", format, ##__VA_ARGS__)    ///< Emergency log

#include "clog.h"
#include "cexception.h"

#endif // COMMON_H
