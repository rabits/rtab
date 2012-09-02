/**
 * @file    pbasic.cpp
 * @date    2012-07-01T02:18:31+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Basic paint object
 *
 */

#include "pbasic.h"

PBasic::PBasic(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , m_x(0)
    , m_y(0)
    , m_style(PStyle::defaultStyle())
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

PBasic::PBasic(PStyle &style, QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , m_x(0)
    , m_y(0)
    , m_style(style)
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

PBasic::PBasic(const PBasic &obj)
    : QDeclarativeItem()
    , m_x(obj.x())
    , m_y(obj.y())
    , m_style(obj.style())
{
}

PBasic &PBasic::operator =(const PBasic &obj)
{
    x(obj.x());
    y(obj.y());
    style(obj.style());

    return *this;
}
