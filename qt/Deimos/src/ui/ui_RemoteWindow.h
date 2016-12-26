#ifndef UI_REMOTEWINDOW_H
#define UI_REMOTEWINDOW_H

#include <Qt3Support/Q3Header>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "Qt3Support/Q3ListViewItemIterator"
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_RemoteWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *buttonHelp;
    QSpacerItem *spacerItem;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    Q3ListView *keystrokeList;
    QLabel *textLabel1;
    QVBoxLayout *vboxLayout;
    QLabel *textLabel2;
    QLineEdit *keyCode;
    QLabel *textLabel4;
    QLineEdit *deviceButton;
    QLabel *textLabel3;
    QLineEdit *description;

    void setupUi(QDialog *RemoteWindow)
    {
    RemoteWindow->setObjectName(QString::fromUtf8("RemoteWindow"));
    RemoteWindow->resize(QSize(510, 283).expandedTo(RemoteWindow->minimumSizeHint()));
    RemoteWindow->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(RemoteWindow);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    buttonHelp = new QPushButton(RemoteWindow);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
    buttonHelp->setAutoDefault(true);

    hboxLayout->addWidget(buttonHelp);

    spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    buttonOk = new QPushButton(RemoteWindow);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
    buttonOk->setAutoDefault(true);
    buttonOk->setDefault(true);

    hboxLayout->addWidget(buttonOk);

    buttonCancel = new QPushButton(RemoteWindow);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
    buttonCancel->setAutoDefault(true);

    hboxLayout->addWidget(buttonCancel);


    gridLayout->addLayout(hboxLayout, 2, 0, 1, 2);

    keystrokeList = new Q3ListView(RemoteWindow);
    keystrokeList->addColumn(QApplication::translate("RemoteWindow", "Keystroke", 0, QApplication::UnicodeUTF8));
    keystrokeList->setObjectName(QString::fromUtf8("keystrokeList"));
    keystrokeList->setResizeMode(Q3ListView::AllColumns);

    gridLayout->addWidget(keystrokeList, 1, 1, 1, 1);

    textLabel1 = new QLabel(RemoteWindow);
    textLabel1->setObjectName(QString::fromUtf8("textLabel1"));

    gridLayout->addWidget(textLabel1, 0, 0, 1, 2);

    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    textLabel2 = new QLabel(RemoteWindow);
    textLabel2->setObjectName(QString::fromUtf8("textLabel2"));

    vboxLayout->addWidget(textLabel2);

    keyCode = new QLineEdit(RemoteWindow);
    keyCode->setObjectName(QString::fromUtf8("keyCode"));
    keyCode->setEnabled(false);

    vboxLayout->addWidget(keyCode);

    textLabel4 = new QLabel(RemoteWindow);
    textLabel4->setObjectName(QString::fromUtf8("textLabel4"));

    vboxLayout->addWidget(textLabel4);

    deviceButton = new QLineEdit(RemoteWindow);
    deviceButton->setObjectName(QString::fromUtf8("deviceButton"));

    vboxLayout->addWidget(deviceButton);

    textLabel3 = new QLabel(RemoteWindow);
    textLabel3->setObjectName(QString::fromUtf8("textLabel3"));

    vboxLayout->addWidget(textLabel3);

    description = new QLineEdit(RemoteWindow);
    description->setObjectName(QString::fromUtf8("description"));

    vboxLayout->addWidget(description);


    gridLayout->addLayout(vboxLayout, 1, 0, 1, 1);

    retranslateUi(RemoteWindow);
    QObject::connect(buttonOk, SIGNAL(clicked()), RemoteWindow, SLOT(accept()));
    QObject::connect(buttonCancel, SIGNAL(clicked()), RemoteWindow, SLOT(reject()));

    QMetaObject::connectSlotsByName(RemoteWindow);
    } // setupUi

    void retranslateUi(QDialog *RemoteWindow)
    {
    RemoteWindow->setWindowTitle(QApplication::translate("RemoteWindow", "Qt- Deimos", 0, QApplication::UnicodeUTF8));
    buttonHelp->setText(QApplication::translate("RemoteWindow", "&Help", 0, QApplication::UnicodeUTF8));
    buttonHelp->setShortcut(QApplication::translate("RemoteWindow", "F1", 0, QApplication::UnicodeUTF8));
    buttonOk->setText(QApplication::translate("RemoteWindow", "&OK", 0, QApplication::UnicodeUTF8));
    buttonOk->setShortcut(QApplication::translate("RemoteWindow", "", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("RemoteWindow", "&Cancel", 0, QApplication::UnicodeUTF8));
    buttonCancel->setShortcut(QApplication::translate("RemoteWindow", "", 0, QApplication::UnicodeUTF8));
    keystrokeList->header()->setLabel(0, QApplication::translate("RemoteWindow", "Keystroke", 0, QApplication::UnicodeUTF8));
    textLabel1->setText(QApplication::translate("RemoteWindow", "<h1><b><p align=\"center\">Press a device button</p></b></h1>", 0, QApplication::UnicodeUTF8));
    textLabel2->setText(QApplication::translate("RemoteWindow", "Device key code :", 0, QApplication::UnicodeUTF8));
    textLabel4->setText(QApplication::translate("RemoteWindow", "Device button :", 0, QApplication::UnicodeUTF8));
    textLabel3->setText(QApplication::translate("RemoteWindow", "Description :", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(RemoteWindow);
    } // retranslateUi

};

namespace Ui {
    class RemoteWindow: public Ui_RemoteWindow {};
} // namespace Ui

#endif // UI_REMOTEWINDOW_H
