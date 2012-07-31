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

#include "style/pstyle.h"

class PBasic
    : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(qint16 x         READ x WRITE x NOTIFY xChanged)
    Q_PROPERTY(qint16 y         READ y WRITE y NOTIFY yChanged)
    Q_PROPERTY(QColor color     READ color WRITE color NOTIFY colorChanged)
    Q_PROPERTY(qint16 lineWidth READ lineWidth WRITE lineWidth NOTIFY lineWidthChanged)
    Q_PROPERTY(qint16 size      READ size WRITE size NOTIFY sizeChanged)

public:
    explicit PBasic(PStyle *style, QDeclarativeItem *parent = 0);
    PBasic(const PBasic &obj);
    PBasic& operator=(const PBasic &obj);

    // --API--- //
    inline       qint16     x()           const { return m_x; }
    inline       qint16     y()           const { return m_y; }
    inline       qint16     lineWidth()   const { return m_lineWidth; }
    inline       qint16     size()        const { return m_size; }
    inline const QColor&    color()       const { return m_color; }

    inline void x(const qint16 val)         { m_x = val; emit xChanged(); }
    inline void y(const qint16 val)         { m_y = val; emit yChanged(); }
    inline void lineWidth(const qint16 val) { m_lineWidth = val; emit lineWidthChanged(); }
    inline void size(const qint16 val)      { m_size = val; emit sizeChanged(); }
    inline void color(const QColor &val)    { m_color = val; emit colorChanged(); }

signals:
    void xChanged();
    void yChanged();
    void lineWidthChanged();
    void sizeChanged();
    void colorChanged();

protected:
    qint16 m_x;
    qint16 m_y;
    qint16 m_lineWidth;
    qint16 m_size;
    QColor m_color;
};

#endif // PBASIC_H
