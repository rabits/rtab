#ifndef CCHANNELPARAMETER_H
#define CCHANNELPARAMETER_H

#include "src/common/common.h"

#include <QObject>

class CChannelParameter
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString key   READ key WRITE key NOTIFY keyChanged)
    Q_PROPERTY(QString value READ value WRITE value NOTIFY valueChanged)

public:
    explicit CChannelParameter(QString key, QString value, QObject *parent = 0);
    CChannelParameter(QObject *parent = 0);
    CChannelParameter(const CChannelParameter &obj);
    CChannelParameter& operator=(const CChannelParameter &obj);

    inline bool operator==(const CChannelParameter &obj) const { return key() == obj.key() && value() == obj.value(); }

    // ---API--- //
    inline const QString& key()   const { return m_key; }
    inline const QString& value() const { return m_value; }

    inline void key(const QString &val)   { m_key = val; emit keyChanged(); }
    inline void value(const QString &val) { m_value = val; emit valueChanged(); }

signals:
    void keyChanged();
    void valueChanged();

private:
    QString m_key;
    QString m_value;
};

#endif // CCHANNELPARAMETER_H
