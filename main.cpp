#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"

#include "src/common/common.h"

using namespace Common;

#include "src/ctab.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    log_notice("Init rTab v%1", PROJECT_VERSION);

    QCoreApplication::setOrganizationName("Rabits");
    QCoreApplication::setOrganizationDomain("rabits.ru");
    QCoreApplication::setApplicationName("rtab");
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);

    try {
        QScopedPointer<QApplication> app(createApplication(argc, argv));

        QmlApplicationViewer viewer;

        CTab::i()->initContext(viewer);

        viewer.setMainQmlFile(QLatin1String("qml/rtab/main.qml"));

        CTab::i()->initRoot(viewer);

        log_notice("Init done, starting");

        CTab::i()->songOpen("/home/psa/Projects/rtab/tmp/test02.tg");
        CTab::i()->songOpen("/home/psa/Projects/rtab/tmp/test03.tg");

        viewer.showExpanded();
        return app->exec();
    }
    catch( Common::CException const &e ) {
        log_emerg("An unhandled exception has occured: %1", e.what());
    }
    catch(...) {
        log_emerg("An unknown exception has occured!");
    }

    log_emerg("Abnormally exiting...");

    return 1;
}
