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
    , m_leftPadding(16)
    , m_rightPadding(16)
    , m_topPadding(16)
    , m_bottomPadding(16)
    , m_foregroundColor(Qt::black)
    , m_backgroundColor(Qt::white)
    , m_selectedForegroundColor(Qt::white)
    , m_selectedBackgroundColor(Qt::black)
{
}

PStyle::PStyle(const PStyle &obj)
{
    // TODO:
}

PStyle &PStyle::operator =(const PStyle &obj)
{
    // TODO:
}
