#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"

#include "src/ctab.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Rabits");
    QCoreApplication::setOrganizationDomain("rabits.ru");
    QCoreApplication::setApplicationName("rtab");
    QCoreApplication::setApplicationVersion("0.0.1");

    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;

    CTab::getInstance()->initContext(viewer);

    viewer.setMainQmlFile(QLatin1String("qml/rtab/main.qml"));

    CTab::getInstance()->initRoot(viewer);

    viewer.showExpanded();
    return app->exec();
}
