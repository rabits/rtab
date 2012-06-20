#ifndef CSTRING_H
#define CSTRING_H

#include "src/common/common.h"

#include <QObject>

class CString
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number READ number WRITE number NOTIFY numberChanged)
    Q_PROPERTY(int value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CString(QObject *parent = 0);
    CString(const CString &obj);
    CString& operator=(const CString &obj);

    inline bool operator==(const CString &obj) const { return value() == obj.value(); }

    // ---API--- //
    inline int number() const { return m_number; }
    inline int value()  const { return m_value; }

    inline void number(const int val) { m_number = val; emit numberChanged(); }
    inline void value(const int val)  { m_value = val; emit valueChanged(); }

signals:
    void numberChanged();
    void valueChanged();

private:
    int m_number;
    int m_value;
};

#endif // CSTRING_H
