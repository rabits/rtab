#include "cexception.h"

using namespace Common;

#include <sstream>

CException::CException(const std::string &description, const std::string &source)
    : m_source(source)
    , m_file()
    , m_description(description)
    , m_line(0)
    , m_fullDescription()
{
}

CException::CException(const std::string &description, const std::string &source, const char* file, long line)
    : m_source(source)
    , m_file(file)
    , m_description(description)
    , m_line(line)
    , m_fullDescription()
{
}

const std::string& CException::fullDescription() const
{
    if( m_fullDescription.empty() )
    {
        std::stringstream full;

        full << "Exception: '" << m_description << "' in " << m_source;

        if( m_line > 0 )
            full << " at " << m_file << "(line " << m_line << ")";

        m_fullDescription = full.str();
    }

    return m_fullDescription;
}

