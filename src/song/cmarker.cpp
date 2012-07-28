/**
 * @file    cmarker.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Marker
 *
 */

#include "cmarker.h"

const char* CMarker::DEFAULT_TITLE = "Undefined";

CMarker::CMarker(QObject *parent)
    : QObject(parent)
    , m_measure(0)
    , m_title(DEFAULT_TITLE)
    , m_color(DEFAULT_COLOR)
{
}

CMarker::CMarker(const CMarker &obj)
    : QObject()
    , m_measure(obj.measure())
    , m_title(obj.title())
    , m_color(obj.color())
{
}

CMarker &CMarker::operator =(const CMarker &obj)
{
    measure(obj.measure());
    title(obj.title());
    color(obj.color());

    return *this;
}
