#include "cexception.h"

using namespace Common;

CException::CException(const QString &description, const QString &source)
    : m_source(source)
    , m_file()
    , m_description(description)
    , m_line(0)
    , m_full_description("Exception: '" + description + "' in " + source)
{
}

CException::CException(const QString &description, const QString &source, const char* file, long line)
    : m_source(source)
    , m_file(file)
    , m_description(description)
    , m_line(line)
    , m_full_description("Exception: '" + description + "' in " + source + " at " + file + " : " + line)
{
}

