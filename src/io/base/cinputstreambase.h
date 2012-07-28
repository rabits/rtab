/**
 * @file    cinputstreambase.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Input Stream Base
 *
 */

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
    virtual CSong*      readSong() = 0;
};

#endif // CINPUTSTREAMBASE_H
