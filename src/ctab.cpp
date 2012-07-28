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

#include "io/base/cfilemgr.h"
#include <QFile>

CTab* CTab::sp_instance = NULL;

CTab::CTab(QObject *parent)
    : QObject(parent)
    , m_settings()
{
    // Set default settings
    log_info("Init engine");
}

void CTab::initContext(QmlApplicationViewer &viewer)
{
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);

    m_context = viewer.rootContext();

    m_context->setContextProperty("CTab", this);
}

void CTab::initRoot(QmlApplicationViewer &viewer)
{
    m_root_object = viewer.rootObject();
}

QVariant CTab::setting(QString key, QString value)
{
    if( ! value.isEmpty() )
        m_settings.setValue(key, value);

    return m_settings.value(key);
}

CSong* CTab::songOpen(QString file_path)
{
    log_notice("Start loading file '%1'", file_path);

    QFile file(file_path);
    QDataStream *stream = new QDataStream(&file);

    try {
        CSong *song = CFileMgr::i()->load(stream);
        if( song != NULL )
        {
            songAdd(song);
            log_info("File loading completed '%1'", file_path);
        }
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
