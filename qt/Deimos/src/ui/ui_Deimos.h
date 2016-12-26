#ifndef UI_DEIMOS_H
#define UI_DEIMOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

class Ui_Deimos
{
public:
    QAction *newConfig;
    QAction *loadConfig;
    QAction *saveConfig;
    QAction *saveConfigAs;
    QAction *exitDeimos;
    QAction *aboutDeimos;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QTreeWidget *softList;
    QTreeWidget *keyList;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Deimos)
    {
    Deimos->setObjectName(QString::fromUtf8("Deimos"));
    Deimos->resize(QSize(675, 531).expandedTo(Deimos->minimumSizeHint()));
    Deimos->setWindowIcon(QIcon(QString::fromUtf8(":/deimos.png")));
    newConfig = new QAction(Deimos);
    newConfig->setObjectName(QString::fromUtf8("newConfig"));
    loadConfig = new QAction(Deimos);
    loadConfig->setObjectName(QString::fromUtf8("loadConfig"));
    saveConfig = new QAction(Deimos);
    saveConfig->setObjectName(QString::fromUtf8("saveConfig"));
    saveConfigAs = new QAction(Deimos);
    saveConfigAs->setObjectName(QString::fromUtf8("saveConfigAs"));
    exitDeimos = new QAction(Deimos);
    exitDeimos->setObjectName(QString::fromUtf8("exitDeimos"));
    aboutDeimos = new QAction(Deimos);
    aboutDeimos->setObjectName(QString::fromUtf8("aboutDeimos"));
    centralwidget = new QWidget(Deimos);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    softList = new QTreeWidget(centralwidget);
    softList->setObjectName(QString::fromUtf8("softList"));
    softList->setMaximumSize(QSize(150, 16777215));

    hboxLayout->addWidget(softList);

    keyList = new QTreeWidget(centralwidget);
    keyList->setObjectName(QString::fromUtf8("keyList"));

    hboxLayout->addWidget(keyList);


    gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

    Deimos->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Deimos);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 675, 19));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    Deimos->setMenuBar(menubar);
    statusbar = new QStatusBar(Deimos);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    Deimos->setStatusBar(statusbar);

    menubar->addAction(menuFile->menuAction());
    menuFile->addAction(newConfig);
    menuFile->addAction(loadConfig);
    menuFile->addAction(saveConfig);
    menuFile->addAction(saveConfigAs);
    menuFile->addSeparator();
    menuFile->addAction(exitDeimos);
    retranslateUi(Deimos);

    QMetaObject::connectSlotsByName(Deimos);
    } // setupUi

    void retranslateUi(QMainWindow *Deimos)
    {
    Deimos->setWindowTitle(QApplication::translate("Deimos", "Deimos", 0, QApplication::UnicodeUTF8));
    newConfig->setText(QApplication::translate("Deimos", "&New configuration", 0, QApplication::UnicodeUTF8));
    loadConfig->setText(QApplication::translate("Deimos", "&Load", 0, QApplication::UnicodeUTF8));
    saveConfig->setText(QApplication::translate("Deimos", "&Save", 0, QApplication::UnicodeUTF8));
    saveConfigAs->setText(QApplication::translate("Deimos", "Save &as...", 0, QApplication::UnicodeUTF8));
    exitDeimos->setText(QApplication::translate("Deimos", "E&xit", 0, QApplication::UnicodeUTF8));
    aboutDeimos->setText(QApplication::translate("Deimos", "&About", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("Deimos", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Deimos: public Ui_Deimos {};
} // namespace Ui

#endif // UI_DEIMOS_H
