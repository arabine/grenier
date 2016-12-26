UI_DIR  = ../src/ui
QT      += xml network
DESTDIR = ../bin
CONFIG += qt warn_on windows
RESOURCES = ../src/res/deimos.qrc


win32 {
    LIBS += Gdi32.lib User32.lib shell32.lib
    RC_FILE = icon.rc
}

HEADERS	= ../src/Classes.h \
        ../src/DeimosEvent.h \
        ../src/DeimosWindow.h \
        ../src/PluginsManager.h \
        ../src/SerialPort.h \
        ../src/UIRDevice.h \
        ../src/NewSoft.h \
        ../src/Classes.h \
        ../src/trayicon/trayicon.h
        
FORMS   = ../src/Deimos.ui \
        ../src/NewApplication.ui \
        ../src/TestDevice.ui \
        ../src/RemoteWindow.ui


SOURCES	= ../src/DeimosEvent.cpp \
        ../src/DeimosWindow.cpp \
        ../src/main.cpp \
        ../src/PluginsManager.cpp \
        ../src/SerialPort.cpp \
        ../src/UIRDevice.cpp \
        ../src/NewSoft.cpp \
        ../src/trayicon/trayicon_win.cpp \
        ../src/trayicon/trayicon.cpp
