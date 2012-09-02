/**
 * @file    psongview.h
 * @date    2012-08-12T18:14:00+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   SongView - song viewer
 *
 */

#ifndef PSONGVIEW_H
#define PSONGVIEW_H

#include "pbasic.h"

#include "../song/csong.h"

class PSongView
    : public PBasic
{
    Q_OBJECT
    Q_PROPERTY(CSong* song     READ song WRITE song NOTIFY songChanged)

public:
    explicit PSongView(QDeclarativeItem *parent = 0);

    // --API--- //
    inline CSong* song()   const { return m_song; }

    inline void song(CSong *val)  { if( m_song == val ) return; m_song = val; emit songChanged(); emit update(); }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *opts, QWidget *);

    inline static void exportGraphic()
    {
        qmlRegisterType<PSongView>("RTab", 1, 0, "RSongView");
    }

signals:
    void songChanged();

protected:
    CSong *m_song;
};

#endif // PSONGVIEW_H
