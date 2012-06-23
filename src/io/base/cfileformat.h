#ifndef CFILEFORMAT_H
#define CFILEFORMAT_H

#include <QStringList>

class CFileFormat
{
public:
    inline CFileFormat(QString name, QStringList supported_formats)
        : m_name(name), m_supported_formats(supported_formats) {}

    const QString&     name()             const { return m_name; }
    const QStringList& supportedFormats() const { return m_supported_formats; }

protected:
    QString     m_name;
    QStringList m_supported_formats;
};

#endif // CFILEFORMAT_H
