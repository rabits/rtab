#ifndef CTEMPO_H
#define CTEMPO_H

#include "src/common/common.h"

#include <QObject>

class CTempo
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint16 value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CTempo(qint16 value = 120, QObject *parent = 0);
    CTempo(const CTempo &obj);
    CTempo& operator=(const CTempo &obj);

    inline bool operator==(const CTempo &obj) const { return value() == obj.value(); }

    // ---API--- //
    inline qint16 value()   const { return m_value; }

    inline void value(const qint16 val) { m_value = val; emit valueChanged(); }

    inline qint64 inMillis()                const { return qRound64(60.0f / value() * SECOND_IN_MILLIS); }
    inline qint64 inUSQ()                   const { return ((60.00f / value() * SECOND_IN_MILLIS) * 1000); }
    inline CTempo fromUSQ(const qint16 usq) const { return CTempo((60.0f * SECOND_IN_MILLIS) / (usq / 1000)); }

signals:
    void valueChanged();

private:
    static const qint16 SECOND_IN_MILLIS = 1000;
    qint16 m_value;
};

#endif // CTEMPO_H
