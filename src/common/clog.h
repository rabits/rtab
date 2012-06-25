#ifndef CLOG_H
#define CLOG_H

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
