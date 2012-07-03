#ifndef CDIVISIONTYPE_H
#define CDIVISIONTYPE_H

#include "src/common/common.h"

#include <QObject>

class CDivisionType
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint8 enter READ enter WRITE enter NOTIFY enterChanged)
    Q_PROPERTY(qint8 time READ time WRITE time NOTIFY timeChanged)

public:
    explicit CDivisionType(QObject *parent = 0);
    CDivisionType(qint16 enter, qint16 time, QObject *parent = 0);
    CDivisionType(const CDivisionType &obj);
    CDivisionType& operator=(const CDivisionType &obj);

    inline bool operator==(const CDivisionType &obj) const { return enter() == obj.enter() && time() == obj.time(); }

    static const CDivisionType NORMAL;
    static const CDivisionType TRIPLET;

    // ---API--- //
    inline qint8  enter() const { return m_enter; }
    inline qint8 time()  const { return m_time; }

    inline void enter(const qint8 val) { m_enter = val; emit enterChanged(); }
    inline void time(const qint8 val)  { m_time = val; emit timeChanged(); }

    inline qint64 convertTime(qint64 in_time) const { return in_time * time() / enter(); }

signals:
    void enterChanged();
    void timeChanged();

private:
    qint8 m_enter;
    qint8 m_time;
};

#endif // CDIVISIONTYPE_H
