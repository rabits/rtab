/**
 * @file    pstyle.cpp
 * @date    2012-07-01T02:18:31+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Style basic
 *
 */

#include "pstyle.h"

PStyle::PStyle(QObject *parent)
    : QObject(parent)
    , m_inverted(false)
    , m_size(1)
    , m_lineWidth(1)
    , m_smooth(true)
    , m_leftPadding(16)
    , m_rightPadding(16)
    , m_topPadding(16)
    , m_bottomPadding(16)
    , m_foregroundColor(Qt::black)
    , m_backgroundColor(Qt::gray)
    , m_borderColor(Qt::black)
    , m_selectedForegroundColor(Qt::white)
    , m_selectedBackgroundColor(Qt::gray)
    , m_selectedBorderColor(Qt::white)
{
}

PStyle::PStyle(const PStyle &obj)
    : QObject()
    , m_inverted(obj.inverted())
    , m_size(obj.size())
    , m_lineWidth(obj.lineWidth())
    , m_smooth(obj.smooth())
    , m_leftPadding(obj.leftPadding())
    , m_rightPadding(obj.rightPadding())
    , m_topPadding(obj.topPadding())
    , m_bottomPadding(obj.bottomPadding())
    , m_foregroundColor(obj.foregroundColor())
    , m_backgroundColor(obj.backgroundColor())
    , m_borderColor(obj.borderColor())
    , m_selectedForegroundColor(obj.selectedForegroundColor())
    , m_selectedBackgroundColor(obj.selectedBackgroundColor())
    , m_selectedBorderColor(obj.selectedBorderColor())
{
}

PStyle &PStyle::operator =(const PStyle &obj)
{
    inverted(obj.inverted());
    size(obj.size());
    lineWidth(obj.lineWidth());
    smooth(obj.smooth());
    leftPadding(obj.leftPadding());
    rightPadding(obj.rightPadding());
    topPadding(obj.topPadding());
    bottomPadding(obj.bottomPadding());
    foregroundColor(obj.foregroundColor());
    backgroundColor(obj.backgroundColor());
    borderColor(obj.borderColor());
    selectedForegroundColor(obj.selectedForegroundColor());
    selectedBackgroundColor(obj.selectedBackgroundColor());
    selectedBorderColor(obj.selectedBorderColor());

    return *this;
}
