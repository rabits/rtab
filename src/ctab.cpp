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
    try {
        QFile file(file_path);
        CSong *song = CFileMgr::i()->load(new QDataStream(&file));
        if( song != NULL )
            songAdd(song);
        return song;
    }
    catch( Common::CException const &e ) {
        log_error("Can't load file '%s': %s", file_path.toStdString().c_str(), e.what());
    }

    return NULL;
}

void CTab::songSave(QString file_path)
{
}

void CTab::songClose(CSong *song)
{
    songRemove(song);
}
