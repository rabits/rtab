/**
 * @file    coutputstream.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Output Stream for tg v1.2-current_svn
 *
 */

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
