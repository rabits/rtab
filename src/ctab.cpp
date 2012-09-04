/**
 * @file    ctab.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   rTab main object
 *
 */

#include "ctab.h"

#include <QtOpenGL/QGLWidget>

#include "io/base/cfilemgr.h"
#include <QFile>
#include <QLocale>
#include <QDesktopWidget>
#include <QDir>
#include <qmath.h>

CTab* CTab::sp_instance = NULL;

CTab::CTab(QObject *parent)
    : QObject(parent)
    , m_settings()
{
    // Set default settings
    log_info("Init engine");

    if( m_settings.value("preferences/locale").isNull() )
        m_settings.setValue("preferences/locale", QLocale::system().name());

    if( m_settings.value("preferences/last_folder").isNull() )
        m_settings.setValue("preferences/last_folder", QString(QDir::homePath()));

    if( m_settings.value("preferences/file_history_max_count").isNull() )
        m_settings.setValue("preferences/file_history_max_count", 10);

    if( m_settings.value("preferences/device").isNull() )
#if defined(Q_OS_SYMBIAN) || defined(MEEGO_EDITION_HARMATTAN) || defined(Q_WS_SIMULATOR) || defined(Q_WS_S60) || defined(Q_WS_MAEMO)
        m_settings.setValue("preferences/device_screen", "small");
#else
        m_settings.setValue("preferences/device_screen", "big");
#endif
    fileHistoryLoad();
}

CTab::~CTab()
{
    log_notice("Destroying rTab v%1", PROJECT_VERSION);
}

void CTab::initContext(QmlApplicationViewer &viewer, QScopedPointer<QApplication> *app)
{
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers | QGL::AlphaChannel)));

    m_context = viewer.rootContext();

    m_context->setContextProperty("ctab", this);

    m_app = app;
    changeLocale(setting("preferences/locale").toString());
    (*m_app)->installTranslator(&m_translator);
}

void CTab::changeLocale(QString locale)
{
    log_notice("Changing locale to %1", locale);
    if( ! m_translator.load("tr_" + locale, ":/") )
    {
        m_translator.load("tr_en", ":/");
        setting("preferences/locale", "en");
    }
}

void CTab::initRoot(QmlApplicationViewer &viewer)
{
    m_root_object = viewer.rootObject();
}

QVariant CTab::setting(QString key, QString value)
{
    if( ! value.isEmpty() )
    {
        log_debug("Set setting %1 = %2", key, value);
        m_settings.setValue(key, value);
    }

    return m_settings.value(key);
}

void CTab::fileHistoryAdd(const QString val)
{
    m_file_history.removeOne(val);
    m_file_history.prepend(val);
    fileHistorySave();
    emit fileHistoryChanged();
}

void CTab::fileHistorySave()
{
    log_debug("Saving history");
    quint16 count = setting("preferences/file_history_max_count").toInt();
    if( fileHistoryCount() > count )
    {
        m_file_history.removeLast();
        emit fileHistoryChanged();
    }

    m_settings.beginWriteArray("file_history/song", count);
    for( quint16 i = 0; i < count; i++ )
    {
        if( i >= fileHistoryCount() )
            break;
        m_settings.setArrayIndex(i);
        m_settings.setValue("path", fileHistory(i));
    }
    m_settings.endArray();
}

void CTab::fileHistoryLoad()
{
    log_debug("Loading history");
    m_file_history.clear();

    quint16 count = m_settings.beginReadArray("file_history/song");
    for( quint16 i = 0; i < count; i++ )
    {
        m_settings.setArrayIndex(i);
        m_file_history.append(m_settings.value("path").toString());
    }
    m_settings.endArray();

    emit fileHistoryChanged();
}

CSong* CTab::songOpen(QString file_path)
{
    log_notice("Begin loading file '%1'", file_path);

    QFile file(file_path);
    QDataStream *stream = NULL;

    try {
        if( ! file.exists() )
            throw EXCEPTION(log_error("File is not exists"));

        stream = new QDataStream(&file);
        CSong *song = CFileMgr::i()->load(stream);

        if( song == NULL )
            throw EXCEPTION(log_error("Song can't be created"));

        song = songAdd(song);
        log_info("File loading completed '%1'", file_path);
        fileHistoryAdd(file_path);

        return song;
    }
    catch( Common::CException const &e ) {
        log_error("Can't load file '%1': %2", file_path, e.fullDescription());
    }

    delete stream;
    file.close();

    return NULL;
}

void CTab::songSave(QString file_path)
{
}

void CTab::songClose(CSong *song)
{
    songRemove(song);
}
