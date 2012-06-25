#ifndef CCHANNEL_H
#define CCHANNEL_H

#include "src/common/common.h"

#include <QObject>

#include "cchannelparameter.h"

class CChannel
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint16                   id READ id WRITE id NOTIFY idChanged)
    Q_PROPERTY(short                    bank READ bank WRITE bank NOTIFY bankChanged)
    Q_PROPERTY(short                    program READ program WRITE program NOTIFY programChanged)
    Q_PROPERTY(short                    volume READ volume WRITE volume NOTIFY volumeChanged)
    Q_PROPERTY(short                    balance READ balance WRITE balance NOTIFY balanceChanged)
    Q_PROPERTY(short                    chorus READ chorus WRITE chorus NOTIFY chorusChanged)
    Q_PROPERTY(short                    reverb READ reverb WRITE reverb NOTIFY reverbChanged)
    Q_PROPERTY(short                    phaser READ phaser WRITE phaser NOTIFY phaserChanged)
    Q_PROPERTY(short                    tremolo READ tremolo WRITE tremolo NOTIFY tremoloChanged)
    Q_PROPERTY(QString                  name READ name WRITE name NOTIFY nameChanged)
    Q_PROPERTY(QList<CChannelParameter> parameters READ parameters WRITE parameters NOTIFY parametersChanged)

public:
    explicit CChannel(QObject *parent = 0);
    CChannel(const CChannel &obj);
    CChannel& operator=(const CChannel &obj);

    inline bool operator==(const CChannel &obj) const { return bank() == obj.bank() && program() == obj.program()
                                                                  && volume() == obj.volume() && balance() == obj.balance()
                                                                  && chorus() == obj.chorus() && reverb() == obj.reverb()
                                                                  && phaser() == obj.phaser() && tremolo() == obj.tremolo()
                                                                  && name() == obj.name(); }

    static const short DEFAULT_PERCUSSION_CHANNEL = 9;
    static const short DEFAULT_PERCUSSION_PROGRAM = 0;
    static const short DEFAULT_PERCUSSION_BANK    = 128;

    static const short DEFAULT_BANK    = 0;
    static const short DEFAULT_PROGRAM = 25;
    static const short DEFAULT_VOLUME  = 127;
    static const short DEFAULT_BALANCE = 64;
    static const short DEFAULT_CHORUS  = 0;
    static const short DEFAULT_REVERB  = 0;
    static const short DEFAULT_PHASER  = 0;
    static const short DEFAULT_TREMOLO = 0;

    // ---API--- //
    inline qint16                          id()         const { return m_id; }
    inline short                           bank()       const { return m_bank; }
    inline short                           program()    const { return m_program; }
    inline short                           volume()     const { return m_volume; }
    inline short                           balance()    const { return m_balance; }
    inline short                           chorus()     const { return m_chorus; }
    inline short                           reverb()     const { return m_reverb; }
    inline short                           phaser()     const { return m_phaser; }
    inline short                           tremolo()    const { return m_tremolo; }
    inline const QString&                  name()       const { return m_name; }
    inline const QList<CChannelParameter>& parameters() const { return m_parameters; }

    inline void id(const qint16 val)                            { m_id = val; emit idChanged(); }
    inline void bank(const short val)                           { m_bank = val; emit bankChanged(); }
    inline void program(const short val)                        { m_program = val; emit programChanged(); }
    inline void volume(const short val)                         { m_volume = val; emit volumeChanged(); }
    inline void balance(const short val)                        { m_balance = val; emit balanceChanged(); }
    inline void chorus(const short val)                         { m_chorus = val; emit chorusChanged(); }
    inline void reverb(const short val)                         { m_reverb = val; emit reverbChanged(); }
    inline void phaser(const short val)                         { m_phaser = val; emit phaserChanged(); }
    inline void tremolo(const short val)                        { m_tremolo = val; emit tremoloChanged(); }
    inline void name(const QString &val)                        { m_name = val; emit nameChanged(); }
    inline void parameters(const QList<CChannelParameter> &val) { m_parameters = val; emit parametersChanged(); }

    inline quint16                  parametersCount()                                      const { return m_parameters.count(); }
    inline const CChannelParameter& parameter(const quint16 index)                         const { return m_parameters[index]; }
    inline void                     parameter(const quint16 index, const CChannelParameter &val) { m_parameters[index] = val; emit parametersChanged(); }
    inline void                     parameterAdd(const CChannelParameter &val)                   { m_parameters.append(val); emit parametersChanged(); }
    inline void                     parameterRemove(const quint16 index)                         { m_parameters.removeAt(index); emit parametersChanged(); }
    inline void                     parameterRemove(const CChannelParameter &val)                { m_parameters.removeOne(val); emit parametersChanged(); }

    inline bool isPercussionChannel() const { return bank() == DEFAULT_PERCUSSION_BANK; }

signals:
    void idChanged();
    void bankChanged();
    void programChanged();
    void volumeChanged();
    void balanceChanged();
    void chorusChanged();
    void reverbChanged();
    void phaserChanged();
    void tremoloChanged();
    void nameChanged();
    void parametersChanged();

private:
    quint16                  m_id;
    short                    m_bank;
    short                    m_program;
    short                    m_volume;
    short                    m_balance;
    short                    m_chorus;
    short                    m_reverb;
    short                    m_phaser;
    short                    m_tremolo;
    QString                  m_name;
    QList<CChannelParameter> m_parameters;
};

#endif // CCHANNEL_H
