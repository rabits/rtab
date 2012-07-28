/**
 * @file    cduration.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Duration
 *
 */

#ifndef CDURATION_H
#define CDURATION_H

#include "src/common/common.h"

#include <QObject>

#include "cdivisiontype.h"

class CDuration
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint8         value READ value WRITE value NOTIFY valueChanged)
    Q_PROPERTY(bool          dotted READ dotted WRITE dotted NOTIFY dottedChanged)
    Q_PROPERTY(bool          doubleDotted READ doubleDotted WRITE doubleDotted NOTIFY doubleDottedChanged)
    Q_PROPERTY(CDivisionType divisionType READ divisionType WRITE divisionType NOTIFY divisionTypeChanged)

public:
    explicit CDuration(QObject *parent = 0);
    CDuration(const CDuration &obj);
    CDuration& operator=(const CDuration &obj);

    inline bool operator==(const CDuration &obj) const { return value() == obj.value() && doubleDotted() == obj.doubleDotted()
                                                                   && dotted() == obj.dotted() && divisionType() == obj.divisionType(); }

    static const qint64 QUARTER_TIME = 960;

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
    inline qint16               value()        const { return m_value; }
    inline bool                 dotted()       const { return m_dotted; }
    inline bool                 doubleDotted() const { return m_doubleDotted; }
    inline const CDivisionType& divisionType() const { return m_divisionType; }
    inline CDivisionType&       divisionType()       { return m_divisionType; }

    inline void value(const qint8 val)                 { m_value = val; emit valueChanged(); }
    inline void dotted(const bool val)                 { m_dotted = val; emit dottedChanged(); }
    inline void doubleDotted(const bool val)           { m_doubleDotted = val; emit doubleDottedChanged(); }
    inline void divisionType(const CDivisionType &val) { m_divisionType = val; emit divisionTypeChanged(); }

    CDuration        fromTime(qint64 in_time) const;
    inline CDuration fromTime(qint64 in_time, CDuration &minDuration) const { return fromTime(in_time, minDuration, 10); }
    CDuration        fromTime(qint64 in_time, CDuration minDuration, qint32 diff) const;
    qint64 time() const;
    qint16 index() const;

signals:
    void valueChanged();
    void dottedChanged();
    void doubleDottedChanged();
    void divisionTypeChanged();

private:
    qint8         m_value;
    bool          m_dotted;
    bool          m_doubleDotted;
    CDivisionType m_divisionType;
};

#endif // CDURATION_H
