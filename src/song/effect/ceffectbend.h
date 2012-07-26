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

    static const quint16 SEMITONE_LENGTH     = 1;
    static const quint16 MAX_POSITION_LENGTH = 12;
    static const quint16 MAX_VALUE_LENGTH    = (SEMITONE_LENGTH * 12);

    class CPointBend : public CPoint
    {
    public:
        explicit CPointBend(qint8 position, qint8 value, QObject *parent = 0);
        inline qint64 time(qint64 duration) const { return (duration * position() / MAX_POSITION_LENGTH); }
    };

    // ---API--- //
    inline const QList<CPointBend>& points() const { return m_points; }

    inline void points(const QList<CPointBend> &val) { m_points = val; emit pointsChanged(); }

    inline quint16           pointsCount()                        const { return m_points.count(); }
    inline const CPointBend& point(const quint16 index)           const { return m_points[index]; }
    inline CPointBend&       point(const quint16 index)                 { return m_points[index]; }
    inline void              pointAdd(const qint8 pos, const qint8 val) { m_points.append(CPointBend(pos, val)); emit pointsChanged(); }
    inline void              pointRemove(const quint16 index)           { m_points.removeAt(index); emit pointsChanged(); }
    inline void              pointRemove(const CPointBend &val)         { m_points.removeOne(val); emit pointsChanged(); }

signals:
    void pointsChanged();

private:
    QList<CPointBend> m_points;
};

#endif // CEFFECTBEND_H
