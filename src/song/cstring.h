/**
 * @file    cstring.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   String
 *
 */

#ifndef CSTRING_H
#define CSTRING_H

#include "src/common/common.h"

#include <QObject>

class CString
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint8 number READ number WRITE number NOTIFY numberChanged)
    Q_PROPERTY(qint16 value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CString(QObject *parent = 0);
    CString(const CString &obj);
    CString& operator=(const CString &obj);

    inline bool operator==(const CString &obj) const { return value() == obj.value(); }

    // ---API--- //
    inline quint8 number() const { return m_number; }
    inline qint16 value()  const { return m_value; }

    inline void number(const quint8 val) { m_number = val; emit numberChanged(); }
    inline void value(const qint16 val)  { m_value = val; emit valueChanged(); }

signals:
    void numberChanged();
    void valueChanged();

private:
    quint8 m_number;
    qint16 m_value;
};

#endif // CSTRING_H
