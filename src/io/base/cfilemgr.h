/**
 * @file    cfilemgr.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   File Manager
 *
 */

#ifndef CFILEFORMATMANAGER_H
#define CFILEFORMATMANAGER_H

#include "../../common/common.h"

#include <QObject>
#include <QDataStream>

#include "cinputstreambase.h"
#include "coutputstreambase.h"
#include "../../song/csong.h"

class CFileMgr
    : public QObject
{
    Q_OBJECT

public:
    inline static CFileMgr* i() { if( sp_instance == NULL ) sp_instance = new CFileMgr(); return sp_instance; }
    inline static void      destroyInstance() { delete sp_instance; }

    // ---API--- //
    uint inputStreamCount() const { return m_input_streams.count(); }
    void inputStreamAdd(CInputStreamBase *stream) { m_input_streams.append(stream); }

    uint outputStreamCount() const { return m_output_streams.count(); }
    void outputStreamAdd(COutputStreamBase *stream) { m_output_streams.append(stream); }

    CSong* load(QDataStream *stream) const;
    void   write(QDataStream *stream, CSong &song) const;

private:
    explicit CFileMgr();
    ~CFileMgr();
    static CFileMgr* sp_instance;

    QList<CInputStreamBase*>  m_input_streams;
    QList<COutputStreamBase*> m_output_streams;
};

#endif // CFILEFORMATMANAGER_H
