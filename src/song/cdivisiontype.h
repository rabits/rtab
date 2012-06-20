#ifndef CDIVISIONTYPE_H
#define CDIVISIONTYPE_H

#include "src/common/common.h"

#include <QObject>

class CDivisionType
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int enter READ enter WRITE enter NOTIFY enterChanged)
    Q_PROPERTY(int time READ time WRITE time NOTIFY timeChanged)

public:
    explicit CDivisionType(QObject *parent = 0);
    CDivisionType(int enter, int time, QObject *parent = 0);
    CDivisionType(const CDivisionType &obj);
    CDivisionType& operator=(const CDivisionType &obj);

    inline bool operator==(const CDivisionType &obj) const { return enter() == obj.enter() && time() == obj.time(); }

    static const CDivisionType NORMAL;
    static const CDivisionType TRIPLET;

    // ---API--- //
    inline int enter() const { return m_enter; }
    inline int time()  const { return m_time; }

    inline void enter(const int val) { m_enter = val; emit enterChanged(); }
    inline void time(const int val) { m_time = val; emit timeChanged(); }

    inline long convertTime(long in_time) const { return in_time * time() / enter(); }

signals:
    void enterChanged();
    void timeChanged();

private:
    int m_enter;
    int m_time;
};

#endif // CDIVISIONTYPE_H
