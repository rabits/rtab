# Version
VERSION='0.0.1'
VERSTR='\\"$${VERSION}\\"'
DEFINES += PROJECT_VERSION=\"$${VERSTR}\"

# Debug on debug
debug {
    DEFINES += CONFIG_DEBUG
    message("DEBUG MODE ON")
}

release: message("DEBUG MODE OFF")

debug: release: error("debug release builds is not supported. Add to release build 'CONFIG-=debug' and to debug build 'CONFIG-=release' $${CONFIG}")

QMAKE_CXXFLAGS += -std=c++0x

# Add more folders to ship with the application, here
folder_01.source = qml/rtab
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE32B673B

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
CONFIG += qdeclarative-boostable

# Add dependency to Symbian components
# CONFIG += qt-components

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    src/ctab.cpp \
    src/tabulature/ctabulature.cpp \
    src/song/csong.cpp \
    src/song/ctrack.cpp \
    src/song/cmeasureheader.cpp \
    src/song/cchannel.cpp \
    src/song/cmeasure.cpp \
    src/song/cstring.cpp \
    src/song/cbeat.cpp \
    src/song/cchannelparameter.cpp \
    src/song/cchord.cpp \
    src/song/cdivisiontype.cpp \
    src/song/cduration.cpp \
    src/song/cmarker.cpp \
    src/song/cnoteeffect.cpp \
    src/song/cnote.cpp \
    src/song/cscale.cpp \
    src/song/cstroke.cpp \
    src/song/ctempo.cpp \
    src/song/ctext.cpp \
    src/song/ctimesignature.cpp \
    src/song/cvoice.cpp \
    src/common/cexception.cpp \
    src/common/clog.cpp \
    src/song/effect/ceffectbend.cpp \
    src/song/effect/ceffecttremolobar.cpp \
    src/song/effect/ceffecthormonic.cpp \
    src/song/effect/ceffectgrace.cpp \
    src/song/effect/ceffecttrill.cpp \
    src/song/effect/ceffecttremolopicking.cpp \
    src/song/effect/cpoint.cpp \
    src/song/clyrics.cpp \
    src/io/base/cfilemgr.cpp \
    src/io/tg/cstream.cpp \
    src/io/tg/cinputstream.cpp \
    src/io/tg/coutputstream.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qml/rtab/main.qml

HEADERS += \
    src/ctab.h \
    src/tabulature/ctabulature.h \
    src/song/csong.h \
    src/song/ctrack.h \
    src/song/cmeasureheader.h \
    src/song/cchannel.h \
    src/song/cmeasure.h \
    src/song/cstring.h \
    src/song/cbeat.h \
    src/song/cchannelparameter.h \
    src/song/cchord.h \
    src/song/cdivisiontype.h \
    src/song/cduration.h \
    src/song/cmarker.h \
    src/song/cnoteeffect.h \
    src/song/cnote.h \
    src/song/cscale.h \
    src/song/cstroke.h \
    src/song/ctempo.h \
    src/song/ctext.h \
    src/song/ctimesignature.h \
    src/song/cvelocities.h \
    src/song/cvoice.h \
    src/common/cexception.h \
    src/common/clog.h \
    src/common/common.h \
    src/song/effect/ceffectbend.h \
    src/song/effect/ceffecttremolobar.h \
    src/song/effect/ceffecthormonic.h \
    src/song/effect/ceffectgrace.h \
    src/song/effect/ceffecttrill.h \
    src/song/effect/ceffecttremolopicking.h \
    src/song/effect/cpoint.h \
    src/song/clyrics.h \
    src/io/base/cfileformat.h \
    src/io/base/cinputstreambase.h \
    src/io/base/coutputstreambase.h \
    src/io/base/cfilemgr.h \
    src/io/tg/cstream.h \
    src/io/tg/cinputstream.h \
    src/io/tg/coutputstream.h
