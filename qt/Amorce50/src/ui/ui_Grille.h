/********************************************************************************
** Form generated from reading ui file 'Grille.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GRILLE_H
#define UI_GRILLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

class Ui_Grille
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_5;
    QHBoxLayout *hboxLayout;
    QRadioButton *rbChoix1;
    QRadioButton *rbChoix2;
    QVBoxLayout *vboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *btnTransfert;
    QSpacerItem *spacerItem1;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout1;
    QTableWidget *driversListNotCat;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout2;
    QTableWidget *driversListCat;
    QLabel *textLabel1_2;
    QVBoxLayout *vboxLayout1;
    QFrame *line3;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem2;
    QPushButton *btnShowGrid;
    QPushButton *btnOk;
    QPushButton *btnAnnuler;
    QFrame *frame;
    QGridLayout *gridLayout3;
    QLabel *TextLabel1;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout4;
    QTableWidget *driversList;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout2;
    QRadioButton *radioLeft;
    QRadioButton *radioRight;
    QVBoxLayout *vboxLayout3;
    QPushButton *btnDriverUp;
    QPushButton *btnDriverDown;

    void setupUi(QDialog *Grille)
    {
    Grille->setObjectName(QString::fromUtf8("Grille"));
    gridLayout = new QGridLayout(Grille);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox_5 = new QGroupBox(Grille);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    hboxLayout = new QHBoxLayout(groupBox_5);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(9);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    rbChoix1 = new QRadioButton(groupBox_5);
    rbChoix1->setObjectName(QString::fromUtf8("rbChoix1"));
    rbChoix1->setEnabled(false);

    hboxLayout->addWidget(rbChoix1);

    rbChoix2 = new QRadioButton(groupBox_5);
    rbChoix2->setObjectName(QString::fromUtf8("rbChoix2"));
    rbChoix2->setEnabled(false);
    rbChoix2->setChecked(true);

    hboxLayout->addWidget(rbChoix2);


    gridLayout->addWidget(groupBox_5, 5, 2, 1, 2);

    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout->addItem(spacerItem);

    btnTransfert = new QPushButton(Grille);
    btnTransfert->setObjectName(QString::fromUtf8("btnTransfert"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(btnTransfert->sizePolicy().hasHeightForWidth());
    btnTransfert->setSizePolicy(sizePolicy);
    btnTransfert->setMaximumSize(QSize(30, 32767));
    QFont font;
    font.setPointSize(10);
    font.setBold(true);
    font.setWeight(75);
    btnTransfert->setFont(font);

    vboxLayout->addWidget(btnTransfert);

    spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout->addItem(spacerItem1);


    gridLayout->addLayout(vboxLayout, 2, 1, 4, 1);

    groupBox_3 = new QGroupBox(Grille);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    gridLayout1 = new QGridLayout(groupBox_3);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    driversListNotCat = new QTableWidget(groupBox_3);
    driversListNotCat->setObjectName(QString::fromUtf8("driversListNotCat"));
    driversListNotCat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    driversListNotCat->setEditTriggers(QAbstractItemView::NoEditTriggers);
    driversListNotCat->setSelectionMode(QAbstractItemView::MultiSelection);
    driversListNotCat->setSelectionBehavior(QAbstractItemView::SelectRows);

    gridLayout1->addWidget(driversListNotCat, 0, 0, 1, 1);


    gridLayout->addWidget(groupBox_3, 3, 0, 3, 1);

    groupBox_2 = new QGroupBox(Grille);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout2 = new QGridLayout(groupBox_2);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    driversListCat = new QTableWidget(groupBox_2);
    driversListCat->setObjectName(QString::fromUtf8("driversListCat"));
    driversListCat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    driversListCat->setEditTriggers(QAbstractItemView::NoEditTriggers);
    driversListCat->setSelectionMode(QAbstractItemView::MultiSelection);
    driversListCat->setSelectionBehavior(QAbstractItemView::SelectRows);

    gridLayout2->addWidget(driversListCat, 0, 0, 1, 1);


    gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

    textLabel1_2 = new QLabel(Grille);
    textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
    textLabel1_2->setWordWrap(false);

    gridLayout->addWidget(textLabel1_2, 1, 0, 1, 4);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    line3 = new QFrame(Grille);
    line3->setObjectName(QString::fromUtf8("line3"));
    line3->setFrameShape(QFrame::HLine);
    line3->setFrameShadow(QFrame::Sunken);
    line3->setFrameShape(QFrame::HLine);
    line3->setFrameShadow(QFrame::Sunken);

    vboxLayout1->addWidget(line3);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem2 = new QSpacerItem(420, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem2);

    btnShowGrid = new QPushButton(Grille);
    btnShowGrid->setObjectName(QString::fromUtf8("btnShowGrid"));

    hboxLayout1->addWidget(btnShowGrid);

    btnOk = new QPushButton(Grille);
    btnOk->setObjectName(QString::fromUtf8("btnOk"));

    hboxLayout1->addWidget(btnOk);

    btnAnnuler = new QPushButton(Grille);
    btnAnnuler->setObjectName(QString::fromUtf8("btnAnnuler"));

    hboxLayout1->addWidget(btnAnnuler);


    vboxLayout1->addLayout(hboxLayout1);


    gridLayout->addLayout(vboxLayout1, 6, 0, 1, 4);

    frame = new QFrame(Grille);
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
    gridLayout3 = new QGridLayout(frame);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    TextLabel1 = new QLabel(frame);
    TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
    TextLabel1->setSizePolicy(sizePolicy1);
    TextLabel1->setMinimumSize(QSize(0, 0));
    TextLabel1->setMaximumSize(QSize(32767, 32767));
    QFont font1;
    font1.setPointSize(16);
    font1.setBold(true);
    font1.setWeight(75);
    TextLabel1->setFont(font1);
    TextLabel1->setAlignment(Qt::AlignCenter);
    TextLabel1->setWordWrap(false);

    gridLayout3->addWidget(TextLabel1, 0, 0, 1, 1);


    gridLayout->addWidget(frame, 0, 0, 1, 4);

    groupBox_4 = new QGroupBox(Grille);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    gridLayout4 = new QGridLayout(groupBox_4);
    gridLayout4->setSpacing(6);
    gridLayout4->setMargin(9);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    driversList = new QTableWidget(groupBox_4);
    driversList->setObjectName(QString::fromUtf8("driversList"));
    driversList->setMinimumSize(QSize(300, 0));
    driversList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    driversList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    driversList->setSelectionMode(QAbstractItemView::SingleSelection);
    driversList->setSelectionBehavior(QAbstractItemView::SelectRows);

    gridLayout4->addWidget(driversList, 0, 0, 1, 1);


    gridLayout->addWidget(groupBox_4, 2, 2, 2, 2);

    groupBox = new QGroupBox(Grille);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    vboxLayout2 = new QVBoxLayout(groupBox);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(9);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    radioLeft = new QRadioButton(groupBox);
    radioLeft->setObjectName(QString::fromUtf8("radioLeft"));
    radioLeft->setChecked(true);

    vboxLayout2->addWidget(radioLeft);

    radioRight = new QRadioButton(groupBox);
    radioRight->setObjectName(QString::fromUtf8("radioRight"));

    vboxLayout2->addWidget(radioRight);


    gridLayout->addWidget(groupBox, 4, 2, 1, 1);

    vboxLayout3 = new QVBoxLayout();
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(0);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    btnDriverUp = new QPushButton(Grille);
    btnDriverUp->setObjectName(QString::fromUtf8("btnDriverUp"));
    btnDriverUp->setIcon(QIcon(QString::fromUtf8(":/images/images/arrow_up.png")));

    vboxLayout3->addWidget(btnDriverUp);

    btnDriverDown = new QPushButton(Grille);
    btnDriverDown->setObjectName(QString::fromUtf8("btnDriverDown"));
    btnDriverDown->setIcon(QIcon(QString::fromUtf8(":/images/images/arrow_down.png")));

    vboxLayout3->addWidget(btnDriverDown);


    gridLayout->addLayout(vboxLayout3, 4, 3, 1, 1);


    retranslateUi(Grille);

    QSize size(742, 588);
    size = size.expandedTo(Grille->minimumSizeHint());
    Grille->resize(size);

    QObject::connect(btnAnnuler, SIGNAL(clicked()), Grille, SLOT(reject()));
    QObject::connect(btnOk, SIGNAL(clicked()), Grille, SLOT(accept()));

    QMetaObject::connectSlotsByName(Grille);
    } // setupUi

    void retranslateUi(QDialog *Grille)
    {
    Grille->setWindowTitle(QApplication::translate("Grille", "Pilotes au d\303\251part de la manche", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("Grille", "Premi\303\250re ligne", 0, QApplication::UnicodeUTF8));
    rbChoix1->setText(QApplication::translate("Grille", "1 pilote", 0, QApplication::UnicodeUTF8));
    rbChoix2->setText(QApplication::translate("Grille", "4 pilotes", 0, QApplication::UnicodeUTF8));
    btnTransfert->setText(QApplication::translate("Grille", "-->", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("Grille", "Pilotes pr\303\251sents hors cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    if (driversListNotCat->columnCount() < 3)
        driversListNotCat->setColumnCount(3);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("Grille", "id", 0, QApplication::UnicodeUTF8));
    driversListNotCat->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("Grille", "Pilote", 0, QApplication::UnicodeUTF8));
    driversListNotCat->setHorizontalHeaderItem(1, __colItem1);

    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    __colItem2->setText(QApplication::translate("Grille", "Num\303\251ro", 0, QApplication::UnicodeUTF8));
    driversListNotCat->setHorizontalHeaderItem(2, __colItem2);
    groupBox_2->setTitle(QApplication::translate("Grille", "Pilotes pr\303\251sents de la cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    if (driversListCat->columnCount() < 3)
        driversListCat->setColumnCount(3);

    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    __colItem3->setText(QApplication::translate("Grille", "id", 0, QApplication::UnicodeUTF8));
    driversListCat->setHorizontalHeaderItem(0, __colItem3);

    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    __colItem4->setText(QApplication::translate("Grille", "Pilote", 0, QApplication::UnicodeUTF8));
    driversListCat->setHorizontalHeaderItem(1, __colItem4);

    QTableWidgetItem *__colItem5 = new QTableWidgetItem();
    __colItem5->setText(QApplication::translate("Grille", "Num\303\251ro", 0, QApplication::UnicodeUTF8));
    driversListCat->setHorizontalHeaderItem(2, __colItem5);
    textLabel1_2->setText(QApplication::translate("Grille", "<p align=\"center\">S\303\251lectionnez les pilotes participants \303\240 cette manche, puis d\303\251finissez l'ordre de d\303\251part. \n"
"La grille de d\303\251part sera automatiquement g\303\251n\303\251r\303\251e.</p>", 0, QApplication::UnicodeUTF8));
    btnShowGrid->setText(QApplication::translate("Grille", "Visualiser la grille !", 0, QApplication::UnicodeUTF8));
    btnShowGrid->setShortcut(QString());
    btnOk->setText(QApplication::translate("Grille", "&Ok", 0, QApplication::UnicodeUTF8));
    btnOk->setShortcut(QApplication::translate("Grille", "Alt+O", 0, QApplication::UnicodeUTF8));
    btnAnnuler->setText(QApplication::translate("Grille", "&Annuler", 0, QApplication::UnicodeUTF8));
    btnAnnuler->setShortcut(QApplication::translate("Grille", "Alt+A", 0, QApplication::UnicodeUTF8));
    TextLabel1->setText(QApplication::translate("Grille", "GRILLE DE DEPART", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("Grille", "Pilotes sur la grille de d\303\251part", 0, QApplication::UnicodeUTF8));
    if (driversList->columnCount() < 4)
        driversList->setColumnCount(4);

    QTableWidgetItem *__colItem6 = new QTableWidgetItem();
    __colItem6->setText(QApplication::translate("Grille", "Position", 0, QApplication::UnicodeUTF8));
    driversList->setHorizontalHeaderItem(0, __colItem6);

    QTableWidgetItem *__colItem7 = new QTableWidgetItem();
    __colItem7->setText(QApplication::translate("Grille", "id", 0, QApplication::UnicodeUTF8));
    driversList->setHorizontalHeaderItem(1, __colItem7);

    QTableWidgetItem *__colItem8 = new QTableWidgetItem();
    __colItem8->setText(QApplication::translate("Grille", "Pilote", 0, QApplication::UnicodeUTF8));
    driversList->setHorizontalHeaderItem(2, __colItem8);

    QTableWidgetItem *__colItem9 = new QTableWidgetItem();
    __colItem9->setText(QApplication::translate("Grille", "Num\303\251ro", 0, QApplication::UnicodeUTF8));
    driversList->setHorizontalHeaderItem(3, __colItem9);
    groupBox->setTitle(QApplication::translate("Grille", "Premier virage", 0, QApplication::UnicodeUTF8));
    radioLeft->setText(QApplication::translate("Grille", "\303\200 gauche", 0, QApplication::UnicodeUTF8));
    radioRight->setText(QApplication::translate("Grille", "\303\200 droite", 0, QApplication::UnicodeUTF8));
    btnDriverUp->setText(QString());
    btnDriverDown->setText(QString());
    Q_UNUSED(Grille);
    } // retranslateUi

};

namespace Ui {
    class Grille: public Ui_Grille {};
} // namespace Ui

#endif // UI_GRILLE_H
