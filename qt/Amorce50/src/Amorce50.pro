UI_DIR  = ui
QT      += xml sql
DESTDIR = ../bin
CONFIG += qt warn_on static
RESOURCES = ressources.qrc

win32 {
    RC_FILE = icon.rc
}

HEADERS	=   Amorce50.h \
            Classes.h \
            defines.h \
            GrilleWindow.h \
            ParametresWindow.h \
            PointageWindow.h \
            Resultat.h \
            ResultWindow.h
        
FORMS   =   ui/About.ui \
            ui/CategoryEdit.ui \
            ui/DriverEdit.ui \
            ui/Grille.ui \
            ui/Main.ui \
            ui/Parametres.ui \
            ui/PilotesPresents.ui \
            ui/Pointage.ui \
            ui/PointsEdit.ui \
            ui/RaceEdit.ui \
            ui/Result.ui \
            ui/SeasonEdit.ui \
            ui/SousCat.ui

SOURCES	=   Amorce50.cpp \
            GrilleWindow.cpp \
            main.cpp \
            ParametresWindow.cpp \
            PointageWindow.cpp \
            Resultat.cpp \
            ResultWindow.cpp
