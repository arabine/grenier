/********************************************************************************
** Form generated from reading ui file 'PilotesPresents.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PILOTESPRESENTS_H
#define UI_PILOTESPRESENTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_PilotesPresents
{
public:
    QGridLayout *gridLayout;
    QListWidget *listePresents;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QLabel *textLabel1_2;
    QFrame *frame;
    QGridLayout *gridLayout1;
    QLabel *TextLabel1;

    void setupUi(QDialog *PilotesPresents)
    {
    PilotesPresents->setObjectName(QString::fromUtf8("PilotesPresents"));
    PilotesPresents->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(PilotesPresents);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    listePresents = new QListWidget(PilotesPresents);
    listePresents->setObjectName(QString::fromUtf8("listePresents"));

    gridLayout->addWidget(listePresents, 2, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    buttonOk = new QPushButton(PilotesPresents);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
    buttonOk->setAutoDefault(true);
    buttonOk->setDefault(true);

    hboxLayout->addWidget(buttonOk);

    buttonCancel = new QPushButton(PilotesPresents);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
    buttonCancel->setAutoDefault(true);

    hboxLayout->addWidget(buttonCancel);


    gridLayout->addLayout(hboxLayout, 3, 0, 1, 1);

    textLabel1_2 = new QLabel(PilotesPresents);
    textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
    textLabel1_2->setWordWrap(false);

    gridLayout->addWidget(textLabel1_2, 1, 0, 1, 1);

    frame = new QFrame(PilotesPresents);
    frame->setObjectName(QString::fromUtf8("frame"));
    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush);
    QBrush brush1(QColor(255, 255, 255, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    QBrush brush2(QColor(255, 255, 255, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
    QBrush brush3(QColor(255, 255, 255, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
    QBrush brush4(QColor(255, 255, 255, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
    QBrush brush5(QColor(255, 255, 255, 255));
    brush5.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
    frame->setPalette(palette);
    frame->setAutoFillBackground(true);
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Plain);
    gridLayout1 = new QGridLayout(frame);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    TextLabel1 = new QLabel(frame);
    TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
    TextLabel1->setSizePolicy(sizePolicy);
    TextLabel1->setMinimumSize(QSize(0, 0));
    TextLabel1->setMaximumSize(QSize(32767, 32767));
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    font.setWeight(75);
    TextLabel1->setFont(font);
    TextLabel1->setAlignment(Qt::AlignCenter);
    TextLabel1->setWordWrap(false);

    gridLayout1->addWidget(TextLabel1, 0, 0, 1, 1);


    gridLayout->addWidget(frame, 0, 0, 1, 1);


    retranslateUi(PilotesPresents);

    QSize size(336, 446);
    size = size.expandedTo(PilotesPresents->minimumSizeHint());
    PilotesPresents->resize(size);

    QObject::connect(buttonOk, SIGNAL(clicked()), PilotesPresents, SLOT(accept()));
    QObject::connect(buttonCancel, SIGNAL(clicked()), PilotesPresents, SLOT(reject()));

    QMetaObject::connectSlotsByName(PilotesPresents);
    } // setupUi

    void retranslateUi(QDialog *PilotesPresents)
    {
    PilotesPresents->setWindowTitle(QApplication::translate("PilotesPresents", "Qt - Pilotes pr\303\251sents", 0, QApplication::UnicodeUTF8));
    buttonOk->setText(QApplication::translate("PilotesPresents", "&OK", 0, QApplication::UnicodeUTF8));
    buttonOk->setShortcut(QString());
    buttonCancel->setText(QApplication::translate("PilotesPresents", "&Annuler", 0, QApplication::UnicodeUTF8));
    buttonCancel->setShortcut(QApplication::translate("PilotesPresents", "Alt+A", 0, QApplication::UnicodeUTF8));
    textLabel1_2->setText(QApplication::translate("PilotesPresents", "<p align=\"center\">S\303\251lectionnez les pilotes pr\303\251sents lors de la journ\303\251e de comp\303\251tition.", 0, QApplication::UnicodeUTF8));
    TextLabel1->setText(QApplication::translate("PilotesPresents", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">PILOTES PR\303\211SENTS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(PilotesPresents);
    } // retranslateUi

};

namespace Ui {
    class PilotesPresents: public Ui_PilotesPresents {};
} // namespace Ui

#endif // UI_PILOTESPRESENTS_H
