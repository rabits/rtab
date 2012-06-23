#ifndef CINPUTSTREAMBASE_H
#define CINPUTSTREAMBASE_H

#include "cfileformat.h"
#include "../../song/csong.h"

class CInputStreamBase
{
public:
    CInputStreamBase() {}
    virtual ~CInputStreamBase() {}

    virtual void init(QDataStream *stream) = 0;
    virtual bool isSupportedVersion() = 0;

    virtual CFileFormat getFileFormat() = 0;
    virtual CSong       readSong() = 0;
};

#endif // CINPUTSTREAMBASE_H
