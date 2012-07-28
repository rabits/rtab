/**
 * @file
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Output Stream of format tg 1.2-current_svn
 *
 */

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
