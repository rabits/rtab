#ifndef CTAB_H
#define CTAB_H

#include "src/common/common.h"

#include <QObject>
#include <QSettings>
#include <QtDeclarative/QDeclarativeContext>
#include <QGraphicsObject>
#include <qplatformdefs.h> // MEEGO_EDITION_HARMATTAN

#include "qmlapplicationviewer.h"

#include "song/csong.h"

class CTab : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<CSong> songs READ songs WRITE songs NOTIFY songsChanged)

public:
    inline static CTab* getInstance() { if( s_pInstance == NULL ) s_pInstance = new CTab(); return s_pInstance; }
    inline static void  destroyInstance() { delete s_pInstance; }

    void initContext(QmlApplicationViewer &viewer);
    void initRoot(QmlApplicationViewer &viewer);

    Q_INVOKABLE inline QSettings* settings() { return &m_settings; }
    Q_INVOKABLE QVariant setting(QString key, QString value = "");

    // --API--- //
    inline const QList<CSong>& songs()                  { return m_songs; }
    inline void                songs(QList<CSong> &val) { m_songs = val; emit songsChanged(); }

    inline uint         songsCount()                       { return m_songs.count(); }
    inline const CSong& song(uint index)                   { return m_songs[index]; }
    inline void         song(uint index, CSong &val)       { m_songs[index] = val; emit songsChanged(); }
    inline void         songAdd(CSong &val)                { m_songs.append(val); emit songsChanged(); }
    inline void         songRemove(uint index, CSong &val) { m_songs[index] = val; emit songsChanged(); }

signals:
    void songsChanged();

private:
    explicit CTab(QObject *parent = 0);

    static CTab* s_pInstance;

    QGraphicsObject*     m_root_object;
    QDeclarativeContext* m_context;

    QSettings   m_settings;

    QList<CSong> m_songs;
};

#endif // CTAB_H
