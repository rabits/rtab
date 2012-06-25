#include "cbeat.h"

#include "cduration.h"

CBeat::CBeat(QObject *parent)
    : QObject(parent)
    , m_start(CDuration::QUARTER_TIME)
    , m_voices()
    , m_stroke()
    , p_chord(NULL)
    , p_text(NULL)
    , p_measure(NULL)
{
    for( quint16 i = 0; i < MAX_VOICES; i++)
        m_voices[i] = CVoice(i);
}

CBeat::CBeat(const CBeat &obj)
    : QObject()
    , m_start(obj.start())
    , m_voices(obj.voices())
    , m_stroke(obj.stroke())
    , p_chord(NULL)
    , p_text(NULL)
    , p_measure(obj.measure())
{
    chord(obj.chord());
    text(obj.text());
}

CBeat &CBeat::operator =(const CBeat &obj)
{
    start(obj.start());
    stroke(obj.stroke());
    voices(obj.voices());
    chord(obj.chord());
    text(obj.text());

    return *this;
}

void CBeat::chord(const CChord *val)
{
    delete p_chord;
    if( val != NULL)
    {
        p_chord = new CChord(*val);
        p_chord->beat(this);
    }
    emit chordChanged();
}

void CBeat::text(const CText *val)
{
    delete p_text;
    if( val != NULL)
    {
        p_text = new CText(*val);
        p_text->beat(this);
    }
    emit textChanged();
}

void CBeat::voices(const QList<CVoice> &val)
{
    for( int i = 0 ; i < val.count() ; i ++ )
        m_voices[i] = val[i];

    emit voicesChanged();

    if( val.count() > static_cast<int>(MAX_VOICES) )
        log_warn("Used only first %i from %i voices", MAX_VOICES, val.count());
}

const CVoice& CBeat::voice(const quint16 index) const
    throw(Common::CException)
{
    if( index < MAX_VOICES )
        return m_voices[index];

    log_error("Can't get voice %i, it not allow by MAX_VOICES %i", index, MAX_VOICES);
    throw EXCEPTION("Can't get voice");
}

void CBeat::voice(const quint16 index, const CVoice &val)
    throw(Common::CException)
{
    if( index < MAX_VOICES )
    {
        m_voices[index] = val;
        m_voices[index].beat(this);
        emit voicesChanged();
        return;
    }

    log_error("Can't set voice %i, it not allow by MAX_VOICES %i", index, MAX_VOICES);
    throw EXCEPTION("Can't set voice");
}

void CBeat::voiceRemove(const quint16 index)
    throw(Common::CException)
{
    if( index < MAX_VOICES )
    {
        m_voices.removeAt(index);
        emit voicesChanged();
        return;
    }

    log_error("Can't remove voice %i, it not allow by MAX_VOICES %i", index, MAX_VOICES);
    throw EXCEPTION("Can't remove voice");
}

bool CBeat::isRestBeat() const
{
    foreach( CVoice voice, voices() )
    {
        if( !voice.empty() && !voice.isRest() )
            return false;
    }

    return true;
}
