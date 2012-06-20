#include "clog.h"

using namespace Common;

#include <cstdio>
#include <cstdarg>
#include <cstring>

CLog::LogLevel CLog::s_displayLevel = CLog::LOG_NONE;
unsigned long CLog::s_logTime = 0;

bool CLog::log(CLog::LogLevel level, const char* format, ...)
{
    if( level < s_displayLevel )
        return level < 5;

    char msgbuffer[CONFIG_LOG_BUFFER];
    char msglevel[] = "       ";
    std::va_list ap;

    // Select output
    FILE* output;
    if( level < CLog::LOG_WARN )
        output = stdout;
    else
        output = stderr;

    va_start(ap, format);
    vsnprintf(msgbuffer, CONFIG_LOG_BUFFER, format, ap);
    va_end(ap);

    // Message level
    switch( level ) {
        case 1:
            std::strcpy(msglevel, "DEBUG");
            break;
        case 2:
            std::strcpy(msglevel, "INFO");
            break;
        case 3:
            std::strcpy(msglevel, "NOTICE");
            break;
        case 4:
            std::strcpy(msglevel, "WARN");
            break;
        case 5:
            std::strcpy(msglevel, "ERROR");
            break;
        case 6:
            std::strcpy(msglevel, "CRIT");
            break;
        case 7:
            std::strcpy(msglevel, "ALERT");
            break;
        case 8:
            std::strcpy(msglevel, "FATAL");
            break;
        case 0:
            return true;
    }

    std::fprintf(output, "[rTab] %6s: %s\n", msglevel, msgbuffer);

    return level < CLog::LOG_ERROR;
}

CLog::LogLevel CLog::displayLogLevel(CLog::LogLevel level)
{
    if( level != CLog::LOG_NONE )
        s_displayLevel = level;

    return s_displayLevel;
}
