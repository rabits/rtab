/**
 * @file    cscale.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Scale
 *
 */

#ifndef CSCALE_H
#define CSCALE_H

#include "src/common/common.h"

#include <QObject>

class CScale
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint8 key READ key WRITE key NOTIFY keyChanged)

public:
    explicit CScale(QObject *parent = 0);

    // ---API--- //
    inline qint8 key() const { return m_key; }

    inline void key(const qint8 val) { m_key = val; emit keyChanged(); }

    inline bool note(const quint8 note)          const { return m_notes[((note + (12 - key())) % 12)]; }
    inline void note(const quint8 note, const qint8 val) { if( note < 12 ) { m_notes[note] = val; emit notesChanged(); } }

    void clear();

signals:
    void keyChanged();
    void notesChanged();

private:
    qint8 m_key;
    bool  m_notes[12];
};

#endif // CSCALE_H
