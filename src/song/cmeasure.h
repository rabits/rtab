/**
 * @file    cmeasure.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Measure
 *
 */

#ifndef CMEASURE_H
#define CMEASURE_H

#include "src/common/common.h"

#include <QObject>

class CTrack;

#include "cmeasureheader.h"
#include "cbeat.h"

class CMeasure
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint8           clef READ clef WRITE clef NOTIFY clefChanged)
    Q_PROPERTY(qint16          keySignature READ keySignature WRITE keySignature NOTIFY keySignatureChanged)
    Q_PROPERTY(QList<CBeat>    beats READ beats WRITE beats NOTIFY beatsChanged)
    Q_PROPERTY(CMeasureHeader* header READ header WRITE header NOTIFY headerChanged)
    Q_PROPERTY(CTrack*         track READ track WRITE track NOTIFY trackChanged)

public:
    explicit CMeasure(CMeasureHeader *header = NULL, QObject *parent = 0);
    CMeasure(const CMeasure &obj);
    CMeasure(CMeasureHeader &obj);
    CMeasure& operator=(const CMeasure &obj);

    inline bool operator==(const CMeasure &obj) const { return clef() == obj.clef() && keySignature() == obj.keySignature()
                                                                  && beats() == obj.beats(); }

    enum CLEF {
        CLEF_TREBLE = 1,
        CLEF_BASS   = 2,
        CLEF_TENOR  = 3,
        CLEF_ALTO   = 4
    };

    static const CLEF   DEFAULT_CLEF = CLEF_TREBLE;
    static const qint16 DEFAULT_KEY_SIGNATURE = 0;

    // ---API--- //
    inline qint8               clef()         const { return m_clef; }
    inline qint16              keySignature() const { return m_keySignature; }
    inline const QList<CBeat>& beats()        const { return m_beats; }
    inline CMeasureHeader*     header()       const { return p_header; }
    inline CMeasureHeader*     header()             { return p_header; }
    inline CTrack*             track()        const { return p_track; }

    inline void clef(const qint8 val)          { m_clef = val; emit clefChanged(); }
    inline void keySignature(const qint16 val) { m_keySignature = val; emit keySignatureChanged(); }
    inline void beats(const QList<CBeat> &val) { m_beats = val; emit beatsChanged(); }
    inline void header(CMeasureHeader *val)    { p_header = val; emit headerChanged(); }
    inline void track(CTrack *val)             { p_track = val; emit trackChanged(); }

    inline quint16      beatsCount()                          const { return m_beats.count(); }
    inline const CBeat& beat(const quint16 index)             const { return m_beats[index]; }
    inline CBeat&       beat(const quint16 index)                   { return m_beats[index]; }
    inline void         beat(const quint16 index, const CBeat &val) { m_beats[index] = val; m_beats[index].measure(this); emit beatsChanged(); }
    inline void         beatAdd(const CBeat &val)                   { m_beats.append(val); m_beats.last().measure(this); emit beatsChanged(); }
    inline void         beatRemove(const quint16 index)             { m_beats.removeAt(index); emit beatsChanged(); }
    inline void         beatRemove(const CBeat &val)                { m_beats.removeOne(val); emit beatsChanged(); }

signals:
    void trackChanged();
    void clefChanged();
    void keySignatureChanged();
    void beatsChanged();
    void headerChanged();

private:
    void updateThisLinks();

    qint8           m_clef;
    qint16          m_keySignature;
    QList<CBeat>    m_beats;
    CMeasureHeader *p_header;
    CTrack         *p_track;
};

#endif // CMEASURE_H
