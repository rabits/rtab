/**
 * @file    clog.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Logger
 *
 */

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
        static const char* log(const char *level, const char *format, const QString &arg1);
        static const char* log(const char *level, const char *format, const QString &arg1, const QString arg2);
        static const char* log(const char *level, const char *format, const QString &arg1, const QString &arg2, const QString &arg3);
        static const char* log(const char *level, const char *format, ...);

    protected:
        CLog();
        ~CLog();
        static QList<QByteArray> s_msg_stack;
    };
}

#endif // CLOG_H
