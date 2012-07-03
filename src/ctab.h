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
    Q_PROPERTY(QList<CSong*> songs READ songs WRITE songs NOTIFY songsChanged)

public:
    inline static CTab* i()               { if( sp_instance == NULL ) sp_instance = new CTab(); return sp_instance; }
    inline static void  destroyInstance() { delete sp_instance; }

    void initContext(QmlApplicationViewer &viewer);
    void initRoot(QmlApplicationViewer &viewer);

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

    Q_INVOKABLE CSong* songOpen(QString file_path);
    Q_INVOKABLE void   songSave(QString file_path);
    Q_INVOKABLE void   songClose(CSong *song);

signals:
    void songsChanged();

private:
    explicit CTab(QObject *parent = 0);

    static CTab* sp_instance;

    QGraphicsObject*     m_root_object;
    QDeclarativeContext* m_context;

    QSettings     m_settings;

    QList<CSong*> m_songs;
};

#endif // CTAB_H
