/********************************************************************************
** Form generated from reading ui file 'CategoryEdit.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CATEGORYEDIT_H
#define UI_CATEGORYEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_CategoryEdit
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout1;
    QLabel *TextLabel1;
    QLineEdit *lneName;
    QHBoxLayout *hboxLayout;
    QPushButton *btnOk;
    QSpacerItem *spacerItem;
    QPushButton *btnCancel;

    void setupUi(QDialog *CategoryEdit)
    {
    CategoryEdit->setObjectName(QString::fromUtf8("CategoryEdit"));
    gridLayout = new QGridLayout(CategoryEdit);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    frame = new QFrame(CategoryEdit);
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

    lneName = new QLineEdit(CategoryEdit);
    lneName->setObjectName(QString::fromUtf8("lneName"));

    gridLayout->addWidget(lneName, 1, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    btnOk = new QPushButton(CategoryEdit);
    btnOk->setObjectName(QString::fromUtf8("btnOk"));

    hboxLayout->addWidget(btnOk);

    spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    btnCancel = new QPushButton(CategoryEdit);
    btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

    hboxLayout->addWidget(btnCancel);


    gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);


    retranslateUi(CategoryEdit);

    QSize size(295, 129);
    size = size.expandedTo(CategoryEdit->minimumSizeHint());
    CategoryEdit->resize(size);

    QObject::connect(btnOk, SIGNAL(clicked()), CategoryEdit, SLOT(accept()));
    QObject::connect(btnCancel, SIGNAL(clicked()), CategoryEdit, SLOT(reject()));

    QMetaObject::connectSlotsByName(CategoryEdit);
    } // setupUi

    void retranslateUi(QDialog *CategoryEdit)
    {
    CategoryEdit->setWindowTitle(QApplication::translate("CategoryEdit", "Ajout/\303\251dition d'une cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    TextLabel1->setText(QApplication::translate("CategoryEdit", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">AJOUT/EDITION</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    btnOk->setText(QApplication::translate("CategoryEdit", "&Ok", 0, QApplication::UnicodeUTF8));
    btnCancel->setText(QApplication::translate("CategoryEdit", "&Annuler", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CategoryEdit);
    } // retranslateUi

};

namespace Ui {
    class CategoryEdit: public Ui_CategoryEdit {};
} // namespace Ui

#endif // UI_CATEGORYEDIT_H
