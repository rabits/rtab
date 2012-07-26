#include "cfilemgr.h"

#include "../tg/cinputstream.h"
#include "../tg/coutputstream.h"
#include "../tg/v12/cinputstreamtg12.h"

CFileMgr* CFileMgr::sp_instance = NULL;

CFileMgr::CFileMgr()
    : QObject()
{
    // Init input and output streams TG current
    inputStreamAdd((CInputStreamBase*) new CInputStream());
    outputStreamAdd((COutputStreamBase*) new COutputStream());

    // Init input stream TG 1.2
    inputStreamAdd((CInputStreamBase*) new CInputStreamTG12());
}

CFileMgr::~CFileMgr()
{
    for( quint16 i = 0; i < inputStreamCount(); i++ )
        delete m_input_streams[i];
    for( quint16 i = 0; i < outputStreamCount(); i++ )
        delete m_output_streams[i];
    m_input_streams.clear();
    m_output_streams.clear();
}

CSong* CFileMgr::load(QDataStream *stream) const
{
    log_info("Start loading file");

    stream->device()->open(QIODevice::ReadOnly);
    stream->device()->reset();
    for( quint16 i = 0; i < inputStreamCount(); i++)
    {
        CInputStreamBase *reader = m_input_streams.at(i);
        log_debug("Processing loader: %1", reader->getFileFormat().name());
        reader->init(stream);
        if( reader->isSupportedVersion() )
            return reader->readSong();
        stream->device()->reset();
    }
    stream->device()->close();

    throw EXCEPTION(log_error("Unknown file format or version"));
}

void CFileMgr::write(QDataStream *stream, CSong &song) const
{
}
