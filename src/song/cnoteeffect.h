#ifndef CNOTEEFFECT_H
#define CNOTEEFFECT_H

#include "src/common/common.h"

#include <QObject>

#include "effect/ceffectbend.h"
#include "effect/ceffectgrace.h"
#include "effect/ceffecthormonic.h"
#include "effect/ceffecttremolobar.h"
#include "effect/ceffecttrill.h"
#include "effect/ceffecttremolopicking.h"

class CNoteEffect
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CEffectBend*           bend READ bend WRITE bend NOTIFY bendChanged)
    Q_PROPERTY(CEffectTremoloBar*     tremoloBar READ tremoloBar WRITE tremoloBar NOTIFY tremoloBarChanged)
    Q_PROPERTY(CEffectHormonic*       harmonic READ harmonic WRITE harmonic NOTIFY harmonicChanged)
    Q_PROPERTY(CEffectGrace*          grace READ grace WRITE grace NOTIFY graceChanged)
    Q_PROPERTY(CEffectTrill*          trill READ trill WRITE trill NOTIFY trillChanged)
    Q_PROPERTY(CEffectTremoloPicking* tremoloPicking READ tremoloPicking WRITE tremoloPicking NOTIFY tremoloPickingChanged)

    Q_PROPERTY(bool vibrato READ vibrato WRITE vibrato NOTIFY vibratoChanged)
    Q_PROPERTY(bool dead READ dead WRITE dead NOTIFY deadChanged)
    Q_PROPERTY(bool slide READ slide WRITE slide NOTIFY slideChanged)
    Q_PROPERTY(bool hammer READ hammer WRITE hammer NOTIFY hammerChanged)
    Q_PROPERTY(bool ghost READ ghost WRITE ghost NOTIFY ghostChanged)
    Q_PROPERTY(bool accentuated READ accentuated WRITE accentuated NOTIFY accentuatedChanged)
    Q_PROPERTY(bool heavyAccentuated READ heavyAccentuated WRITE heavyAccentuated NOTIFY heavyAccentuatedChanged)
    Q_PROPERTY(bool palmMute READ palmMute WRITE palmMute NOTIFY palmMuteChanged)
    Q_PROPERTY(bool staccato READ staccato WRITE staccato NOTIFY staccatoChanged)
    Q_PROPERTY(bool tapping READ tapping WRITE tapping NOTIFY tappingChanged)
    Q_PROPERTY(bool slapping READ slapping WRITE slapping NOTIFY slappingChanged)
    Q_PROPERTY(bool popping READ popping WRITE popping NOTIFY poppingChanged)
    Q_PROPERTY(bool fadeIn READ fadeIn WRITE fadeIn NOTIFY fadeInChanged)
    Q_PROPERTY(bool letRing READ letRing WRITE letRing NOTIFY letRingChanged)

public:
    explicit CNoteEffect(QObject *parent = 0);
    CNoteEffect(const CNoteEffect &obj);
    CNoteEffect& operator=(const CNoteEffect &obj);

    inline bool operator==(const CNoteEffect &obj) const { obj.isBend(); return false; }  // TODO: Implement

    ~CNoteEffect();

    // ---API--- //
    inline CEffectBend*           bend()           const { return p_bend; }
    inline CEffectTremoloBar*     tremoloBar()     const { return p_tremoloBar; }
    inline CEffectHormonic*       harmonic()       const { return p_harmonic; }
    inline CEffectGrace*          grace()          const { return p_grace; }
    inline CEffectTrill*          trill()          const { return p_trill; }
    inline CEffectTremoloPicking* tremoloPicking() const { return p_tremoloPicking; }
    inline bool vibrato()          const { return m_vibrato; }
    inline bool dead()             const { return m_dead; }
    inline bool slide()            const { return m_slide; }
    inline bool hammer()           const { return m_hammer; }
    inline bool ghost()            const { return m_ghost; }
    inline bool accentuated()      const { return m_accentuated; }
    inline bool heavyAccentuated() const { return m_heavyAccentuated; }
    inline bool palmMute()         const { return m_palmMute; }
    inline bool staccato()         const { return m_staccato; }
    inline bool tapping()          const { return m_tapping; }
    inline bool slapping()         const { return m_slapping; }
    inline bool popping()          const { return m_popping; }
    inline bool fadeIn()           const { return m_fadeIn; }
    inline bool letRing()          const { return m_letRing; }

    void bend(const CEffectBend *val);
    void tremoloBar(const CEffectTremoloBar *val);
    void harmonic(const CEffectHormonic *val);
    void grace(const CEffectGrace *val);
    void trill(const CEffectTrill *val);
    void tremoloPicking(const CEffectTremoloPicking *val);
    void vibrato(const bool val);
    void dead(const bool val);
    void slide(const bool val);
    void hammer(const bool val);
    void ghost(const bool val);
    void accentuated(const bool val);
    void heavyAccentuated(const bool val);
    void palmMute(const bool val);
    void staccato(const bool val);
    void tapping(const bool val);
    void slapping(const bool val);
    void popping(const bool val);
    void fadeIn(const bool val);
    void letRing(const bool val);

    inline bool isBend()           const { if( bend() != NULL ) return ! bend()->points().isEmpty(); return false; }
    inline bool isTremoloBar()     const { return tremoloBar() != NULL; }
    inline bool isHarmonic()       const { return harmonic() != NULL; }
    inline bool isGrace()          const { return grace() != NULL; }
    inline bool isTrill()          const { return trill() != NULL; }
    inline bool isTremoloPicking() const { return tremoloPicking() != NULL; }

    inline bool hasAnyEffect() const { return (isBend() || isTremoloBar() || isHarmonic() || isGrace() || isTrill() || isTremoloPicking()
                                         || vibrato() || dead() || slide() || hammer() || ghost() || accentuated() || heavyAccentuated()
                                         || palmMute() || letRing() || staccato() || tapping() || slapping() || popping() || fadeIn()); }

signals:
    void bendChanged();
    void tremoloBarChanged();
    void harmonicChanged();
    void graceChanged();
    void trillChanged();
    void tremoloPickingChanged();
    void vibratoChanged();
    void deadChanged();
    void slideChanged();
    void hammerChanged();
    void ghostChanged();
    void accentuatedChanged();
    void heavyAccentuatedChanged();
    void palmMuteChanged();
    void staccatoChanged();
    void tappingChanged();
    void slappingChanged();
    void poppingChanged();
    void fadeInChanged();
    void letRingChanged();

private:
    CEffectBend           *p_bend;
    CEffectTremoloBar     *p_tremoloBar;
    CEffectHormonic       *p_harmonic;
    CEffectGrace          *p_grace;
    CEffectTrill          *p_trill;
    CEffectTremoloPicking *p_tremoloPicking;
    bool m_vibrato;
    bool m_dead;
    bool m_slide;
    bool m_hammer;
    bool m_ghost;
    bool m_accentuated;
    bool m_heavyAccentuated;
    bool m_palmMute;
    bool m_staccato;
    bool m_tapping;
    bool m_slapping;
    bool m_popping;
    bool m_fadeIn;
    bool m_letRing;
};

#endif // CNOTEEFFECT_H
