#include "coutputstream.h"

#include "../../song/csong.h"

COutputStream::COutputStream()
    : CStream()
    , COutputStreamBase()
{
}

COutputStream::~COutputStream()
{
}

void COutputStream::init()
{
    // TODO
}

bool COutputStream::isSupportedExtension(QString extension)
{
    // TODO
}

CFileFormat COutputStream::getFileFormat()
{
    // TODO
}

void COutputStream::writeSong(CSong *song)
{
    // TODO
}
