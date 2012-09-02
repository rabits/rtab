/**
 * @file    ctab.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   rTab basic object
 *
 */

#ifndef CTAB_H
#define CTAB_H

#include "src/common/common.h"

#include <QObject>
#include <QSettings>
#include <QtDeclarative/QDeclarativeContext>
#include <QGraphicsObject>
#include <qplatformdefs.h> // MEEGO_EDITION_HARMATTAN
#include <QTranslator>
#include <QApplication>

#include "qmlapplicationviewer.h"

#include "song/csong.h"

class CTab
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<CSong*> songs       READ songs WRITE songs NOTIFY songsChanged)
    Q_PROPERTY(QStringList   fileHistory READ fileHistory NOTIFY songsChanged)

public:
    inline static CTab* i()               { if( sp_instance == NULL ) sp_instance = new CTab(); return sp_instance; }
    inline static void  destroyInstance() { delete sp_instance; }

    void initContext(QmlApplicationViewer& viewer, QScopedPointer<QApplication> *app);
    void initRoot(QmlApplicationViewer &viewer);

    Q_INVOKABLE void changeLocale(QString locale);

    Q_INVOKABLE inline QSettings* settings() { return &m_settings; }
    Q_INVOKABLE QVariant setting(QString key, QString value = "");

    // --API--- //
    inline const QList<CSong*>& songs()                   { return m_songs; }
    inline void                 songs(QList<CSong*> &val) { m_songs = val; emit songsChanged(); }

    inline quint8       songsCount()           const { return m_songs.count(); }
    inline const CSong* song(quint8 index)     const { return m_songs[index]; }
    inline CSong*       song(quint8 index)           { return m_songs[index]; }
    inline void         songAdd(CSong *val)          { m_songs.append(val); emit songsChanged(); }
    inline void         songRemove(CSong *val)       { delete val; m_songs.removeOne(val); emit songsChanged(); }

    inline quint8            fileHistoryCount()          const { return m_file_history.count(); }
    inline const QStringList fileHistory()               const { return m_file_history; }
    inline const QString     fileHistory(quint8 index)   const { return m_file_history[index]; }
    inline void              fileHistoryAdd(const QString val);
    void                     fileHistorySave();
    void                     fileHistoryLoad();

    Q_INVOKABLE CSong* songOpen(QString file_path);
    Q_INVOKABLE void   songSave(QString file_path);
    Q_INVOKABLE void   songClose(CSong *song);

signals:
    void songsChanged();
    void fileHistoryChanged();

private:
    explicit CTab(QObject *parent = 0);

    static CTab* sp_instance;

    QGraphicsObject*     m_root_object;
    QDeclarativeContext* m_context;

    QSettings     m_settings;

    QTranslator                   m_translator;
    QScopedPointer<QApplication> *m_app;

    QList<CSong*> m_songs;
    QStringList   m_file_history;
};

#endif // CTAB_H
