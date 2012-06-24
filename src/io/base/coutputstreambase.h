#ifndef COUTPUTSTREAMBASE_H
#define COUTPUTSTREAMBASE_H

#include <QString>

#include "cfileformat.h"

class CSong;

class COutputStreamBase
{
public:
    COutputStreamBase() {}
    virtual ~COutputStreamBase() {}

    virtual void init() = 0;
    virtual bool isSupportedExtension(QString extension) = 0;

    virtual CFileFormat getFileFormat() = 0;
    virtual void        writeSong(CSong *song) = 0;
};

#endif // COUTPUTSTREAMBASE_H
