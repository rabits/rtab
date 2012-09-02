/**
 * @file    pbasic.h
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

#ifndef PBASIC_H
#define PBASIC_H

#include <QDeclarativeItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

#include "style/pstyle.h"

class PBasic
    : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(qint16 x         READ x WRITE x NOTIFY xChanged)
    Q_PROPERTY(qint16 y         READ y WRITE y NOTIFY yChanged)
    Q_PROPERTY(PStyle style     READ style WRITE style NOTIFY styleChanged)

public:
    explicit PBasic(QDeclarativeItem *parent = 0);
    PBasic(PStyle &style, QDeclarativeItem *parent = 0);
    PBasic(const PBasic &obj);
    PBasic& operator=(const PBasic &obj);

    // --API--- //
    inline       qint16     x()           const { return m_x; }
    inline       qint16     y()           const { return m_y; }
    inline const PStyle     style()       const { return m_style; }

    inline void x(const qint16 val)     { if( m_x == val ) return; m_x = val; emit xChanged(); emit update(); }
    inline void y(const qint16 val)     { if( m_y == val ) return; m_y = val; emit yChanged(); emit update(); }
    inline void style(const PStyle val) { if( m_style == val ) return; m_style = val; emit styleChanged(); emit update(); }

signals:
    void xChanged();
    void yChanged();
    void styleChanged();

protected:
    qint16 m_x;
    qint16 m_y;
    PStyle m_style;
};

#endif // PBASIC_H
