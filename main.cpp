/**
 * @file    main.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Main module
 *
 */

#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"

#include "src/common/common.h"

using namespace Common;

#include "src/ctab.h"
#include "src/graphics/psongview.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    log_notice("Init rTab v%1", PROJECT_VERSION);

    QCoreApplication::setOrganizationName("Rabits");
    QCoreApplication::setOrganizationDomain("rabits.ru");
    QCoreApplication::setApplicationName("rtab");
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);

    try {
        QScopedPointer<QApplication> app(createApplication(argc, argv));

        PSongView::exportGraphic();

        QmlApplicationViewer viewer;

        log_info("Creating context");
        CTab::i()->initContext(viewer, &app);

        log_info("Loading qml");
        viewer.setSource(QUrl("qrc:/qml/main.qml"));

        CTab::i()->initRoot(viewer);

        log_notice("Init done, starting");

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
