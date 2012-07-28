/**
 * @file    cexception.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Exception
 *
 */

#include "cexception.h"

using namespace Common;

CException::CException(const QString &description, const QString &source)
    : m_source(source)
    , m_file()
    , m_description(description)
    , m_line(0)
    , m_full_description("Exception: '" + description + "' in " + source)
{
}

CException::CException(const QString &description, const QString &source, const char* file, quint32 line)
    : m_source(source)
    , m_file(file)
    , m_description(description)
    , m_line(line)
    , m_full_description("Exception: '" + description + "' in " + source + " at " + file + " : " + QString::number(line))
{
}

