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
    Q_PROPERTY(qint8                    bank READ bank WRITE bank NOTIFY bankChanged)
    Q_PROPERTY(qint8                    program READ program WRITE program NOTIFY programChanged)
    Q_PROPERTY(qint8                    volume READ volume WRITE volume NOTIFY volumeChanged)
    Q_PROPERTY(qint8                    balance READ balance WRITE balance NOTIFY balanceChanged)
    Q_PROPERTY(qint8                    chorus READ chorus WRITE chorus NOTIFY chorusChanged)
    Q_PROPERTY(qint8                    reverb READ reverb WRITE reverb NOTIFY reverbChanged)
    Q_PROPERTY(qint8                    phaser READ phaser WRITE phaser NOTIFY phaserChanged)
    Q_PROPERTY(qint8                    tremolo READ tremolo WRITE tremolo NOTIFY tremoloChanged)
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

    static const qint8 DEFAULT_PERCUSSION_CHANNEL = 9;
    static const qint8 DEFAULT_PERCUSSION_PROGRAM = 0;
    static const qint8 DEFAULT_PERCUSSION_BANK    = 128;

    static const qint8 DEFAULT_BANK    = 0;
    static const qint8 DEFAULT_PROGRAM = 25;
    static const qint8 DEFAULT_VOLUME  = 127;
    static const qint8 DEFAULT_BALANCE = 64;
    static const qint8 DEFAULT_CHORUS  = 0;
    static const qint8 DEFAULT_REVERB  = 0;
    static const qint8 DEFAULT_PHASER  = 0;
    static const qint8 DEFAULT_TREMOLO = 0;

    // ---API--- //
    inline qint16                          id()         const { return m_id; }
    inline qint8                           bank()       const { return m_bank; }
    inline qint8                           program()    const { return m_program; }
    inline qint8                           volume()     const { return m_volume; }
    inline qint8                           balance()    const { return m_balance; }
    inline qint8                           chorus()     const { return m_chorus; }
    inline qint8                           reverb()     const { return m_reverb; }
    inline qint8                           phaser()     const { return m_phaser; }
    inline qint8                           tremolo()    const { return m_tremolo; }
    inline const QString&                  name()       const { return m_name; }
    inline const QList<CChannelParameter>& parameters() const { return m_parameters; }

    inline void id(const qint16 val)                            { m_id = val; emit idChanged(); }
    inline void bank(const qint8 val)                           { m_bank = val; emit bankChanged(); }
    inline void program(const qint8 val)                        { m_program = val; emit programChanged(); }
    inline void volume(const qint8 val)                         { m_volume = val; emit volumeChanged(); }
    inline void balance(const qint8 val)                        { m_balance = val; emit balanceChanged(); }
    inline void chorus(const qint8 val)                         { m_chorus = val; emit chorusChanged(); }
    inline void reverb(const qint8 val)                         { m_reverb = val; emit reverbChanged(); }
    inline void phaser(const qint8 val)                         { m_phaser = val; emit phaserChanged(); }
    inline void tremolo(const qint8 val)                        { m_tremolo = val; emit tremoloChanged(); }
    inline void name(const QString &val)                        { m_name = val; emit nameChanged(); }
    inline void parameters(const QList<CChannelParameter> &val) { m_parameters = val; emit parametersChanged(); }

    inline quint16                  parametersCount()                                      const { return m_parameters.count(); }
    inline const CChannelParameter& parameter(const quint16 index)                         const { return m_parameters[index]; }
    inline CChannelParameter&       parameter(const quint16 index)                               { return m_parameters[index]; }
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
    qint8                    m_bank;
    qint8                    m_program;
    qint8                    m_volume;
    qint8                    m_balance;
    qint8                    m_chorus;
    qint8                    m_reverb;
    qint8                    m_phaser;
    qint8                    m_tremolo;
    QString                  m_name;
    QList<CChannelParameter> m_parameters;
};

#endif // CCHANNEL_H
