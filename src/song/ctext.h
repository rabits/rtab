#ifndef CTEXT_H
#define CTEXT_H

#include "src/common/common.h"

#include <QObject>

class CBeat;

class CText
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE value NOTIFY valueChanged)
    Q_PROPERTY(CBeat*  beat READ beat WRITE beat NOTIFY beatChanged)

public:
    explicit CText(QObject *parent = 0);
    CText(const CText &obj);
    CText& operator=(const CText &obj);

    // ---API--- //
    inline const QString& value() const { return m_value; }
    inline CBeat*         beat()  const { return p_beat; }

    inline void value(const QString &val) { m_value = val; emit valueChanged(); }
    inline void beat(CBeat *val)          { p_beat = val; emit beatChanged(); }

    inline bool isEmpty() const { return value().isEmpty(); }

signals:
    void valueChanged();
    void beatChanged();

private:
    QString  m_value;
    CBeat   *p_beat;
};

#endif // CTEXT_H
