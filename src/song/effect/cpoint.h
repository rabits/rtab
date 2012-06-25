#ifndef CPOINT_H
#define CPOINT_H

#include <QObject>

class CPoint
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 position READ position WRITE position NOTIFY positionChanged)
    Q_PROPERTY(qint16  value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CPoint(quint16 position, qint16 value, QObject *parent = 0);
    CPoint(const CPoint &obj);
    CPoint& operator=(const CPoint &obj);

    inline bool operator==(const CPoint &obj) const { return position() == obj.position() && value() == obj.value(); }

    // ---API--- //
    inline quint16 position() const { return m_position; }
    inline qint16 value()    const { return m_value; }

    inline void position(const quint16 val) { m_position = val; emit positionChanged(); }
    inline void value(const qint16 val)     { m_value = val; emit valueChanged(); }

signals:
    void positionChanged();
    void valueChanged();

private:
    quint16 m_position;
    qint16  m_value;
};

#endif // CPOINT_H
