/********************************************************************************
** Form generated from reading ui file 'Parametres.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PARAMETRES_H
#define UI_PARAMETRES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_Parametres
{
public:
    QGridLayout *gridLayout;
    QTabWidget *ongletsParametres;
    QWidget *SaisonsTab;
    QGridLayout *gridLayout1;
    QTableWidget *seasonsList;
    QVBoxLayout *vboxLayout;
    QPushButton *btnAddSeason;
    QPushButton *btnEditSeason;
    QPushButton *btnDeleteSeason;
    QSpacerItem *spacerItem;
    QFrame *frame_4;
    QGridLayout *gridLayout2;
    QLabel *TextLabel1;
    QWidget *PilotesTab;
    QGridLayout *gridLayout3;
    QTableWidget *driversList;
    QVBoxLayout *vboxLayout1;
    QLabel *textLabel1_2;
    QComboBox *categoriesCombo;
    QPushButton *btnAddDriver;
    QPushButton *btnEditDriver;
    QPushButton *btnDeleteDriver;
    QSpacerItem *spacerItem1;
    QFrame *frame_3;
    QGridLayout *gridLayout4;
    QLabel *TextLabel1_2;
    QWidget *CategoriesTab;
    QGridLayout *gridLayout5;
    QPushButton *btnSousCat;
    QSpacerItem *spacerItem2;
    QPushButton *btnDeleteCategory;
    QPushButton *btnEditCategory;
    QPushButton *btnAddCategory;
    QFrame *frame_2;
    QGridLayout *gridLayout6;
    QLabel *TextLabel1_3;
    QTableWidget *categoriesList;
    QWidget *ReglementTab;
    QGridLayout *gridLayout7;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QSpinBox *tauxMini;
    QLabel *label_2;
    QSpacerItem *spacerItem3;
    QFrame *frame;
    QGridLayout *gridLayout8;
    QLabel *TextLabel1_3_3;
    QVBoxLayout *vboxLayout3;
    QTableWidget *pointsList;
    QVBoxLayout *vboxLayout4;
    QPushButton *btnAddPosition;
    QPushButton *btnEditPosition;
    QSpacerItem *spacerItem4;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem5;
    QPushButton *btnOk;

    void setupUi(QDialog *Parametres)
    {
    Parametres->setObjectName(QString::fromUtf8("Parametres"));
    Parametres->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(Parametres);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    ongletsParametres = new QTabWidget(Parametres);
    ongletsParametres->setObjectName(QString::fromUtf8("ongletsParametres"));
    SaisonsTab = new QWidget();
    SaisonsTab->setObjectName(QString::fromUtf8("SaisonsTab"));
    gridLayout1 = new QGridLayout(SaisonsTab);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    seasonsList = new QTableWidget(SaisonsTab);
    seasonsList->setObjectName(QString::fromUtf8("seasonsList"));
    seasonsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    seasonsList->setSelectionMode(QAbstractItemView::SingleSelection);
    seasonsList->setSelectionBehavior(QAbstractItemView::SelectRows);

    gridLayout1->addWidget(seasonsList, 1, 0, 1, 1);

    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    btnAddSeason = new QPushButton(SaisonsTab);
    btnAddSeason->setObjectName(QString::fromUtf8("btnAddSeason"));

    vboxLayout->addWidget(btnAddSeason);

    btnEditSeason = new QPushButton(SaisonsTab);
    btnEditSeason->setObjectName(QString::fromUtf8("btnEditSeason"));

    vboxLayout->addWidget(btnEditSeason);

    btnDeleteSeason = new QPushButton(SaisonsTab);
    btnDeleteSeason->setObjectName(QString::fromUtf8("btnDeleteSeason"));
    btnDeleteSeason->setCheckable(false);
    btnDeleteSeason->setFlat(false);

    vboxLayout->addWidget(btnDeleteSeason);

    spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout->addItem(spacerItem);


    gridLayout1->addLayout(vboxLayout, 1, 1, 1, 1);

    frame_4 = new QFrame(SaisonsTab);
    frame_4->setObjectName(QString::fromUtf8("frame_4"));
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
    frame_4->setPalette(palette);
    frame_4->setAutoFillBackground(true);
    frame_4->setFrameShape(QFrame::Box);
    frame_4->setFrameShadow(QFrame::Plain);
    gridLayout2 = new QGridLayout(frame_4);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    TextLabel1 = new QLabel(frame_4);
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

    gridLayout2->addWidget(TextLabel1, 0, 0, 1, 1);


    gridLayout1->addWidget(frame_4, 0, 0, 1, 2);

    ongletsParametres->addTab(SaisonsTab, QApplication::translate("Parametres", "Saisons", 0, QApplication::UnicodeUTF8));
    PilotesTab = new QWidget();
    PilotesTab->setObjectName(QString::fromUtf8("PilotesTab"));
    gridLayout3 = new QGridLayout(PilotesTab);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    driversList = new QTableWidget(PilotesTab);
    driversList->setObjectName(QString::fromUtf8("driversList"));
    driversList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    driversList->setSelectionMode(QAbstractItemView::SingleSelection);
    driversList->setSelectionBehavior(QAbstractItemView::SelectRows);

    gridLayout3->addWidget(driversList, 1, 0, 1, 1);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    textLabel1_2 = new QLabel(PilotesTab);
    textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
    textLabel1_2->setWordWrap(false);

    vboxLayout1->addWidget(textLabel1_2);

    categoriesCombo = new QComboBox(PilotesTab);
    categoriesCombo->setObjectName(QString::fromUtf8("categoriesCombo"));

    vboxLayout1->addWidget(categoriesCombo);

    btnAddDriver = new QPushButton(PilotesTab);
    btnAddDriver->setObjectName(QString::fromUtf8("btnAddDriver"));

    vboxLayout1->addWidget(btnAddDriver);

    btnEditDriver = new QPushButton(PilotesTab);
    btnEditDriver->setObjectName(QString::fromUtf8("btnEditDriver"));

    vboxLayout1->addWidget(btnEditDriver);

    btnDeleteDriver = new QPushButton(PilotesTab);
    btnDeleteDriver->setObjectName(QString::fromUtf8("btnDeleteDriver"));
    btnDeleteDriver->setEnabled(true);
    btnDeleteDriver->setCheckable(false);
    btnDeleteDriver->setFlat(false);

    vboxLayout1->addWidget(btnDeleteDriver);

    spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout1->addItem(spacerItem1);


    gridLayout3->addLayout(vboxLayout1, 1, 1, 1, 1);

    frame_3 = new QFrame(PilotesTab);
    frame_3->setObjectName(QString::fromUtf8("frame_3"));
    QPalette palette1;
    QBrush brush6(QColor(255, 255, 255, 255));
    brush6.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
    QBrush brush7(QColor(255, 255, 255, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
    QBrush brush8(QColor(255, 255, 255, 255));
    brush8.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Inactive, QPalette::Base, brush8);
    QBrush brush9(QColor(255, 255, 255, 255));
    brush9.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
    QBrush brush10(QColor(255, 255, 255, 255));
    brush10.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Disabled, QPalette::Base, brush10);
    QBrush brush11(QColor(255, 255, 255, 255));
    brush11.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Disabled, QPalette::Window, brush11);
    frame_3->setPalette(palette1);
    frame_3->setAutoFillBackground(true);
    frame_3->setFrameShape(QFrame::Box);
    frame_3->setFrameShadow(QFrame::Plain);
    gridLayout4 = new QGridLayout(frame_3);
    gridLayout4->setSpacing(6);
    gridLayout4->setMargin(9);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    TextLabel1_2 = new QLabel(frame_3);
    TextLabel1_2->setObjectName(QString::fromUtf8("TextLabel1_2"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(TextLabel1_2->sizePolicy().hasHeightForWidth());
    TextLabel1_2->setSizePolicy(sizePolicy1);
    TextLabel1_2->setMinimumSize(QSize(0, 0));
    TextLabel1_2->setMaximumSize(QSize(32767, 32767));
    QFont font1;
    font1.setPointSize(16);
    font1.setBold(true);
    font1.setWeight(75);
    TextLabel1_2->setFont(font1);
    TextLabel1_2->setAlignment(Qt::AlignCenter);
    TextLabel1_2->setWordWrap(false);

    gridLayout4->addWidget(TextLabel1_2, 0, 0, 1, 1);


    gridLayout3->addWidget(frame_3, 0, 0, 1, 2);

    ongletsParametres->addTab(PilotesTab, QApplication::translate("Parametres", "Pilotes", 0, QApplication::UnicodeUTF8));
    CategoriesTab = new QWidget();
    CategoriesTab->setObjectName(QString::fromUtf8("CategoriesTab"));
    gridLayout5 = new QGridLayout(CategoriesTab);
    gridLayout5->setSpacing(6);
    gridLayout5->setMargin(9);
    gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
    btnSousCat = new QPushButton(CategoriesTab);
    btnSousCat->setObjectName(QString::fromUtf8("btnSousCat"));

    gridLayout5->addWidget(btnSousCat, 4, 1, 1, 1);

    spacerItem2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout5->addItem(spacerItem2, 5, 1, 1, 1);

    btnDeleteCategory = new QPushButton(CategoriesTab);
    btnDeleteCategory->setObjectName(QString::fromUtf8("btnDeleteCategory"));
    btnDeleteCategory->setCheckable(false);
    btnDeleteCategory->setFlat(false);

    gridLayout5->addWidget(btnDeleteCategory, 3, 1, 1, 1);

    btnEditCategory = new QPushButton(CategoriesTab);
    btnEditCategory->setObjectName(QString::fromUtf8("btnEditCategory"));

    gridLayout5->addWidget(btnEditCategory, 2, 1, 1, 1);

    btnAddCategory = new QPushButton(CategoriesTab);
    btnAddCategory->setObjectName(QString::fromUtf8("btnAddCategory"));

    gridLayout5->addWidget(btnAddCategory, 1, 1, 1, 1);

    frame_2 = new QFrame(CategoriesTab);
    frame_2->setObjectName(QString::fromUtf8("frame_2"));
    QPalette palette2;
    QBrush brush12(QColor(255, 255, 255, 255));
    brush12.setStyle(Qt::SolidPattern);
    palette2.setBrush(QPalette::Active, QPalette::Base, brush12);
    QBrush brush13(QColor(255, 255, 255, 255));
    brush13.setStyle(Qt::SolidPattern);
    palette2.setBrush(QPalette::Active, QPalette::Window, brush13);
    QBrush brush14(QColor(255, 255, 255, 255));
    brush14.setStyle(Qt::SolidPattern);
    palette2.setBrush(QPalette::Inactive, QPalette::Base, brush14);
    QBrush brush15(QColor(255, 255, 255, 255));
    brush15.setStyle(Qt::SolidPattern);
    palette2.setBrush(QPalette::Inactive, QPalette::Window, brush15);
    QBrush brush16(QColor(255, 255, 255, 255));
    brush16.setStyle(Qt::SolidPattern);
    palette2.setBrush(QPalette::Disabled, QPalette::Base, brush16);
    QBrush brush17(QColor(255, 255, 255, 255));
    brush17.setStyle(Qt::SolidPattern);
    palette2.setBrush(QPalette::Disabled, QPalette::Window, brush17);
    frame_2->setPalette(palette2);
    frame_2->setAutoFillBackground(true);
    frame_2->setFrameShape(QFrame::Box);
    frame_2->setFrameShadow(QFrame::Plain);
    gridLayout6 = new QGridLayout(frame_2);
    gridLayout6->setSpacing(6);
    gridLayout6->setMargin(9);
    gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
    TextLabel1_3 = new QLabel(frame_2);
    TextLabel1_3->setObjectName(QString::fromUtf8("TextLabel1_3"));
    QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(TextLabel1_3->sizePolicy().hasHeightForWidth());
    TextLabel1_3->setSizePolicy(sizePolicy2);
    TextLabel1_3->setMinimumSize(QSize(0, 0));
    TextLabel1_3->setMaximumSize(QSize(32767, 32767));
    QFont font2;
    font2.setPointSize(16);
    font2.setBold(true);
    font2.setWeight(75);
    TextLabel1_3->setFont(font2);
    TextLabel1_3->setAlignment(Qt::AlignCenter);
    TextLabel1_3->setWordWrap(false);

    gridLayout6->addWidget(TextLabel1_3, 0, 0, 1, 1);


    gridLayout5->addWidget(frame_2, 0, 0, 1, 2);

    categoriesList = new QTableWidget(CategoriesTab);
    categoriesList->setObjectName(QString::fromUtf8("categoriesList"));
    categoriesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    categoriesList->setSelectionMode(QAbstractItemView::SingleSelection);
    categoriesList->setSelectionBehavior(QAbstractItemView::SelectRows);

    gridLayout5->addWidget(categoriesList, 1, 0, 5, 1);

    ongletsParametres->addTab(CategoriesTab, QApplication::translate("Parametres", "Cat\303\251gories", 0, QApplication::UnicodeUTF8));
    ReglementTab = new QWidget();
    ReglementTab->setObjectName(QString::fromUtf8("ReglementTab"));
    gridLayout7 = new QGridLayout(ReglementTab);
    gridLayout7->setSpacing(6);
    gridLayout7->setMargin(9);
    gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
    groupBox = new QGroupBox(ReglementTab);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    vboxLayout2 = new QVBoxLayout(groupBox);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(9);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    hboxLayout->addWidget(label);

    tauxMini = new QSpinBox(groupBox);
    tauxMini->setObjectName(QString::fromUtf8("tauxMini"));
    tauxMini->setEnabled(false);
    tauxMini->setMaximum(100);
    tauxMini->setValue(75);

    hboxLayout->addWidget(tauxMini);


    vboxLayout2->addLayout(hboxLayout);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    vboxLayout2->addWidget(label_2);

    spacerItem3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout2->addItem(spacerItem3);


    gridLayout7->addWidget(groupBox, 1, 1, 1, 1);

    frame = new QFrame(ReglementTab);
    frame->setObjectName(QString::fromUtf8("frame"));
    QPalette palette3;
    QBrush brush18(QColor(255, 255, 255, 255));
    brush18.setStyle(Qt::SolidPattern);
    palette3.setBrush(QPalette::Active, QPalette::Base, brush18);
    QBrush brush19(QColor(255, 255, 255, 255));
    brush19.setStyle(Qt::SolidPattern);
    palette3.setBrush(QPalette::Active, QPalette::Window, brush19);
    QBrush brush20(QColor(255, 255, 255, 255));
    brush20.setStyle(Qt::SolidPattern);
    palette3.setBrush(QPalette::Inactive, QPalette::Base, brush20);
    QBrush brush21(QColor(255, 255, 255, 255));
    brush21.setStyle(Qt::SolidPattern);
    palette3.setBrush(QPalette::Inactive, QPalette::Window, brush21);
    QBrush brush22(QColor(255, 255, 255, 255));
    brush22.setStyle(Qt::SolidPattern);
    palette3.setBrush(QPalette::Disabled, QPalette::Base, brush22);
    QBrush brush23(QColor(255, 255, 255, 255));
    brush23.setStyle(Qt::SolidPattern);
    palette3.setBrush(QPalette::Disabled, QPalette::Window, brush23);
    frame->setPalette(palette3);
    frame->setAutoFillBackground(true);
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Plain);
    gridLayout8 = new QGridLayout(frame);
    gridLayout8->setSpacing(6);
    gridLayout8->setMargin(9);
    gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
    TextLabel1_3_3 = new QLabel(frame);
    TextLabel1_3_3->setObjectName(QString::fromUtf8("TextLabel1_3_3"));
    QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(TextLabel1_3_3->sizePolicy().hasHeightForWidth());
    TextLabel1_3_3->setSizePolicy(sizePolicy3);
    TextLabel1_3_3->setMinimumSize(QSize(0, 0));
    TextLabel1_3_3->setMaximumSize(QSize(32767, 32767));
    QFont font3;
    font3.setPointSize(16);
    font3.setBold(true);
    font3.setWeight(75);
    TextLabel1_3_3->setFont(font3);
    TextLabel1_3_3->setAlignment(Qt::AlignCenter);
    TextLabel1_3_3->setWordWrap(false);

    gridLayout8->addWidget(TextLabel1_3_3, 0, 0, 1, 1);


    gridLayout7->addWidget(frame, 0, 0, 1, 2);

    vboxLayout3 = new QVBoxLayout();
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(0);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    pointsList = new QTableWidget(ReglementTab);
    pointsList->setObjectName(QString::fromUtf8("pointsList"));
    pointsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pointsList->setSelectionMode(QAbstractItemView::SingleSelection);
    pointsList->setSelectionBehavior(QAbstractItemView::SelectRows);

    vboxLayout3->addWidget(pointsList);

    vboxLayout4 = new QVBoxLayout();
    vboxLayout4->setSpacing(6);
    vboxLayout4->setMargin(0);
    vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
    btnAddPosition = new QPushButton(ReglementTab);
    btnAddPosition->setObjectName(QString::fromUtf8("btnAddPosition"));

    vboxLayout4->addWidget(btnAddPosition);

    btnEditPosition = new QPushButton(ReglementTab);
    btnEditPosition->setObjectName(QString::fromUtf8("btnEditPosition"));

    vboxLayout4->addWidget(btnEditPosition);

    spacerItem4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout4->addItem(spacerItem4);


    vboxLayout3->addLayout(vboxLayout4);


    gridLayout7->addLayout(vboxLayout3, 1, 0, 1, 1);

    ongletsParametres->addTab(ReglementTab, QApplication::translate("Parametres", "R\303\250glement", 0, QApplication::UnicodeUTF8));

    gridLayout->addWidget(ongletsParametres, 0, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem5 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem5);

    btnOk = new QPushButton(Parametres);
    btnOk->setObjectName(QString::fromUtf8("btnOk"));
    btnOk->setAutoDefault(true);
    btnOk->setDefault(true);

    hboxLayout1->addWidget(btnOk);


    gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);


    retranslateUi(Parametres);

    QSize size(472, 458);
    size = size.expandedTo(Parametres->minimumSizeHint());
    Parametres->resize(size);

    QObject::connect(btnOk, SIGNAL(clicked()), Parametres, SLOT(accept()));

    ongletsParametres->setCurrentIndex(2);


    QMetaObject::connectSlotsByName(Parametres);
    } // setupUi

    void retranslateUi(QDialog *Parametres)
    {
    Parametres->setWindowTitle(QApplication::translate("Parametres", "Param\303\250tres de Amorce50", 0, QApplication::UnicodeUTF8));
    if (seasonsList->columnCount() < 2)
        seasonsList->setColumnCount(2);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("Parametres", "id", 0, QApplication::UnicodeUTF8));
    seasonsList->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("Parametres", "Saison", 0, QApplication::UnicodeUTF8));
    seasonsList->setHorizontalHeaderItem(1, __colItem1);
    btnAddSeason->setText(QApplication::translate("Parametres", "&Nouvelle saison", 0, QApplication::UnicodeUTF8));
    btnAddSeason->setShortcut(QApplication::translate("Parametres", "Alt+N", 0, QApplication::UnicodeUTF8));
    btnEditSeason->setText(QApplication::translate("Parametres", "&Editer une saison", 0, QApplication::UnicodeUTF8));
    btnEditSeason->setShortcut(QApplication::translate("Parametres", "Alt+E", 0, QApplication::UnicodeUTF8));
    btnDeleteSeason->setText(QApplication::translate("Parametres", "&Supprimer une saison", 0, QApplication::UnicodeUTF8));
    btnDeleteSeason->setShortcut(QApplication::translate("Parametres", "Alt+S", 0, QApplication::UnicodeUTF8));
    TextLabel1->setText(QApplication::translate("Parametres", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">S A I S O N S</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    ongletsParametres->setTabText(ongletsParametres->indexOf(SaisonsTab), QApplication::translate("Parametres", "Saisons", 0, QApplication::UnicodeUTF8));
    if (driversList->columnCount() < 4)
        driversList->setColumnCount(4);

    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    __colItem2->setText(QApplication::translate("Parametres", "id", 0, QApplication::UnicodeUTF8));
    driversList->setHorizontalHeaderItem(0, __colItem2);

    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    __colItem3->setText(QApplication::translate("Parametres", "Nom", 0, QApplication::UnicodeUTF8));
    driversList->setHorizontalHeaderItem(1, __colItem3);

    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    __colItem4->setText(QApplication::translate("Parametres", "Num\303\251ro", 0, QApplication::UnicodeUTF8));
    driversList->setHorizontalHeaderItem(2, __colItem4);

    QTableWidgetItem *__colItem5 = new QTableWidgetItem();
    __colItem5->setText(QApplication::translate("Parametres", "Club", 0, QApplication::UnicodeUTF8));
    driversList->setHorizontalHeaderItem(3, __colItem5);
    textLabel1_2->setText(QApplication::translate("Parametres", "Cat\303\251gorie :", 0, QApplication::UnicodeUTF8));
    btnAddDriver->setText(QApplication::translate("Parametres", "&Ajouter un pilote", 0, QApplication::UnicodeUTF8));
    btnAddDriver->setShortcut(QApplication::translate("Parametres", "Alt+A", 0, QApplication::UnicodeUTF8));
    btnEditDriver->setText(QApplication::translate("Parametres", "&Editer le pilote", 0, QApplication::UnicodeUTF8));
    btnEditDriver->setShortcut(QApplication::translate("Parametres", "Alt+E", 0, QApplication::UnicodeUTF8));
    btnDeleteDriver->setText(QApplication::translate("Parametres", "&Supprimer le pilote", 0, QApplication::UnicodeUTF8));
    btnDeleteDriver->setShortcut(QApplication::translate("Parametres", "Alt+S", 0, QApplication::UnicodeUTF8));
    TextLabel1_2->setText(QApplication::translate("Parametres", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">P I L O T E S</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    ongletsParametres->setTabText(ongletsParametres->indexOf(PilotesTab), QApplication::translate("Parametres", "Pilotes", 0, QApplication::UnicodeUTF8));
    btnSousCat->setText(QApplication::translate("Parametres", "Sous cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    btnDeleteCategory->setText(QApplication::translate("Parametres", "&Supprimer une cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    btnDeleteCategory->setShortcut(QApplication::translate("Parametres", "Alt+S", 0, QApplication::UnicodeUTF8));
    btnEditCategory->setText(QApplication::translate("Parametres", "&Editer une cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    btnEditCategory->setShortcut(QApplication::translate("Parametres", "Alt+E", 0, QApplication::UnicodeUTF8));
    btnAddCategory->setText(QApplication::translate("Parametres", "&Ajouter une cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    btnAddCategory->setShortcut(QApplication::translate("Parametres", "Alt+A", 0, QApplication::UnicodeUTF8));
    TextLabel1_3->setText(QApplication::translate("Parametres", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">C A T \303\211 G O R I E S</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    if (categoriesList->columnCount() < 3)
        categoriesList->setColumnCount(3);

    QTableWidgetItem *__colItem6 = new QTableWidgetItem();
    __colItem6->setText(QApplication::translate("Parametres", "id", 0, QApplication::UnicodeUTF8));
    categoriesList->setHorizontalHeaderItem(0, __colItem6);

    QTableWidgetItem *__colItem7 = new QTableWidgetItem();
    __colItem7->setText(QApplication::translate("Parametres", "Cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    categoriesList->setHorizontalHeaderItem(1, __colItem7);

    QTableWidgetItem *__colItem8 = new QTableWidgetItem();
    __colItem8->setText(QApplication::translate("Parametres", "Cat\303\251gorie parente", 0, QApplication::UnicodeUTF8));
    categoriesList->setHorizontalHeaderItem(2, __colItem8);
    ongletsParametres->setTabText(ongletsParametres->indexOf(CategoriesTab), QApplication::translate("Parametres", "Cat\303\251gories", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Parametres", "Options", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Parametres", "Minimum de tours pour \303\252tre qualifi\303\251 :", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Parametres", "(en pourcentage du nombre de tours du premier)", 0, QApplication::UnicodeUTF8));
    TextLabel1_3_3->setText(QApplication::translate("Parametres", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">R \303\210 G L E M E N T</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    if (pointsList->columnCount() < 2)
        pointsList->setColumnCount(2);

    QTableWidgetItem *__colItem9 = new QTableWidgetItem();
    __colItem9->setText(QApplication::translate("Parametres", "Position", 0, QApplication::UnicodeUTF8));
    pointsList->setHorizontalHeaderItem(0, __colItem9);

    QTableWidgetItem *__colItem10 = new QTableWidgetItem();
    __colItem10->setText(QApplication::translate("Parametres", "Points", 0, QApplication::UnicodeUTF8));
    pointsList->setHorizontalHeaderItem(1, __colItem10);
    btnAddPosition->setText(QApplication::translate("Parametres", "&Ajouter une position", 0, QApplication::UnicodeUTF8));
    btnAddPosition->setShortcut(QApplication::translate("Parametres", "Alt+A", 0, QApplication::UnicodeUTF8));
    btnEditPosition->setText(QApplication::translate("Parametres", "&Editer une position", 0, QApplication::UnicodeUTF8));
    btnEditPosition->setShortcut(QApplication::translate("Parametres", "Alt+E", 0, QApplication::UnicodeUTF8));
    ongletsParametres->setTabText(ongletsParametres->indexOf(ReglementTab), QApplication::translate("Parametres", "R\303\250glement", 0, QApplication::UnicodeUTF8));
    btnOk->setText(QApplication::translate("Parametres", "&OK", 0, QApplication::UnicodeUTF8));
    btnOk->setShortcut(QString());
    Q_UNUSED(Parametres);
    } // retranslateUi

};

namespace Ui {
    class Parametres: public Ui_Parametres {};
} // namespace Ui

#endif // UI_PARAMETRES_H
