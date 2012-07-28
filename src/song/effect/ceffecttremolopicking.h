/**
 * @file    ceffecttremolopicking.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Effect - Tremolo Picking
 *
 */

#ifndef CEFFECTTREMOLOPICKING_H
#define CEFFECTTREMOLOPICKING_H

#include <QObject>

#include "../cduration.h"

class CEffectTremoloPicking
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CDuration duration READ duration WRITE duration NOTIFY durationChanged)

public:
    explicit CEffectTremoloPicking(QObject *parent = 0);
    CEffectTremoloPicking(const CEffectTremoloPicking &obj);
    CEffectTremoloPicking& operator=(const CEffectTremoloPicking &obj);

    // ---API--- //
    inline const CDuration& duration()       const { return m_duration; }
    inline CDuration&       duration()             { return m_duration; }

    inline void duration(const CDuration &val) { m_duration = val; emit durationChanged(); }

signals:
    void durationChanged();

private:
    CDuration m_duration;
};

#endif // CEFFECTTREMOLOPICKING_H
