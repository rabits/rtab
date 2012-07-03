#ifndef CTIMESIGNATURE_H
#define CTIMESIGNATURE_H

#include "src/common/common.h"

#include <QObject>

#include "cduration.h"

class CTimeSignature
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CDuration denominator READ denominator WRITE denominator NOTIFY denominatorChanged)
    Q_PROPERTY(qint8     numerator READ numerator WRITE numerator NOTIFY numeratorChanged)

public:
    explicit CTimeSignature(QObject *parent = 0);
    CTimeSignature(const CTimeSignature &obj);
    CTimeSignature& operator=(const CTimeSignature &obj);

    inline bool operator==(const CTimeSignature &obj) const { return numerator() == obj.numerator()
                                                                        && denominator() == obj.denominator(); }

    // ---API--- //
    inline const CDuration& denominator() const { return m_denominator; }
    inline CDuration&       denominator()       { return m_denominator; }
    inline qint8            numerator()   const { return m_numerator; }

    inline void denominator(const CDuration &val) { m_denominator = val; emit denominatorChanged(); }
    inline void numerator(const qint8 &val)       { m_numerator = val; emit numeratorChanged(); }

signals:
    void denominatorChanged();
    void numeratorChanged();

private:
    CDuration m_denominator;
    qint8     m_numerator;
};

#endif // CTIMESIGNATURE_H
