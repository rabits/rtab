#ifndef CTEMPO_H
#define CTEMPO_H

#include "src/common/common.h"

#include <QObject>

class CTempo
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CTempo(int value = 120, QObject *parent = 0);
    CTempo(const CTempo &obj);
    CTempo& operator=(const CTempo &obj);

    inline bool operator==(const CTempo &obj) const { return value() == obj.value(); }

    // ---API--- //
    inline int value()   const { return m_value; }

    inline void value(const int val) { m_value = val; emit valueChanged(); }

    inline long   inMillis()             const { return qRound64(60.0f / value() * SECOND_IN_MILLIS); }
    inline long   inUSQ()                const { return ((60.00f / value() * SECOND_IN_MILLIS) * 1000); }
    inline CTempo fromUSQ(const int usq) const { return CTempo((60.0f * SECOND_IN_MILLIS) / (usq / 1000)); }

signals:
    void valueChanged();

private:
    static const int SECOND_IN_MILLIS = 1000;
    int m_value;
};

#endif // CTEMPO_H
