/********************************************************************************
** Form generated from reading ui file 'PointsEdit.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_POINTSEDIT_H
#define UI_POINTSEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_PointsEdit
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *TextLabel1;
    QHBoxLayout *hboxLayout;
    QLabel *lblPosition;
    QLabel *positionNum;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLabel1_2_2;
    QSpinBox *pointsBox;
    QHBoxLayout *hboxLayout2;
    QPushButton *btnOk;
    QSpacerItem *spacerItem;
    QPushButton *btnCancel;

    void setupUi(QDialog *PointsEdit)
    {
    PointsEdit->setObjectName(QString::fromUtf8("PointsEdit"));
    vboxLayout = new QVBoxLayout(PointsEdit);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    frame = new QFrame(PointsEdit);
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
    lblPosition = new QLabel(PointsEdit);
    lblPosition->setObjectName(QString::fromUtf8("lblPosition"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(1));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(lblPosition->sizePolicy().hasHeightForWidth());
    lblPosition->setSizePolicy(sizePolicy1);
    lblPosition->setMinimumSize(QSize(0, 0));
    lblPosition->setMaximumSize(QSize(32767, 32767));
    QFont font1;
    lblPosition->setFont(font1);
    lblPosition->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    lblPosition->setWordWrap(false);

    hboxLayout->addWidget(lblPosition);

    positionNum = new QLabel(PointsEdit);
    positionNum->setObjectName(QString::fromUtf8("positionNum"));

    hboxLayout->addWidget(positionNum);


    vboxLayout->addLayout(hboxLayout);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    TextLabel1_2_2 = new QLabel(PointsEdit);
    TextLabel1_2_2->setObjectName(QString::fromUtf8("TextLabel1_2_2"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(1));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(TextLabel1_2_2->sizePolicy().hasHeightForWidth());
    TextLabel1_2_2->setSizePolicy(sizePolicy2);
    TextLabel1_2_2->setMinimumSize(QSize(0, 0));
    TextLabel1_2_2->setMaximumSize(QSize(32767, 32767));
    QFont font2;
    TextLabel1_2_2->setFont(font2);
    TextLabel1_2_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    TextLabel1_2_2->setWordWrap(false);

    hboxLayout1->addWidget(TextLabel1_2_2);

    pointsBox = new QSpinBox(PointsEdit);
    pointsBox->setObjectName(QString::fromUtf8("pointsBox"));

    hboxLayout1->addWidget(pointsBox);


    vboxLayout->addLayout(hboxLayout1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    btnOk = new QPushButton(PointsEdit);
    btnOk->setObjectName(QString::fromUtf8("btnOk"));

    hboxLayout2->addWidget(btnOk);

    spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem);

    btnCancel = new QPushButton(PointsEdit);
    btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

    hboxLayout2->addWidget(btnCancel);


    vboxLayout->addLayout(hboxLayout2);


    retranslateUi(PointsEdit);

    QSize size(250, 149);
    size = size.expandedTo(PointsEdit->minimumSizeHint());
    PointsEdit->resize(size);

    QObject::connect(btnOk, SIGNAL(clicked()), PointsEdit, SLOT(accept()));
    QObject::connect(btnCancel, SIGNAL(clicked()), PointsEdit, SLOT(reject()));

    QMetaObject::connectSlotsByName(PointsEdit);
    } // setupUi

    void retranslateUi(QDialog *PointsEdit)
    {
    PointsEdit->setWindowTitle(QApplication::translate("PointsEdit", "R\303\251partition des points", 0, QApplication::UnicodeUTF8));
    TextLabel1->setText(QApplication::translate("PointsEdit", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">AJOUT/EDITION</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    lblPosition->setText(QApplication::translate("PointsEdit", "Position", 0, QApplication::UnicodeUTF8));
    positionNum->setText(QApplication::translate("PointsEdit", "0", 0, QApplication::UnicodeUTF8));
    TextLabel1_2_2->setText(QApplication::translate("PointsEdit", "Points", 0, QApplication::UnicodeUTF8));
    btnOk->setText(QApplication::translate("PointsEdit", "&Ok", 0, QApplication::UnicodeUTF8));
    btnOk->setShortcut(QApplication::translate("PointsEdit", "Alt+O", 0, QApplication::UnicodeUTF8));
    btnCancel->setText(QApplication::translate("PointsEdit", "&Annuler", 0, QApplication::UnicodeUTF8));
    btnCancel->setShortcut(QApplication::translate("PointsEdit", "Alt+A", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(PointsEdit);
    } // retranslateUi

};

namespace Ui {
    class PointsEdit: public Ui_PointsEdit {};
} // namespace Ui

#endif // UI_POINTSEDIT_H
