/********************************************************************************
** Form generated from reading ui file 'Main.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_Main
{
public:
    QAction *actionNouvelleCourse;
    QAction *actionQuitter;
    QAction *actionParametres;
    QAction *actionSaisons;
    QAction *actionPilotes;
    QAction *actionCategories;
    QAction *actionReglement;
    QAction *actionAPropos;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout1;
    QVBoxLayout *vboxLayout;
    QLabel *textLabel1_2_2;
    QTableWidget *roundsList;
    QVBoxLayout *vboxLayout1;
    QLabel *textLabel1_2;
    QTableWidget *categoriesList;
    QHBoxLayout *hboxLayout;
    QPushButton *btnClassCategorie;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout2;
    QPushButton *btnPointage;
    QPushButton *btnAddRound;
    QPushButton *btnEditRound;
    QPushButton *btnDeleteRound;
    QSpacerItem *spacerItem1;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout3;
    QHBoxLayout *hboxLayout1;
    QLabel *textLabel1;
    QComboBox *seasonsList;
    QTableWidget *racesList;
    QGridLayout *gridLayout2;
    QPushButton *btnNewRace;
    QPushButton *btnEditRace;
    QPushButton *btnPilotesPresents;
    QPushButton *btnDeleteRace;
    QFrame *frame;
    QGridLayout *gridLayout3;
    QLabel *TextLabel1;
    QMenuBar *menubar;
    QMenu *menuFen_tres;
    QMenu *menu;
    QMenu *menuFichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main)
    {
    Main->setObjectName(QString::fromUtf8("Main"));
    actionNouvelleCourse = new QAction(Main);
    actionNouvelleCourse->setObjectName(QString::fromUtf8("actionNouvelleCourse"));
    actionQuitter = new QAction(Main);
    actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
    actionParametres = new QAction(Main);
    actionParametres->setObjectName(QString::fromUtf8("actionParametres"));
    actionSaisons = new QAction(Main);
    actionSaisons->setObjectName(QString::fromUtf8("actionSaisons"));
    actionPilotes = new QAction(Main);
    actionPilotes->setObjectName(QString::fromUtf8("actionPilotes"));
    actionCategories = new QAction(Main);
    actionCategories->setObjectName(QString::fromUtf8("actionCategories"));
    actionReglement = new QAction(Main);
    actionReglement->setObjectName(QString::fromUtf8("actionReglement"));
    actionAPropos = new QAction(Main);
    actionAPropos->setObjectName(QString::fromUtf8("actionAPropos"));
    centralwidget = new QWidget(Main);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox_2 = new QGroupBox(centralwidget);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout1 = new QGridLayout(groupBox_2);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    textLabel1_2_2 = new QLabel(groupBox_2);
    textLabel1_2_2->setObjectName(QString::fromUtf8("textLabel1_2_2"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(5));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(textLabel1_2_2->sizePolicy().hasHeightForWidth());
    textLabel1_2_2->setSizePolicy(sizePolicy);
    textLabel1_2_2->setMinimumSize(QSize(160, 0));
    textLabel1_2_2->setWordWrap(false);

    vboxLayout->addWidget(textLabel1_2_2);

    roundsList = new QTableWidget(groupBox_2);
    roundsList->setObjectName(QString::fromUtf8("roundsList"));
    roundsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    roundsList->setSelectionMode(QAbstractItemView::SingleSelection);
    roundsList->setSelectionBehavior(QAbstractItemView::SelectRows);

    vboxLayout->addWidget(roundsList);


    gridLayout1->addLayout(vboxLayout, 0, 1, 1, 1);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    textLabel1_2 = new QLabel(groupBox_2);
    textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
    textLabel1_2->setWordWrap(false);

    vboxLayout1->addWidget(textLabel1_2);

    categoriesList = new QTableWidget(groupBox_2);
    categoriesList->setObjectName(QString::fromUtf8("categoriesList"));
    categoriesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    categoriesList->setSelectionMode(QAbstractItemView::SingleSelection);
    categoriesList->setSelectionBehavior(QAbstractItemView::SelectRows);

    vboxLayout1->addWidget(categoriesList);


    gridLayout1->addLayout(vboxLayout1, 0, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    btnClassCategorie = new QPushButton(groupBox_2);
    btnClassCategorie->setObjectName(QString::fromUtf8("btnClassCategorie"));

    hboxLayout->addWidget(btnClassCategorie);

    spacerItem = new QSpacerItem(80, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    gridLayout1->addLayout(hboxLayout, 1, 0, 1, 3);

    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    btnPointage = new QPushButton(groupBox_2);
    btnPointage->setObjectName(QString::fromUtf8("btnPointage"));
    btnPointage->setAutoDefault(false);

    vboxLayout2->addWidget(btnPointage);

    btnAddRound = new QPushButton(groupBox_2);
    btnAddRound->setObjectName(QString::fromUtf8("btnAddRound"));

    vboxLayout2->addWidget(btnAddRound);

    btnEditRound = new QPushButton(groupBox_2);
    btnEditRound->setObjectName(QString::fromUtf8("btnEditRound"));

    vboxLayout2->addWidget(btnEditRound);

    btnDeleteRound = new QPushButton(groupBox_2);
    btnDeleteRound->setObjectName(QString::fromUtf8("btnDeleteRound"));

    vboxLayout2->addWidget(btnDeleteRound);

    spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout2->addItem(spacerItem1);


    gridLayout1->addLayout(vboxLayout2, 0, 2, 1, 1);


    gridLayout->addWidget(groupBox_2, 1, 1, 1, 1);

    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    vboxLayout3 = new QVBoxLayout(groupBox);
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(9);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    textLabel1 = new QLabel(groupBox);
    textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
    textLabel1->setWordWrap(false);

    hboxLayout1->addWidget(textLabel1);

    seasonsList = new QComboBox(groupBox);
    seasonsList->setObjectName(QString::fromUtf8("seasonsList"));

    hboxLayout1->addWidget(seasonsList);


    vboxLayout3->addLayout(hboxLayout1);

    racesList = new QTableWidget(groupBox);
    racesList->setObjectName(QString::fromUtf8("racesList"));
    racesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    racesList->setSelectionMode(QAbstractItemView::SingleSelection);
    racesList->setSelectionBehavior(QAbstractItemView::SelectRows);

    vboxLayout3->addWidget(racesList);

    gridLayout2 = new QGridLayout();
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(0);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    btnNewRace = new QPushButton(groupBox);
    btnNewRace->setObjectName(QString::fromUtf8("btnNewRace"));

    gridLayout2->addWidget(btnNewRace, 0, 0, 1, 1);

    btnEditRace = new QPushButton(groupBox);
    btnEditRace->setObjectName(QString::fromUtf8("btnEditRace"));

    gridLayout2->addWidget(btnEditRace, 0, 1, 1, 1);

    btnPilotesPresents = new QPushButton(groupBox);
    btnPilotesPresents->setObjectName(QString::fromUtf8("btnPilotesPresents"));

    gridLayout2->addWidget(btnPilotesPresents, 1, 0, 1, 1);

    btnDeleteRace = new QPushButton(groupBox);
    btnDeleteRace->setObjectName(QString::fromUtf8("btnDeleteRace"));

    gridLayout2->addWidget(btnDeleteRace, 1, 1, 1, 1);


    vboxLayout3->addLayout(gridLayout2);


    gridLayout->addWidget(groupBox, 1, 0, 1, 1);

    frame = new QFrame(centralwidget);
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
    TextLabel1->setPalette(palette1);
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    font.setWeight(75);
    TextLabel1->setFont(font);
    TextLabel1->setAutoFillBackground(true);
    TextLabel1->setAlignment(Qt::AlignCenter);
    TextLabel1->setWordWrap(false);

    gridLayout3->addWidget(TextLabel1, 0, 0, 1, 1);


    gridLayout->addWidget(frame, 0, 0, 1, 2);

    Main->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Main);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 811, 21));
    menuFen_tres = new QMenu(menubar);
    menuFen_tres->setObjectName(QString::fromUtf8("menuFen_tres"));
    menu = new QMenu(menubar);
    menu->setObjectName(QString::fromUtf8("menu"));
    menuFichier = new QMenu(menubar);
    menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
    Main->setMenuBar(menubar);
    statusbar = new QStatusBar(Main);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    Main->setStatusBar(statusbar);

    menubar->addAction(menuFichier->menuAction());
    menubar->addAction(menuFen_tres->menuAction());
    menubar->addAction(menu->menuAction());
    menuFen_tres->addAction(actionParametres);
    menuFen_tres->addSeparator();
    menuFen_tres->addAction(actionSaisons);
    menuFen_tres->addAction(actionPilotes);
    menuFen_tres->addAction(actionCategories);
    menuFen_tres->addAction(actionReglement);
    menu->addAction(actionAPropos);
    menuFichier->addAction(actionQuitter);

    retranslateUi(Main);

    QSize size(811, 555);
    size = size.expandedTo(Main->minimumSizeHint());
    Main->resize(size);


    QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QMainWindow *Main)
    {
    Main->setWindowTitle(QApplication::translate("Main", "Amorce50", 0, QApplication::UnicodeUTF8));
    actionNouvelleCourse->setText(QApplication::translate("Main", "Nouvelle course", 0, QApplication::UnicodeUTF8));
    actionQuitter->setText(QApplication::translate("Main", "Quitter", 0, QApplication::UnicodeUTF8));
    actionParametres->setText(QApplication::translate("Main", "Param\303\250tres", 0, QApplication::UnicodeUTF8));
    actionSaisons->setText(QApplication::translate("Main", "Saisons", 0, QApplication::UnicodeUTF8));
    actionPilotes->setText(QApplication::translate("Main", "Pilotes", 0, QApplication::UnicodeUTF8));
    actionCategories->setText(QApplication::translate("Main", "Cat\303\251gories", 0, QApplication::UnicodeUTF8));
    actionReglement->setText(QApplication::translate("Main", "R\303\250glement", 0, QApplication::UnicodeUTF8));
    actionAPropos->setText(QApplication::translate("Main", "\303\200 propos...", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("Main", "Epreuves", 0, QApplication::UnicodeUTF8));
    textLabel1_2_2->setText(QApplication::translate("Main", "<b><p align=\"center\">MANCHES</p></b>", 0, QApplication::UnicodeUTF8));
    if (roundsList->columnCount() < 3)
        roundsList->setColumnCount(3);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("Main", "id", 0, QApplication::UnicodeUTF8));
    roundsList->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("Main", "Manche", 0, QApplication::UnicodeUTF8));
    roundsList->setHorizontalHeaderItem(1, __colItem1);

    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    __colItem2->setText(QApplication::translate("Main", "Statut", 0, QApplication::UnicodeUTF8));
    roundsList->setHorizontalHeaderItem(2, __colItem2);
    textLabel1_2->setText(QApplication::translate("Main", "<b><p align=\"center\">CATEGORIES</p></b>", 0, QApplication::UnicodeUTF8));
    if (categoriesList->columnCount() < 2)
        categoriesList->setColumnCount(2);

    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    __colItem3->setText(QApplication::translate("Main", "id", 0, QApplication::UnicodeUTF8));
    categoriesList->setHorizontalHeaderItem(0, __colItem3);

    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    __colItem4->setText(QApplication::translate("Main", "Nom", 0, QApplication::UnicodeUTF8));
    categoriesList->setHorizontalHeaderItem(1, __colItem4);
    btnClassCategorie->setText(QApplication::translate("Main", "&Classement de la cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    btnClassCategorie->setShortcut(QApplication::translate("Main", "Alt+C", 0, QApplication::UnicodeUTF8));
    btnPointage->setText(QApplication::translate("Main", "&Pointage", 0, QApplication::UnicodeUTF8));
    btnPointage->setShortcut(QApplication::translate("Main", "Alt+P", 0, QApplication::UnicodeUTF8));
    btnAddRound->setText(QApplication::translate("Main", "Ajouter", 0, QApplication::UnicodeUTF8));
    btnEditRound->setText(QApplication::translate("Main", "E&diter", 0, QApplication::UnicodeUTF8));
    btnEditRound->setShortcut(QApplication::translate("Main", "Alt+D", 0, QApplication::UnicodeUTF8));
    btnDeleteRound->setText(QApplication::translate("Main", "Supprimer", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Main", "Liste des courses", 0, QApplication::UnicodeUTF8));
    textLabel1->setText(QApplication::translate("Main", "Saison :", 0, QApplication::UnicodeUTF8));
    if (racesList->columnCount() < 3)
        racesList->setColumnCount(3);

    QTableWidgetItem *__colItem5 = new QTableWidgetItem();
    __colItem5->setText(QApplication::translate("Main", "id", 0, QApplication::UnicodeUTF8));
    racesList->setHorizontalHeaderItem(0, __colItem5);

    QTableWidgetItem *__colItem6 = new QTableWidgetItem();
    __colItem6->setText(QApplication::translate("Main", "Lieu", 0, QApplication::UnicodeUTF8));
    racesList->setHorizontalHeaderItem(1, __colItem6);

    QTableWidgetItem *__colItem7 = new QTableWidgetItem();
    __colItem7->setText(QApplication::translate("Main", "Date", 0, QApplication::UnicodeUTF8));
    racesList->setHorizontalHeaderItem(2, __colItem7);
    btnNewRace->setText(QApplication::translate("Main", "&Nouvelle course", 0, QApplication::UnicodeUTF8));
    btnNewRace->setShortcut(QApplication::translate("Main", "Alt+N", 0, QApplication::UnicodeUTF8));
    btnEditRace->setText(QApplication::translate("Main", "&Editer", 0, QApplication::UnicodeUTF8));
    btnEditRace->setShortcut(QApplication::translate("Main", "Alt+E", 0, QApplication::UnicodeUTF8));
    btnPilotesPresents->setText(QApplication::translate("Main", "Pilotes pr\303\251sents", 0, QApplication::UnicodeUTF8));
    btnPilotesPresents->setShortcut(QString());
    btnDeleteRace->setText(QApplication::translate("Main", "&Supprimer", 0, QApplication::UnicodeUTF8));
    btnDeleteRace->setShortcut(QApplication::translate("Main", "Alt+S", 0, QApplication::UnicodeUTF8));
    TextLabel1->setText(QApplication::translate("Main", "C O U R S E S     E T     E P R E U V E S", 0, QApplication::UnicodeUTF8));
    menuFen_tres->setTitle(QApplication::translate("Main", "Fen\303\252tres", 0, QApplication::UnicodeUTF8));
    menu->setTitle(QApplication::translate("Main", "?", 0, QApplication::UnicodeUTF8));
    menuFichier->setTitle(QApplication::translate("Main", "Fichier", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

#endif // UI_MAIN_H
