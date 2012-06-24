#ifndef COUTPUTSTREAM_H
#define COUTPUTSTREAM_H

#include "cstream.h"
#include "../base/coutputstreambase.h"

class COutputStream
    : public CStream
    , public COutputStreamBase
{
public:
    COutputStream();
    ~COutputStream();

    void init();
    bool isSupportedExtension(QString extension);

    CFileFormat getFileFormat();
    void        writeSong(CSong *song);
};

#endif // COUTPUTSTREAM_H
