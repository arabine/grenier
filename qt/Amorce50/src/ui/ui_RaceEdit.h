/********************************************************************************
** Form generated from reading ui file 'RaceEdit.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RACEEDIT_H
#define UI_RACEEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_RaceEdit
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *TextLabel1;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel1_2;
    QLineEdit *lneName;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLabel2;
    QDateEdit *date;
    QHBoxLayout *hboxLayout2;
    QPushButton *btnOk;
    QSpacerItem *spacerItem;
    QPushButton *btnCancel;

    void setupUi(QDialog *RaceEdit)
    {
    RaceEdit->setObjectName(QString::fromUtf8("RaceEdit"));
    vboxLayout = new QVBoxLayout(RaceEdit);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    frame = new QFrame(RaceEdit);
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
    gridLayout = new QGridLayout(frame);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

    gridLayout->addWidget(TextLabel1, 0, 0, 1, 1);


    vboxLayout->addWidget(frame);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    TextLabel1_2 = new QLabel(RaceEdit);
    TextLabel1_2->setObjectName(QString::fromUtf8("TextLabel1_2"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(TextLabel1_2->sizePolicy().hasHeightForWidth());
    TextLabel1_2->setSizePolicy(sizePolicy1);
    TextLabel1_2->setMinimumSize(QSize(0, 0));
    TextLabel1_2->setMaximumSize(QSize(32767, 32767));
    QFont font1;
    TextLabel1_2->setFont(font1);
    TextLabel1_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    TextLabel1_2->setWordWrap(false);

    hboxLayout->addWidget(TextLabel1_2);

    lneName = new QLineEdit(RaceEdit);
    lneName->setObjectName(QString::fromUtf8("lneName"));

    hboxLayout->addWidget(lneName);


    vboxLayout->addLayout(hboxLayout);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    TextLabel2 = new QLabel(RaceEdit);
    TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(TextLabel2->sizePolicy().hasHeightForWidth());
    TextLabel2->setSizePolicy(sizePolicy2);
    TextLabel2->setMinimumSize(QSize(0, 0));
    TextLabel2->setMaximumSize(QSize(32767, 32767));
    QFont font2;
    TextLabel2->setFont(font2);
    TextLabel2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    TextLabel2->setWordWrap(false);

    hboxLayout1->addWidget(TextLabel2);

    date = new QDateEdit(RaceEdit);
    date->setObjectName(QString::fromUtf8("date"));

    hboxLayout1->addWidget(date);


    vboxLayout->addLayout(hboxLayout1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    btnOk = new QPushButton(RaceEdit);
    btnOk->setObjectName(QString::fromUtf8("btnOk"));

    hboxLayout2->addWidget(btnOk);

    spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem);

    btnCancel = new QPushButton(RaceEdit);
    btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

    hboxLayout2->addWidget(btnCancel);


    vboxLayout->addLayout(hboxLayout2);


    retranslateUi(RaceEdit);

    QSize size(268, 160);
    size = size.expandedTo(RaceEdit->minimumSizeHint());
    RaceEdit->resize(size);

    QObject::connect(btnOk, SIGNAL(clicked()), RaceEdit, SLOT(accept()));
    QObject::connect(btnCancel, SIGNAL(clicked()), RaceEdit, SLOT(reject()));

    QMetaObject::connectSlotsByName(RaceEdit);
    } // setupUi

    void retranslateUi(QDialog *RaceEdit)
    {
    RaceEdit->setWindowTitle(QApplication::translate("RaceEdit", "Ajout/\303\251dition d'une course", 0, QApplication::UnicodeUTF8));
    TextLabel1->setText(QApplication::translate("RaceEdit", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">AJOUT/EDITION</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    TextLabel1_2->setText(QApplication::translate("RaceEdit", "Lieu", 0, QApplication::UnicodeUTF8));
    TextLabel2->setText(QApplication::translate("RaceEdit", "Date", 0, QApplication::UnicodeUTF8));
    btnOk->setText(QApplication::translate("RaceEdit", "&Ok", 0, QApplication::UnicodeUTF8));
    btnOk->setShortcut(QApplication::translate("RaceEdit", "Alt+O", 0, QApplication::UnicodeUTF8));
    btnCancel->setText(QApplication::translate("RaceEdit", "&Annuler", 0, QApplication::UnicodeUTF8));
    btnCancel->setShortcut(QApplication::translate("RaceEdit", "Alt+A", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(RaceEdit);
    } // retranslateUi

};

namespace Ui {
    class RaceEdit: public Ui_RaceEdit {};
} // namespace Ui

#endif // UI_RACEEDIT_H
