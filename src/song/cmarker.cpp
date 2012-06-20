#include "cmarker.h"

const char* CMarker::DEFAULT_TITLE = "Undefined";

CMarker::CMarker(QObject *parent)
    : QObject(parent)
    , m_measure(0)
    , m_title(DEFAULT_TITLE)
    , m_color(DEFAULT_COLOR)
{
}

CMarker::CMarker(const CMarker &obj)
    : QObject()
    , m_measure(obj.measure())
    , m_title(obj.title())
    , m_color(obj.color())
{
}

CMarker &CMarker::operator =(const CMarker &obj)
{
    measure(obj.measure());
    title(obj.title());
    color(obj.color());

    return *this;
}
