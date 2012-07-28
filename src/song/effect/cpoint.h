/**
 * @file    cpoint.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Basic point for some effects
 *
 */

#ifndef CPOINT_H
#define CPOINT_H

#include <QObject>

class CPoint
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 position READ position WRITE position NOTIFY positionChanged)
    Q_PROPERTY(qint16  value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CPoint(qint8 position, qint8 value, QObject *parent = 0);
    CPoint(const CPoint &obj);
    CPoint& operator=(const CPoint &obj);

    inline bool operator==(const CPoint &obj) const { return position() == obj.position() && value() == obj.value(); }

    // ---API--- //
    inline qint8 position() const { return m_position; }
    inline qint8 value()    const { return m_value; }

    inline void position(const qint8 val) { m_position = val; emit positionChanged(); }
    inline void value(const qint8 val)    { m_value = val; emit valueChanged(); }

signals:
    void positionChanged();
    void valueChanged();

private:
    qint8 m_position;
    qint8 m_value;
};

#endif // CPOINT_H
