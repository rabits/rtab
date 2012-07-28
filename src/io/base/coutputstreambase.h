/**
 * @file    coutputstreambase.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Output Stream Base
 *
 */

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
