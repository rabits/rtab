#include "cfilemgr.h"

#include "../tg/cinputstream.h"
#include "../tg/coutputstream.h"

CFileMgr* CFileMgr::sp_instance = NULL;

CFileMgr::CFileMgr()
    : QObject()
{
    // Init input and output streams
    inputStreamAdd((CInputStreamBase*) new CInputStream());
    outputStreamAdd((COutputStreamBase*) new COutputStream());
}

CFileMgr::~CFileMgr()
{
    for( uint i = 0; i < inputStreamCount(); i++ )
        delete m_input_streams[i];
    for( uint i = 0; i < outputStreamCount(); i++ )
        delete m_output_streams[i];
    m_input_streams.clear();
    m_output_streams.clear();
}

CSong CFileMgr::load(QDataStream *stream) const
{
    log_notice("Start loading file");
    try {
        stream->device()->open(QIODevice::ReadOnly);
        stream->device()->reset();
        for( uint i = 0; i < inputStreamCount(); i++)
        {
            CInputStreamBase *reader = m_input_streams.at(i);
            log_notice("Processing loader: %s", reader->getFileFormat().name().toStdString().c_str());
            reader->init(stream);
            if( reader->isSupportedVersion() )
                return reader->readSong();
            stream->device()->reset();
        }
        stream->device()->close();
    }
    catch(Common::CException const &e) {
        log_error("Exception ocurred: %s");
    }

    throw EXCEPTION("Unsupported file format");
}

void CFileMgr::write(QDataStream *stream, CSong &song) const
{
}
