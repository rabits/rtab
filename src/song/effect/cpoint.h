#ifndef CPOINT_H
#define CPOINT_H

#include <QObject>

class CPoint
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int position READ position WRITE position NOTIFY positionChanged)
    Q_PROPERTY(int value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CPoint(int position, int value, QObject *parent = 0);
    CPoint(const CPoint &obj);
    CPoint& operator=(const CPoint &obj);

    inline bool operator==(const CPoint &obj) const { return position() == obj.position() && value() == obj.value(); }

    // ---API--- //
    inline int position() const { return m_position; }
    inline int value()    const { return m_value; }

    inline void position(const int val) { m_position = val; emit positionChanged(); }
    inline void value(const int val)    { m_value = val; emit valueChanged(); }

signals:
    void positionChanged();
    void valueChanged();

private:
    int m_position;
    int m_value;
};

#endif // CPOINT_H
