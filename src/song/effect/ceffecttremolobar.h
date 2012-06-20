#ifndef CEFFECTTREMOLOBAR_H
#define CEFFECTTREMOLOBAR_H

#include <QObject>

#include "cpoint.h"

class CEffectTremoloBar
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<CPointTremoloBar> points READ points WRITE points NOTIFY pointsChanged)

public:
    explicit CEffectTremoloBar(QObject *parent = 0);
    CEffectTremoloBar(const CEffectTremoloBar &obj);
    CEffectTremoloBar& operator=(const CEffectTremoloBar &obj);

    static const int MAX_POSITION_LENGTH = 12;
    static const int MAX_VALUE_LENGTH    = 12;

    class CPointTremoloBar : public CPoint
    {
    public:
        explicit CPointTremoloBar(int position, int value, QObject *parent = 0);
        inline long time(long duration) { return (duration * position() / MAX_POSITION_LENGTH); }
    };

    // ---API--- //
    inline const QList<CPointTremoloBar>& points() const { return m_points; }

    inline void points(const QList<CPointTremoloBar> &val) { m_points = val; emit pointsChanged(); }

    inline uint                    pointsCount()                      const { return m_points.count(); }
    inline const CPointTremoloBar& point(const uint index)            const { return m_points[index]; }
    inline void                    pointAdd(const int pos, const int val)   { m_points.append(CPointTremoloBar(pos, val)); emit pointsChanged(); }
    inline void                    pointRemove(const uint index)            { m_points.removeAt(index); emit pointsChanged(); }
    inline void                    pointRemove(const CPointTremoloBar &val) { m_points.removeOne(val); emit pointsChanged(); }

signals:
    void pointsChanged();

private:
    QList<CPointTremoloBar> m_points;
};

#endif // CEFFECTTREMOLOBAR_H
