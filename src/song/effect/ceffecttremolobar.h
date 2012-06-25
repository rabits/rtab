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

    static const qint16 MAX_POSITION_LENGTH = 12;
    static const qint16 MAX_VALUE_LENGTH    = 12;

    class CPointTremoloBar : public CPoint
    {
    public:
        explicit CPointTremoloBar(quint16 position, qint16 value, QObject *parent = 0);
        inline qint64 time(qint64 duration) { return (duration * position() / MAX_POSITION_LENGTH); }
    };

    // ---API--- //
    inline const QList<CPointTremoloBar>& points() const { return m_points; }

    inline void points(const QList<CPointTremoloBar> &val) { m_points = val; emit pointsChanged(); }

    inline quint16                 pointsCount()                             const { return m_points.count(); }
    inline const CPointTremoloBar& point(const quint16 index)                const { return m_points[index]; }
    inline void                    pointAdd(const quint16 pos, const qint16 val)   { m_points.append(CPointTremoloBar(pos, val)); emit pointsChanged(); }
    inline void                    pointRemove(const quint16 index)                { m_points.removeAt(index); emit pointsChanged(); }
    inline void                    pointRemove(const CPointTremoloBar &val)        { m_points.removeOne(val); emit pointsChanged(); }

signals:
    void pointsChanged();

private:
    QList<CPointTremoloBar> m_points;
};

#endif // CEFFECTTREMOLOBAR_H
