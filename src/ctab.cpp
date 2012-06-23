#include "ctab.h"

#include "io/base/cfilemgr.h"
#include <QFile>

CTab::CTab(QObject *parent)
    : QObject(parent)
    , m_settings()
{
    // Set default settings
    log_notice("Init engine");
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

    QFile file("/home/psa/Projects/rtab/tmp/Untitled.tg");
    CFileMgr::i()->load(new QDataStream(&file));
}

QVariant CTab::setting(QString key, QString value)
{
    if( ! value.isEmpty() )
        m_settings.setValue(key, value);

    return m_settings.value(key);
}

CTab* CTab::s_pInstance = NULL;
