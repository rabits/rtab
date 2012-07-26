#ifndef CSTREAM_H
#define CSTREAM_H

#include <QString>
#include "../../song/cmeasure.h"
#include "../../song/cbeat.h"

class CStream
{
public:
    CStream();

    inline QString tgName()      { return "TuxGuitar File Format"; }
    inline QString tgVersion()   { return tgName() + " - 1.2.20111001"; }
    inline QString tgExtension() { return ".tg"; }

    enum TRACK {
        TRACK_SOLO   = 0x01,
        TRACK_MUTE   = 0x02,
        TRACK_LYRICS = 0x04
    };

    enum MEASURE_HEADER {
        MEASURE_HEADER_TIMESIGNATURE      = 0x01,
        MEASURE_HEADER_TEMPO              = 0x02,
        MEASURE_HEADER_REPEAT_OPEN        = 0x04,
        MEASURE_HEADER_REPEAT_CLOSE       = 0x08,
        MEASURE_HEADER_REPEAT_ALTERNATIVE = 0x10,
        MEASURE_HEADER_MARKER             = 0x20,
        MEASURE_HEADER_TRIPLET_FEEL       = 0x40
    };

    enum MEASURE {
        MEASURE_CLEF         = 0x01,
        MEASURE_KEYSIGNATURE = 0x02
    };

    enum BEAT {
        BEAT_HAS_NEXT          = 0x01,
        BEAT_HAS_STROKE        = 0x02,
        BEAT_HAS_CHORD         = 0x04,
        BEAT_HAS_TEXT          = 0x08,
        BEAT_HAS_VOICE         = 0x10,
        BEAT_HAS_VOICE_CHANGES = 0x20
    };

    enum VOICE {
        VOICE_HAS_NOTES      = 0x01,
        VOICE_NEXT_DURATION  = 0x02,
        VOICE_DIRECTION_UP   = 0x04,
        VOICE_DIRECTION_DOWN = 0x08
    };

    enum NOTE {
        NOTE_HAS_NEXT = 0x01,
        NOTE_TIED     = 0x02,
        NOTE_EFFECT   = 0x04,
        NOTE_VELOCITY = 0x08
    };

    enum DURATION {
        DURATION_DOTTED        = 0x01,
        DURATION_DOUBLE_DOTTED = 0x02,
        DURATION_NO_TUPLET     = 0x04
    };

    enum EFFECT {
        EFFECT_BEND              = 0x000001,
        EFFECT_TREMOLO_BAR       = 0x000002,
        EFFECT_HARMONIC          = 0x000004,
        EFFECT_GRACE             = 0x000008,
        EFFECT_TRILL             = 0x000010,
        EFFECT_TREMOLO_PICKING   = 0x000020,
        EFFECT_VIBRATO           = 0x000040,
        EFFECT_DEAD              = 0x000080,
        EFFECT_SLIDE             = 0x000100,
        EFFECT_HAMMER            = 0x000200,
        EFFECT_GHOST             = 0x000400,
        EFFECT_ACCENTUATED       = 0x000800,
        EFFECT_HEAVY_ACCENTUATED = 0x001000,
        EFFECT_PALM_MUTE         = 0x002000,
        EFFECT_STACCATO          = 0x004000,
        EFFECT_TAPPING           = 0x008000,
        EFFECT_SLAPPING          = 0x010000,
        EFFECT_POPPING           = 0x020000,
        EFFECT_FADE_IN           = 0x040000,
        EFFECT_LET_RING          = 0x080000
    };

    enum GRACE {
        GRACE_FLAG_DEAD    = 0x01,
        GRACE_FLAG_ON_BEAT = 0x02
    };

protected:
    class CVoiceData {
    public:
        CVoiceData(CMeasure &measure);

        inline qint64           start()    const { return m_start; }
        inline qint8            velocity() const { return m_velocity; }
        inline qint16           flags()    const { return m_flags; }
        inline const CDuration& duration() const { return m_duration; }
        inline CDuration&       duration()       { return m_duration; }

        inline void       start(qint64 val)        { m_start = val; }
        inline void       velocity(qint8 val)     { m_velocity = val; }
        inline void       flags(qint16 val)        { m_flags = val; }
        inline void       duration(CDuration &val) { m_duration = val; }

    private:
        qint64    m_start;
        qint8     m_velocity;
        qint16    m_flags;
        CDuration m_duration;
    };

    class CBeatData {
    public:
        CBeatData(CMeasure &measure);
        qint64     currentStart();

        inline quint16           voicesCount()        const { return m_voices.count(); }
        inline const CVoiceData& voice(quint16 index) const { return m_voices[index]; }
        inline       CVoiceData& voice(quint16 index)       { return m_voices[index]; }

    private:
        qint64            m_current_start;
        QList<CVoiceData> m_voices;
    };
};

#endif // CSTREAM_H
