#ifndef CBEAT_H
#define CBEAT_H

#include "src/common/common.h"

#include <QObject>

class CMeasure;
#include "cchord.h"
#include "ctext.h"
#include "cvoice.h"
#include "cstroke.h"

class CBeat
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64        start READ start WRITE start NOTIFY startChanged)
    Q_PROPERTY(QList<CVoice> voices READ voices WRITE voices NOTIFY voicesChanged)
    Q_PROPERTY(CStroke       stroke READ stroke WRITE stroke NOTIFY strokeChanged)
    Q_PROPERTY(CChord*       chord READ chord WRITE chord NOTIFY chordChanged)
    Q_PROPERTY(CText*        text READ text WRITE text NOTIFY textChanged)
    Q_PROPERTY(CMeasure*     measure READ measure WRITE measure NOTIFY measureChanged)

public:
    explicit CBeat(QObject *parent = 0);
    CBeat(const CBeat &obj);
    CBeat& operator=(const CBeat &obj);

    inline bool operator==(const CBeat &obj) const { return start() == obj.start() && voices() == obj.voices()
                                                               && stroke() == obj.stroke() && chord() == obj.chord()
                                                               && text() == obj.text(); }

    static const uint MAX_VOICES = 2;

    // ---API--- //
    inline qint64               start()   const { return m_start; }
    inline const QList<CVoice>& voices()  const { return m_voices; }
    inline const CStroke&       stroke()  const { return m_stroke; }
    inline CChord*              chord()   const { return p_chord; }
    inline CText*               text()    const { return p_text; }
    inline CMeasure*            measure() const { return p_measure; }

    inline void start(const qint64 val)          { m_start = val; emit startChanged(); }
           void voices(const QList<CVoice> &val);
    inline void stroke(const CStroke &val)       { m_stroke = val; emit strokeChanged(); }
           void chord(const CChord *val);
           void text(const CText *val);
    inline void measure(CMeasure *val)           { p_measure = val; emit measureChanged(); }

    inline quint16    voicesCount()              const { return m_voices.count(); }
    const CVoice&     voice(const quint16 index) const throw(Common::CException);
    void              voice(const quint16 index, const CVoice &val) throw(Common::CException);
    void              voiceRemove(const quint16 index) throw(Common::CException);
    inline void       voiceRemove(const CVoice &val)   { m_voices.removeOne(val); emit voicesChanged(); }

    inline bool isChordBeat() const { return chord() != NULL; }
    inline bool isTextBeat()  const { return text() != NULL; }
    bool        isRestBeat()  const;

signals:
    void startChanged();
    void voicesChanged();
    void strokeChanged();
    void chordChanged();
    void textChanged();
    void measureChanged();

private:
    qint64         m_start;
    QList<CVoice>  m_voices;
    CStroke        m_stroke;
    CChord        *p_chord;
    CText         *p_text;
    CMeasure      *p_measure;
};

#endif // CBEAT_H
