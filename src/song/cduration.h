#ifndef CDURATION_H
#define CDURATION_H

#include "src/common/common.h"

#include <QObject>

#include "cdivisiontype.h"

class CDuration
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int           value READ value WRITE value NOTIFY valueChanged)
    Q_PROPERTY(bool          dotted READ dotted WRITE dotted NOTIFY dottedChanged)
    Q_PROPERTY(bool          doubleDotted READ doubleDotted WRITE doubleDotted NOTIFY doubleDottedChanged)
    Q_PROPERTY(CDivisionType divisionType READ divisionType WRITE divisionType NOTIFY divisionTypeChanged)

public:
    explicit CDuration(QObject *parent = 0);
    CDuration(const CDuration &obj);
    CDuration& operator=(const CDuration &obj);

    inline bool operator==(const CDuration &obj) const { return value() == obj.value() && doubleDotted() == obj.doubleDotted()
                                                                   && dotted() == obj.dotted() && divisionType() == obj.divisionType(); }

    static const long QUARTER_TIME = 960;

    enum DURATION {
        WHOLE         = 1,
        HALF          = 2,
        QUARTER       = 4,
        EIGHTH        = 8,
        SIXTEENTH     = 16,
        THIRTY_SECOND = 32,
        SIXTY_FOURTH  = 64
    };

    // ---API--- //
    inline int                  value()        const { return m_value; }
    inline bool                 dotted()       const { return m_dotted; }
    inline bool                 doubleDotted() const { return m_doubleDotted; }
    inline const CDivisionType& divisionType() const { return m_divisionType; }

    inline void value(const int val)                   { m_value = val; emit valueChanged(); }
    inline void dotted(const bool val)                 { m_dotted = val; emit dottedChanged(); }
    inline void doubleDotted(const bool val)           { m_doubleDotted = val; emit doubleDottedChanged(); }
    inline void divisionType(const CDivisionType &val) { m_divisionType = val; emit divisionTypeChanged(); }

    CDuration        fromTime(long in_time) const;
    inline CDuration fromTime(long in_time, CDuration &minDuration) const { return fromTime(in_time, minDuration, 10); }
    CDuration        fromTime(long in_time, CDuration minDuration, int diff) const;
    long time() const;
    int index() const;

signals:
    void valueChanged();
    void dottedChanged();
    void doubleDottedChanged();
    void divisionTypeChanged();

private:
    int           m_value;
    bool          m_dotted;
    bool          m_doubleDotted;
    CDivisionType m_divisionType;
};

#endif // CDURATION_H
