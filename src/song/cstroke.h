#ifndef CSTROKE_H
#define CSTROKE_H

#include "src/common/common.h"

#include <QObject>

class CBeat;

class CStroke
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(STROKE direction READ direction WRITE direction NOTIFY directionChanged)
    Q_PROPERTY(qint16 value READ value WRITE value NOTIFY valueChanged)

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
    inline STROKE direction() const { return m_direction; }
    inline qint16 value()     const { return m_value; }

    inline void direction(const STROKE val) { m_direction = val; emit directionChanged(); }
    inline void value(const qint16 val)     { m_value = val; emit valueChanged(); }

    qint64 getIncrementTime(const CBeat *beat) const;

signals:
    void directionChanged();
    void valueChanged();

private:
    STROKE m_direction;
    qint16    m_value;
};

#endif // CSTROKE_H