#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"

#include "src/common/common.h"

using namespace Common;

#include <execinfo.h>
#include <signal.h>

/** @brief Stacktrace exception class for serious errors
 */
class CExceptionTracer
{
public:
    CExceptionTracer()
    {
        void * array[25];
        int nSize = backtrace(array, 25);
        char** symbols = backtrace_symbols(array, nSize);

        for (int i = 0; i < nSize; i++)
            std::cout << symbols[i] << std::endl;

        free(symbols);
    }
    virtual ~CExceptionTracer() throw() {}
};

/** @brief Template of SignalExceptions
 *
 */
template <class CSignalExceptionClass> class CSignalTranslator
{
private:
    class CSingleTonTranslator
    {
    public:
        CSingleTonTranslator()
        {
            signal(CSignalExceptionClass::GetSignalNumber(), SignalHandler);
        }

        static void SignalHandler(int)
        {
            throw CSignalExceptionClass();
        }
    };

public:
    CSignalTranslator()
    {
        static CSingleTonTranslator s_objTranslator;
    }
};

/** @brief SIGSEGV signal catcher
 */
class CSegmentationFault
    : public CExceptionTracer
    , public std::exception
{
public:
    static int GetSignalNumber() {return SIGSEGV;}
};

/** @brief SIGFPE signal catcher
 */
class CFloatingPointException
    : public CExceptionTracer
    , public std::exception
{
public:
    static int GetSignalNumber() {return SIGFPE;}
};

// Catching signals by exceptions
CSignalTranslator<CSegmentationFault> g_objSegmentationFaultTranslator;
CSignalTranslator<CFloatingPointException> g_objFloatingPointExceptionTranslator;

#include "src/ctab.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    log_notice("Init rTab v"PROJECT_VERSION);

    QCoreApplication::setOrganizationName("Rabits");
    QCoreApplication::setOrganizationDomain("rabits.ru");
    QCoreApplication::setApplicationName("rtab");
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);

    try {
        QScopedPointer<QApplication> app(createApplication(argc, argv));

        QmlApplicationViewer viewer;

        CTab::getInstance()->initContext(viewer);

        viewer.setMainQmlFile(QLatin1String("qml/rtab/main.qml"));

        CTab::getInstance()->initRoot(viewer);

        log_notice("Init done, starting");
        viewer.showExpanded();
        return app->exec();
    }
    catch( std::exception const &e ) {
        log_emerg("An unhandled exception has occured: %s", e.what());
    }
    catch(...) {
        log_emerg("An unknown exception has occured!");
    }

    log_notice("Abnormally exiting...");

    return 1;
}
