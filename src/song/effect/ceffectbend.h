#ifndef CEFFECTBEND_H
#define CEFFECTBEND_H

#include <QObject>

#include "cpoint.h"

class CEffectBend
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<CPointBend> points READ points WRITE points NOTIFY pointsChanged)

public:
    explicit CEffectBend(QObject *parent = 0);
    CEffectBend(const CEffectBend &obj);
    CEffectBend& operator=(const CEffectBend &obj);

    static const int SEMITONE_LENGTH     = 1;
    static const int MAX_POSITION_LENGTH = 12;
    static const int MAX_VALUE_LENGTH    = (SEMITONE_LENGTH * 12);

    class CPointBend : public CPoint
    {
    public:
        explicit CPointBend(int position, int value, QObject *parent = 0);
        inline long time(long duration) const { return (duration * position() / MAX_POSITION_LENGTH); }
    };

    // ---API--- //
    inline const QList<CPointBend>& points() const { return m_points; }

    inline void points(const QList<CPointBend> &val) { m_points = val; emit pointsChanged(); }

    inline uint              pointsCount()                    const { return m_points.count(); }
    inline const CPointBend& point(const uint index)          const { return m_points[index]; }
    inline void              pointAdd(const int pos, const int val) { m_points.append(CPointBend(pos, val)); emit pointsChanged(); }
    inline void              pointRemove(const uint index)          { m_points.removeAt(index); emit pointsChanged(); }
    inline void              pointRemove(const CPointBend &val)     { m_points.removeOne(val); emit pointsChanged(); }

signals:
    void pointsChanged();

private:
    QList<CPointBend> m_points;
};

#endif // CEFFECTBEND_H
