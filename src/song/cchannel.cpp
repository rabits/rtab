#include "cchannel.h"

CChannel::CChannel(QObject *parent)
    : QObject(parent)
    , m_id(0)
    , m_bank(DEFAULT_BANK)
    , m_program(DEFAULT_PROGRAM)
    , m_volume(DEFAULT_VOLUME)
    , m_balance(DEFAULT_BALANCE)
    , m_chorus(DEFAULT_CHORUS)
    , m_reverb(DEFAULT_REVERB)
    , m_phaser(DEFAULT_PHASER)
    , m_tremolo(DEFAULT_TREMOLO)
    , m_name()
    , m_parameters()
{
}

CChannel::CChannel(const CChannel &obj)
    : QObject()
    , m_id(obj.id())
    , m_bank(obj.bank())
    , m_program(obj.program())
    , m_volume(obj.volume())
    , m_balance(obj.balance())
    , m_chorus(obj.chorus())
    , m_reverb(obj.reverb())
    , m_phaser(obj.phaser())
    , m_tremolo(obj.tremolo())
    , m_name(obj.name())
    , m_parameters(obj.parameters())
{
}

CChannel &CChannel::operator =(const CChannel &obj)
{
    id(obj.id());
    bank(obj.bank());
    program(obj.program());
    volume(obj.volume());
    balance(obj.balance());
    chorus(obj.chorus());
    reverb(obj.reverb());
    phaser(obj.phaser());
    tremolo(obj.tremolo());
    name(obj.name());

    return *this;
}
