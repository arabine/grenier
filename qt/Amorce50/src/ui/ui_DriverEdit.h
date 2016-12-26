/********************************************************************************
** Form generated from reading ui file 'DriverEdit.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DRIVEREDIT_H
#define UI_DRIVEREDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_DriverEdit
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *TextLabel1;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *TextLabel1_2;
    QLabel *TextLabel2;
    QLabel *TextLabel3;
    QLabel *textLabel2;
    QVBoxLayout *vboxLayout2;
    QLineEdit *lneName;
    QSpinBox *lneNumber;
    QLineEdit *lneClub;
    QComboBox *cmbCategories;
    QHBoxLayout *hboxLayout1;
    QPushButton *btnOk;
    QSpacerItem *spacerItem;
    QPushButton *btnCancel;

    void setupUi(QDialog *DriverEdit)
    {
    DriverEdit->setObjectName(QString::fromUtf8("DriverEdit"));
    vboxLayout = new QVBoxLayout(DriverEdit);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    frame = new QFrame(DriverEdit);
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
    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    TextLabel1_2 = new QLabel(DriverEdit);
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

    vboxLayout1->addWidget(TextLabel1_2);

    TextLabel2 = new QLabel(DriverEdit);
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

    vboxLayout1->addWidget(TextLabel2);

    TextLabel3 = new QLabel(DriverEdit);
    TextLabel3->setObjectName(QString::fromUtf8("TextLabel3"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(TextLabel3->sizePolicy().hasHeightForWidth());
    TextLabel3->setSizePolicy(sizePolicy3);
    TextLabel3->setMinimumSize(QSize(0, 0));
    TextLabel3->setMaximumSize(QSize(32767, 32767));
    QFont font3;
    TextLabel3->setFont(font3);
    TextLabel3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    TextLabel3->setWordWrap(false);

    vboxLayout1->addWidget(TextLabel3);

    textLabel2 = new QLabel(DriverEdit);
    textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
    textLabel2->setWordWrap(false);

    vboxLayout1->addWidget(textLabel2);


    hboxLayout->addLayout(vboxLayout1);

    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    lneName = new QLineEdit(DriverEdit);
    lneName->setObjectName(QString::fromUtf8("lneName"));

    vboxLayout2->addWidget(lneName);

    lneNumber = new QSpinBox(DriverEdit);
    lneNumber->setObjectName(QString::fromUtf8("lneNumber"));
    QSizePolicy sizePolicy4(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(lneNumber->sizePolicy().hasHeightForWidth());
    lneNumber->setSizePolicy(sizePolicy4);
    lneNumber->setMaximum(1000);
    lneNumber->setMinimum(1);

    vboxLayout2->addWidget(lneNumber);

    lneClub = new QLineEdit(DriverEdit);
    lneClub->setObjectName(QString::fromUtf8("lneClub"));

    vboxLayout2->addWidget(lneClub);

    cmbCategories = new QComboBox(DriverEdit);
    cmbCategories->setObjectName(QString::fromUtf8("cmbCategories"));
    QSizePolicy sizePolicy5(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
    sizePolicy5.setHorizontalStretch(0);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(cmbCategories->sizePolicy().hasHeightForWidth());
    cmbCategories->setSizePolicy(sizePolicy5);

    vboxLayout2->addWidget(cmbCategories);


    hboxLayout->addLayout(vboxLayout2);


    vboxLayout->addLayout(hboxLayout);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    btnOk = new QPushButton(DriverEdit);
    btnOk->setObjectName(QString::fromUtf8("btnOk"));

    hboxLayout1->addWidget(btnOk);

    spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);

    btnCancel = new QPushButton(DriverEdit);
    btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

    hboxLayout1->addWidget(btnCancel);


    vboxLayout->addLayout(hboxLayout1);


    retranslateUi(DriverEdit);

    QSize size(367, 211);
    size = size.expandedTo(DriverEdit->minimumSizeHint());
    DriverEdit->resize(size);

    QObject::connect(btnOk, SIGNAL(clicked()), DriverEdit, SLOT(accept()));
    QObject::connect(btnCancel, SIGNAL(clicked()), DriverEdit, SLOT(reject()));

    QMetaObject::connectSlotsByName(DriverEdit);
    } // setupUi

    void retranslateUi(QDialog *DriverEdit)
    {
    DriverEdit->setWindowTitle(QApplication::translate("DriverEdit", "Ajout/\303\251dition d'un pilote", 0, QApplication::UnicodeUTF8));
    TextLabel1->setText(QApplication::translate("DriverEdit", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">AJOUT/EDITION</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    TextLabel1_2->setText(QApplication::translate("DriverEdit", "Nom", 0, QApplication::UnicodeUTF8));
    TextLabel2->setText(QApplication::translate("DriverEdit", "Num\303\251ro", 0, QApplication::UnicodeUTF8));
    TextLabel3->setText(QApplication::translate("DriverEdit", "Club", 0, QApplication::UnicodeUTF8));
    textLabel2->setText(QApplication::translate("DriverEdit", "Cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    btnOk->setText(QApplication::translate("DriverEdit", "&Ok", 0, QApplication::UnicodeUTF8));
    btnCancel->setText(QApplication::translate("DriverEdit", "&Annuler", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(DriverEdit);
    } // retranslateUi

};

namespace Ui {
    class DriverEdit: public Ui_DriverEdit {};
} // namespace Ui

#endif // UI_DRIVEREDIT_H
