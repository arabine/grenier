/********************************************************************************
** Form generated from reading ui file 'Result.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RESULT_H
#define UI_RESULT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_Result
{
public:
    QGridLayout *gridLayout;
    QFrame *line9;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *btnOk;
    QPushButton *btnPrint;
    QTextBrowser *resultView;

    void setupUi(QDialog *Result)
    {
    Result->setObjectName(QString::fromUtf8("Result"));
    gridLayout = new QGridLayout(Result);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    line9 = new QFrame(Result);
    line9->setObjectName(QString::fromUtf8("line9"));
    line9->setFrameShape(QFrame::HLine);
    line9->setFrameShadow(QFrame::Sunken);
    line9->setFrameShape(QFrame::HLine);
    line9->setFrameShadow(QFrame::Sunken);

    gridLayout->addWidget(line9, 1, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(381, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    btnOk = new QPushButton(Result);
    btnOk->setObjectName(QString::fromUtf8("btnOk"));

    hboxLayout->addWidget(btnOk);

    btnPrint = new QPushButton(Result);
    btnPrint->setObjectName(QString::fromUtf8("btnPrint"));

    hboxLayout->addWidget(btnPrint);


    gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);

    resultView = new QTextBrowser(Result);
    resultView->setObjectName(QString::fromUtf8("resultView"));

    gridLayout->addWidget(resultView, 0, 0, 1, 1);


    retranslateUi(Result);

    QSize size(707, 482);
    size = size.expandedTo(Result->minimumSizeHint());
    Result->resize(size);

    QObject::connect(btnOk, SIGNAL(clicked()), Result, SLOT(accept()));

    QMetaObject::connectSlotsByName(Result);
    } // setupUi

    void retranslateUi(QDialog *Result)
    {
    Result->setWindowTitle(QApplication::translate("Result", "Qt - R\303\251sultats", 0, QApplication::UnicodeUTF8));
    btnOk->setText(QApplication::translate("Result", "&Ok", 0, QApplication::UnicodeUTF8));
    btnOk->setShortcut(QApplication::translate("Result", "Alt+O", 0, QApplication::UnicodeUTF8));
    btnPrint->setText(QApplication::translate("Result", "&Imprimer", 0, QApplication::UnicodeUTF8));
    btnPrint->setShortcut(QApplication::translate("Result", "Alt+I", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Result);
    } // retranslateUi

};

namespace Ui {
    class Result: public Ui_Result {};
} // namespace Ui

#endif // UI_RESULT_H
