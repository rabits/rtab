/**
 * @file    clog.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Log system
 *
 */

#include "clog.h"

using namespace Common;

#include <iostream>
#include <QString>

QList<QByteArray> CLog::s_msg_stack = QList<QByteArray>();

const char *CLog::log(const char *level, const char *format, const QString &arg1)
{
    if( s_msg_stack.count() > 9 )
        s_msg_stack.removeFirst();

    QByteArray msg = QString("[rTab] %1: %2").arg(level).arg(format).arg(arg1).toUtf8();

    std::cerr << msg.constData() << "\n";
    s_msg_stack.append(msg);

    return s_msg_stack.last().constData();
}

const char *CLog::log(const char *level, const char *format, const QString &arg1, const QString arg2)
{
    if( s_msg_stack.count() > 9 )
        s_msg_stack.removeFirst();

    QByteArray msg = QString("[rTab] %1: %2").arg(level).arg(format).arg(arg1).arg(arg2).toUtf8();

    std::cerr << msg.constData() << "\n";
    s_msg_stack.append(msg);

    return s_msg_stack.last().constData();
}

const char *CLog::log(const char *level, const char *format, const QString &arg1, const QString &arg2, const QString &arg3)
{
    if( s_msg_stack.count() > 9 )
        s_msg_stack.removeFirst();

    QByteArray msg = QString("[rTab] %1: %2").arg(level).arg(format).arg(arg1).arg(arg2).arg(arg3).toUtf8();

    std::cerr << msg.constData() << "\n";
    s_msg_stack.append(msg);

    return s_msg_stack.last().constData();
}

const char* CLog::log(const char *level, const char *format, ...)
{
    if( s_msg_stack.count() > 9 )
        s_msg_stack.removeFirst();

    va_list ap;

    va_start(ap, format);
    QByteArray msg = QString("[rTab] %1: %2").arg(level).arg(QString().vsprintf(format, ap)).toUtf8();
    va_end(ap);

    std::cerr << msg.constData() << "\n";
    s_msg_stack.append(msg);

    return s_msg_stack.last().constData();
}
