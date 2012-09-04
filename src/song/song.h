/**
 * @file    song.h
 * @date    2012-9-2T00:00:00+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Song init file
 *
 */

#ifndef SONG_H
#define SONG_H

#include "csong.h"
#include "cscale.h"
#include "cvelocities.h"

class Song {
public:
    inline static void exportQML() {
        qmlRegisterType<CBeat>("RTab", 1, 0, "CBeat");
        qmlRegisterType<CChannel>("RTab", 1, 0, "CChannel");
        qmlRegisterType<CChannelParameter>("RTab", 1, 0, "CChannelParameter");
        qmlRegisterType<CChord>("RTab", 1, 0, "CChord");
        qmlRegisterType<CDivisionType>("RTab", 1, 0, "CDivisionType");
        qmlRegisterType<CDuration>("RTab", 1, 0, "CDuration");
        qmlRegisterType<CLyrics>("RTab", 1, 0, "CLyrics");
        qmlRegisterType<CMarker>("RTab", 1, 0, "CMarker");
        qmlRegisterType<CMeasure>("RTab", 1, 0, "CMeasure");
        qmlRegisterType<CMeasureHeader>("RTab", 1, 0, "CMeasureHeader");
        qmlRegisterType<CNote>("RTab", 1, 0, "CNote");
        qmlRegisterType<CNoteEffect>("RTab", 1, 0, "CNoteEffect");
        qmlRegisterType<CScale>("RTab", 1, 0, "CScale");
        qmlRegisterType<CSong>("RTab", 1, 0, "CSong");
        qmlRegisterType<CString>("RTab", 1, 0, "CString");
        qmlRegisterType<CStroke>("RTab", 1, 0, "CStroke");
        qmlRegisterType<CTempo>("RTab", 1, 0, "CTempo");
        qmlRegisterType<CText>("RTab", 1, 0, "CText");
        qmlRegisterType<CTimeSignature>("RTab", 1, 0, "CTimeSignature");
        qmlRegisterType<CTrack>("RTab", 1, 0, "CTrack");
        qmlRegisterType<CVoice>("RTab", 1, 0, "CVoice");
        qmlRegisterType<CEffectBend>("RTab", 1, 0, "CEffectBend");
        qmlRegisterType<CEffectGrace>("RTab", 1, 0, "CEffectGrace");
        qmlRegisterType<CEffectHormonic>("RTab", 1, 0, "CEffectHormonic");
        qmlRegisterType<CEffectTremoloBar>("RTab", 1, 0, "CEffectTremoloBar");
        qmlRegisterType<CEffectTremoloPicking>("RTab", 1, 0, "CEffectTremoloPicking");
        qmlRegisterType<CEffectTrill>("RTab", 1, 0, "CEffectTrill");
    }
};

#endif // SONG_H
