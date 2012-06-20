#ifndef CNOTE_H
#define CNOTE_H

#include "src/common/common.h"

#include <QObject>

#include "cnoteeffect.h"

class CVoice;

class CNote
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int         value READ value WRITE value NOTIFY valueChanged)
    Q_PROPERTY(int         velocity READ velocity WRITE velocity NOTIFY velocityChanged)
    Q_PROPERTY(int         string READ string WRITE string NOTIFY stringChanged)
    Q_PROPERTY(bool        tied READ tied WRITE tied NOTIFY tiedChanged)
    Q_PROPERTY(CNoteEffect effect READ effect WRITE effect NOTIFY effectChanged)
    Q_PROPERTY(CVoice*     voice READ voice WRITE voice NOTIFY voiceChanged)

public:
    explicit CNote(QObject *parent = 0);
    CNote(const CNote &obj);
    CNote& operator=(const CNote &obj);

    inline bool operator==(const CNote &obj) const { return value() == obj.value() && velocity() == obj.velocity()
                                                               && string() == obj.string() && tied() == obj.tied()
                                                               && effect() == obj.effect(); }

    // ---API--- //
    inline int                value()    const { return m_value; }
    inline int                velocity() const { return m_velocity; }
    inline int                string()   const { return m_string; }
    inline bool               tied()     const { return m_tied; }
    inline const CNoteEffect& effect()   const { return m_effect; }
    inline CVoice*            voice()    const { return p_voice; }

    inline void value(const int val)           { m_value = val; emit valueChanged(); }
    inline void velocity(const int val)        { m_velocity = val; emit velocityChanged(); }
    inline void string(const int val)          { m_string = val; emit stringChanged(); }
    inline void tied(const bool val)           { m_tied = val; emit tiedChanged(); }
    inline void effect(const CNoteEffect &val) { m_effect = val; emit effectChanged(); }
    inline void voice(CVoice *val)             { p_voice = val; emit voiceChanged(); }

signals:
    void valueChanged();
    void velocityChanged();
    void stringChanged();
    void tiedChanged();
    void effectChanged();
    void voiceChanged();

private:
    int          m_value;
    int          m_velocity;
    int          m_string;
    bool         m_tied;
    CNoteEffect  m_effect;
    CVoice      *p_voice;
};

#endif // CNOTE_H
