/**
 * @file    cstroke.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Stroke
 *
 */

#ifndef CSTROKE_H
#define CSTROKE_H

#include "src/common/common.h"

#include <QObject>

class CBeat;

class CStroke
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint8 direction READ direction WRITE direction NOTIFY directionChanged)
    Q_PROPERTY(qint8 value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CStroke(QObject *parent = 0);
    CStroke(const CStroke &obj);
    CStroke& operator=(const CStroke &obj);

    inline bool operator==(const CStroke &obj) const { return direction() == obj.direction() && value() == obj.value(); }

    enum STROKE {
        STROKE_DOWN = -1,
        STROKE_NONE =  0,
        STROKE_UP   =  1
    };

    // ---API--- //
    inline qint8 direction() const { return m_direction; }
    inline qint8 value()     const { return m_value; }

    inline void direction(const qint8 val) { m_direction = val; emit directionChanged(); }
    inline void value(const qint8 val)     { m_value = val; emit valueChanged(); }

    qint64 getIncrementTime(const CBeat *beat) const;

signals:
    void directionChanged();
    void valueChanged();

private:
    qint8 m_direction;
    qint8 m_value;
};

#endif // CSTROKE_H
