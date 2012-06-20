#ifndef CMEASUREHEADER_H
#define CMEASUREHEADER_H

#include "src/common/common.h"

#include <QObject>

#include "ctimesignature.h"
#include "ctempo.h"
#include "cmarker.h"

class CSong;

class CMeasureHeader
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int            number READ number WRITE number NOTIFY numberChanged)
    Q_PROPERTY(long           start READ start WRITE start NOTIFY startChanged)
    Q_PROPERTY(CTimeSignature timeSignature READ timeSignature WRITE timeSignature NOTIFY timeSignatureChanged)
    Q_PROPERTY(CTempo         tempo READ tempo WRITE tempo NOTIFY tempoChanged)
    Q_PROPERTY(bool           repeatOpen READ repeatOpen WRITE repeatOpen NOTIFY repeatOpenChanged)
    Q_PROPERTY(int            repeatAlternative READ repeatAlternative WRITE repeatAlternative NOTIFY repeatAlternativeChanged)
    Q_PROPERTY(int            repeatClose READ repeatClose WRITE repeatClose NOTIFY repeatCloseChanged)
    Q_PROPERTY(int            tripletFeel READ tripletFeel WRITE tripletFeel NOTIFY tripletFeelChanged)
    Q_PROPERTY(CMarker*       marker READ marker WRITE marker NOTIFY markerChanged)
    Q_PROPERTY(CSong*         song READ song WRITE song NOTIFY songChanged)

public:
    explicit CMeasureHeader(QObject *parent = 0);
    CMeasureHeader(const CMeasureHeader &obj);
    CMeasureHeader& operator=(const CMeasureHeader &obj);

    inline bool operator==(const CMeasureHeader &obj) const { return start() == obj.start() && timeSignature() == obj.timeSignature() && tempo() == obj.tempo()
                                                                        && repeatOpen() == obj.repeatOpen() && repeatAlternative() == obj.repeatAlternative()
                                                                        && repeatClose() == obj.repeatClose() && tripletFeel() == obj.tripletFeel()
                                                                        && ((marker() != NULL) && (obj.marker() != NULL) )? *marker() == *obj.marker() : marker() == obj.marker(); }

    enum TRIPLET {
        TRIPLET_FEEL_NONE    = 1,
        TRIPLET_FEEL_EIGHT   = 2,
        TRIPLET_FEEL_SIXTEEN = 3
    };

    // ---API--- //
    inline int                   number()            const { return m_number; }
    inline long                  start()             const { return m_start; }
    inline const CTimeSignature& timeSignature()     const { return m_timeSignature; }
    inline const CTempo&         tempo()             const { return m_tempo; }
    inline bool                  repeatOpen()        const { return m_repeatOpen; }
    inline int                   repeatAlternative() const { return m_repeatAlternative; }
    inline int                   repeatClose()       const { return m_repeatClose; }
    inline int                   tripletFeel()       const { return m_tripletFeel; }
    inline CMarker*              marker()            const { return p_marker; }
    inline CSong*                song()              const { return p_song; }

    inline void number(const int val)                    { m_number = val; emit numberChanged(); }
    inline void start(const long val)                    { m_start = val; emit startChanged(); }
    inline void timeSignature(const CTimeSignature &val) { m_timeSignature = val; emit timeSignatureChanged(); }
    inline void tempo(const CTempo &val)                 { m_tempo = val; emit tempoChanged(); }
    inline void repeatOpen(const bool val)               { m_repeatOpen = val; emit repeatOpenChanged(); }
    inline void repeatAlternative(const int val)         { m_repeatAlternative = val; emit repeatAlternativeChanged(); }
    inline void repeatClose(const int val)               { m_repeatClose = val; emit repeatCloseChanged(); }
    inline void tripletFeel(const int val)               { m_tripletFeel = val; emit tripletFeelChanged(); }
    inline void marker(const CMarker *val)               { delete p_marker; if( val != NULL ) p_marker = new CMarker(*val); markerCheck(); emit markerChanged(); }
    inline void song(CSong *val)                         { p_song = val; emit songChanged(); }

    inline bool markerHas()    const { return p_marker != NULL; }
    inline void markerCheck()  const { if( markerHas() ) p_marker->measure(number()); }
    inline void markerRemove() const { delete p_marker; }

signals:
    void numberChanged();
    void startChanged();
    void timeSignatureChanged();
    void tempoChanged();
    void repeatOpenChanged();
    void repeatAlternativeChanged();
    void repeatCloseChanged();
    void tripletFeelChanged();
    void markerChanged();
    void songChanged();

private:
    int            m_number;
    long           m_start;
    CTimeSignature m_timeSignature;
    CTempo         m_tempo;
    bool           m_repeatOpen;
    int            m_repeatAlternative;
    int            m_repeatClose;
    int            m_tripletFeel;
    CMarker       *p_marker;
    CSong         *p_song;
};

#endif // CMEASUREHEADER_H
