#include "cnoteeffect.h"

CNoteEffect::CNoteEffect(QObject *parent)
    : QObject(parent)
    , p_bend(NULL)
    , p_tremoloBar(NULL)
    , p_harmonic(NULL)
    , p_grace(NULL)
    , p_trill(NULL)
    , p_tremoloPicking(NULL)
    , m_vibrato(false)
    , m_dead(false)
    , m_slide(false)
    , m_hammer(false)
    , m_ghost(false)
    , m_accentuated(false)
    , m_heavyAccentuated(false)
    , m_palmMute(false)
    , m_staccato(false)
    , m_tapping(false)
    , m_slapping(false)
    , m_popping(false)
    , m_fadeIn(false)
    , m_letRing(false)
{
}

CNoteEffect::CNoteEffect(const CNoteEffect &obj)
    : QObject()
    , p_bend(NULL)
    , p_tremoloBar(NULL)
    , p_harmonic(NULL)
    , p_grace(NULL)
    , p_trill(NULL)
    , p_tremoloPicking(NULL)
    , m_vibrato(obj.vibrato())
    , m_dead(obj.dead())
    , m_slide(obj.slide())
    , m_hammer(obj.hammer())
    , m_ghost(obj.ghost())
    , m_accentuated(obj.accentuated())
    , m_heavyAccentuated(obj.heavyAccentuated())
    , m_palmMute(obj.palmMute())
    , m_staccato(obj.staccato())
    , m_tapping(obj.tapping())
    , m_slapping(obj.slapping())
    , m_popping(obj.popping())
    , m_fadeIn(obj.fadeIn())
    , m_letRing(obj.letRing())
{
    bend(obj.isBend() ? obj.bend() : NULL);
    tremoloBar(obj.isTremoloBar() ? obj.tremoloBar() : NULL);
    harmonic(obj.isHarmonic() ? obj.harmonic() : NULL);
    grace(obj.isGrace() ? obj.grace() : NULL);
    trill(obj.isTrill() ? obj.trill() : NULL);
    tremoloPicking(obj.isTremoloPicking() ? obj.tremoloPicking() : NULL);
}

CNoteEffect &CNoteEffect::operator =(const CNoteEffect &obj)
{
    vibrato(obj.vibrato());
    dead(obj.dead());
    slide(obj.slide());
    hammer(obj.hammer());
    ghost(obj.ghost());
    accentuated(obj.accentuated());
    heavyAccentuated(obj.heavyAccentuated());
    palmMute(obj.palmMute());
    letRing(obj.letRing());
    staccato(obj.staccato());
    tapping(obj.tapping());
    slapping(obj.slapping());
    popping(obj.popping());
    fadeIn(obj.fadeIn());
    bend(obj.isBend() ? obj.bend() : NULL);
    tremoloBar(obj.isTremoloBar() ? obj.tremoloBar() : NULL);
    harmonic(obj.isHarmonic() ? obj.harmonic() : NULL);
    grace(obj.isGrace() ? obj.grace() : NULL);
    trill(obj.isTrill() ? obj.trill() : NULL);
    tremoloPicking(obj.isTremoloPicking() ? obj.tremoloPicking() : NULL);

    return *this;
}

CNoteEffect::~CNoteEffect()
{
    delete p_bend;
    delete p_tremoloBar;
    delete p_harmonic;
    delete p_grace;
    delete p_trill;
    delete p_tremoloPicking;
}

void CNoteEffect::bend(const CEffectBend *val)
{
    if( bend() != val )
    {
        delete p_bend;
        if( val != NULL )
            p_bend = new CEffectBend(*val);
        emit bendChanged();

        if( isBend() )
        {
            trill(NULL);
            dead(false);
            slide(false);
            hammer(false);
            tremoloBar(NULL);
            tremoloPicking(NULL);
        }
    }
}

void CNoteEffect::tremoloBar(const CEffectTremoloBar *val)
{
    if( tremoloBar() != val )
    {
        delete p_tremoloBar;
        if( val != NULL )
            p_tremoloBar = new CEffectTremoloBar(*val);
        emit tremoloBarChanged();

        if( isTremoloBar() )
        {
            bend(NULL);
            trill(NULL);
            dead(false);
            slide(false);
            hammer(false);
            tremoloPicking(NULL);
        }
    }
}

void CNoteEffect::harmonic(const CEffectHormonic *val)
{
    if( harmonic() != val )
    {
        delete p_harmonic;
        if( val != NULL )
            p_harmonic = new CEffectHormonic(*val);
        emit harmonicChanged();
    }
}

void CNoteEffect::grace(const CEffectGrace *val)
{
    if( grace() != val )
    {
        delete p_grace;
        if( val != NULL )
            p_grace = new CEffectGrace(*val);
        emit graceChanged();
    }
}

void CNoteEffect::trill(const CEffectTrill *val)
{
    if( trill() != val )
    {
        delete p_trill;
        if( val != NULL )
            p_trill = new CEffectTrill(*val);
        emit trillChanged();

        if( isTrill() )
        {
            bend(NULL);
            tremoloBar(NULL);
            tremoloPicking(NULL);
            slide(false);
            hammer(false);
            dead(false);
            vibrato(false);
        }
    }
}

void CNoteEffect::tremoloPicking(const CEffectTremoloPicking *val)
{
    if( tremoloPicking() != val )
    {
        delete p_tremoloPicking;
        if( val != NULL )
            p_tremoloPicking = new CEffectTremoloPicking(*val);
        emit tremoloPickingChanged();

        if( isTremoloPicking() )
        {
            trill(NULL);
            bend(NULL);
            tremoloBar(NULL);
            slide(false);
            hammer(false);
            dead(false);
            vibrato(false);
        }
    }
}

void CNoteEffect::vibrato(const bool val)
{
    if( vibrato() != val )
    {
        m_vibrato = val;
        emit vibratoChanged();

        if( vibrato() )
        {
            trill(NULL);
            tremoloPicking(NULL);
        }
    }
}

void CNoteEffect::dead(const bool val)
{
    if( dead() != val )
    {
        m_dead = val;
        emit deadChanged();

        if( dead() )
        {
            bend(NULL);
            trill(NULL);
            slide(false);
            hammer(false);
            tremoloBar(NULL);
            tremoloPicking(NULL);
        }
    }
}

void CNoteEffect::slide(const bool val)
{
    if( slide() != val )
    {
        m_slide = val;
        emit slideChanged();

        if( slide() )
        {
            trill(NULL);
            bend(NULL);
            dead(false);
            hammer(false);
            tremoloBar(NULL);
            tremoloPicking(NULL);
        }
    }
}

void CNoteEffect::hammer(const bool val)
{
    if( hammer() != val )
    {
        m_hammer = val;
        emit hammerChanged();

        if( hammer() )
        {
            trill(NULL);
            bend(NULL);
            dead(false);
            slide(false);
            tremoloBar(NULL);
            tremoloPicking(NULL);
        }
    }
}

void CNoteEffect::ghost(const bool val)
{
    if( ghost() != val )
    {
        m_ghost = val;
        emit ghostChanged();

        if( ghost() )
        {
            accentuated(false);
            heavyAccentuated(false);
        }
    }
}

void CNoteEffect::accentuated(const bool val)
{
    if( accentuated() != val )
    {
        m_accentuated = val;
        emit accentuatedChanged();

        if( accentuated() )
        {
            ghost(false);
            heavyAccentuated(false);
        }
    }
}

void CNoteEffect::heavyAccentuated(const bool val)
{
    if( heavyAccentuated() != val )
    {
        m_heavyAccentuated = val;
        emit heavyAccentuatedChanged();

        if( heavyAccentuated() )
        {
            ghost(false);
            accentuated(false);
        }
    }
}

void CNoteEffect::palmMute(const bool val)
{
    if( palmMute() != val )
    {
        m_palmMute = val;
        emit palmMuteChanged();

        if( palmMute() )
        {
            staccato(false);
            letRing(false);
        }
    }
}

void CNoteEffect::staccato(const bool val)
{
    if( staccato() != val )
    {
        m_staccato = val;
        emit staccatoChanged();

        if( staccato() )
        {
            palmMute(false);
            letRing(false);
        }
    }
}

void CNoteEffect::tapping(const bool val)
{
    if( tapping() != val )
    {
        m_tapping = val;
        emit tappingChanged();

        if( tapping() )
        {
            slapping(false);
            popping(false);
        }
    }
}

void CNoteEffect::slapping(const bool val)
{
    if( slapping() != val )
    {
        m_slapping = val;
        emit slappingChanged();

        if( slapping() )
        {
            tapping(false);
            popping(false);
        }
    }
}

void CNoteEffect::popping(const bool val)
{
    if( popping() != val )
    {
        m_popping = val;
        emit poppingChanged();

        if( popping() )
        {
            tapping(false);
            slapping(false);
        }
    }
}

void CNoteEffect::fadeIn(const bool val)
{
    if( fadeIn() != val )
    {
        m_fadeIn = val;
        emit fadeInChanged();
    }
}

void CNoteEffect::letRing(const bool val)
{
    if( letRing() != val )
    {
        m_letRing = val;
        emit letRingChanged();

        if( letRing() )
        {
            staccato(false);
            palmMute(false);
        }
    }
}
