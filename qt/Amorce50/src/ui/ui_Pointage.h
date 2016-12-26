/********************************************************************************
** Form generated from reading ui file 'Pointage.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_POINTAGE_H
#define UI_POINTAGE_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_Pointage
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QTextEdit *textPointage;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1;
    QSpinBox *premier;
    QFrame *frame;
    QGridLayout *gridLayout1;
    QLabel *lblTitre;
    QVBoxLayout *vboxLayout1;
    QTableWidget *resultList;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *btnToggleQualif;
    QHBoxLayout *hboxLayout2;
    QPushButton *btnGrille;
    QPushButton *btnSauvePointage;
    QPushButton *btnCalculer;
    QSpacerItem *spacerItem1;
    QPushButton *btnSauver;
    QPushButton *btnAnnuler;
    QFrame *Line3;

    void setupUi(QDialog *Pointage)
    {
    Pointage->setObjectName(QString::fromUtf8("Pointage"));
    gridLayout = new QGridLayout(Pointage);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(Pointage);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    vboxLayout = new QVBoxLayout(groupBox);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    vboxLayout->addWidget(label);

    textPointage = new QTextEdit(groupBox);
    textPointage->setObjectName(QString::fromUtf8("textPointage"));
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    textPointage->setFont(font);

    vboxLayout->addWidget(textPointage);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    textLabel1 = new QLabel(groupBox);
    textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
    textLabel1->setWordWrap(false);

    hboxLayout->addWidget(textLabel1);

    premier = new QSpinBox(groupBox);
    premier->setObjectName(QString::fromUtf8("premier"));
    premier->setMaximum(1000);
    premier->setMinimum(1);

    hboxLayout->addWidget(premier);


    vboxLayout->addLayout(hboxLayout);


    gridLayout->addWidget(groupBox, 1, 0, 1, 1);

    frame = new QFrame(Pointage);
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
    lblTitre = new QLabel(frame);
    lblTitre->setObjectName(QString::fromUtf8("lblTitre"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(lblTitre->sizePolicy().hasHeightForWidth());
    lblTitre->setSizePolicy(sizePolicy);
    lblTitre->setMinimumSize(QSize(0, 0));
    lblTitre->setMaximumSize(QSize(32767, 32767));
    QFont font1;
    font1.setPointSize(16);
    font1.setBold(true);
    font1.setWeight(75);
    lblTitre->setFont(font1);
    lblTitre->setAlignment(Qt::AlignCenter);
    lblTitre->setWordWrap(false);

    gridLayout1->addWidget(lblTitre, 0, 0, 1, 1);


    gridLayout->addWidget(frame, 0, 0, 1, 2);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    resultList = new QTableWidget(Pointage);
    resultList->setObjectName(QString::fromUtf8("resultList"));
    resultList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    resultList->setSelectionMode(QAbstractItemView::SingleSelection);
    resultList->setSelectionBehavior(QAbstractItemView::SelectRows);

    vboxLayout1->addWidget(resultList);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);

    btnToggleQualif = new QPushButton(Pointage);
    btnToggleQualif->setObjectName(QString::fromUtf8("btnToggleQualif"));

    hboxLayout1->addWidget(btnToggleQualif);


    vboxLayout1->addLayout(hboxLayout1);


    gridLayout->addLayout(vboxLayout1, 1, 1, 1, 1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    btnGrille = new QPushButton(Pointage);
    btnGrille->setObjectName(QString::fromUtf8("btnGrille"));

    hboxLayout2->addWidget(btnGrille);

    btnSauvePointage = new QPushButton(Pointage);
    btnSauvePointage->setObjectName(QString::fromUtf8("btnSauvePointage"));

    hboxLayout2->addWidget(btnSauvePointage);

    btnCalculer = new QPushButton(Pointage);
    btnCalculer->setObjectName(QString::fromUtf8("btnCalculer"));
    btnCalculer->setCheckable(false);
    btnCalculer->setFlat(false);

    hboxLayout2->addWidget(btnCalculer);

    spacerItem1 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem1);

    btnSauver = new QPushButton(Pointage);
    btnSauver->setObjectName(QString::fromUtf8("btnSauver"));
    btnSauver->setCheckable(false);
    btnSauver->setFlat(false);

    hboxLayout2->addWidget(btnSauver);

    btnAnnuler = new QPushButton(Pointage);
    btnAnnuler->setObjectName(QString::fromUtf8("btnAnnuler"));

    hboxLayout2->addWidget(btnAnnuler);


    gridLayout->addLayout(hboxLayout2, 3, 0, 1, 2);

    Line3 = new QFrame(Pointage);
    Line3->setObjectName(QString::fromUtf8("Line3"));
    Line3->setFrameShape(QFrame::HLine);
    Line3->setFrameShadow(QFrame::Sunken);
    Line3->setFrameShape(QFrame::HLine);
    Line3->setFrameShadow(QFrame::Sunken);

    gridLayout->addWidget(Line3, 2, 0, 1, 2);


    retranslateUi(Pointage);

    QSize size(802, 569);
    size = size.expandedTo(Pointage->minimumSizeHint());
    Pointage->resize(size);

    QObject::connect(btnAnnuler, SIGNAL(clicked()), Pointage, SLOT(reject()));

    QMetaObject::connectSlotsByName(Pointage);
    } // setupUi

    void retranslateUi(QDialog *Pointage)
    {
    Pointage->setWindowTitle(QApplication::translate("Pointage", "Pointage de la manche", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Pointage", "Pointage", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Pointage", "Entrez ci-dessous le pointage de la course.\n"
"S\303\251parez chaque num\303\251ro de pilote par un espace ou une virgule.", 0, QApplication::UnicodeUTF8));
    textLabel1->setText(QApplication::translate("Pointage", "Num\303\251ro du premier pilote \303\240 l'arriv\303\251e :", 0, QApplication::UnicodeUTF8));
    lblTitre->setText(QApplication::translate("Pointage", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">titre + cat\303\251gorie</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    if (resultList->columnCount() < 6)
        resultList->setColumnCount(6);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("Pointage", "id_pilote", 0, QApplication::UnicodeUTF8));
    resultList->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("Pointage", "Pilote", 0, QApplication::UnicodeUTF8));
    resultList->setHorizontalHeaderItem(1, __colItem1);

    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    __colItem2->setText(QApplication::translate("Pointage", "Num\303\251ro", 0, QApplication::UnicodeUTF8));
    resultList->setHorizontalHeaderItem(2, __colItem2);

    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    __colItem3->setText(QApplication::translate("Pointage", "Nombre de tours", 0, QApplication::UnicodeUTF8));
    resultList->setHorizontalHeaderItem(3, __colItem3);

    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    __colItem4->setText(QApplication::translate("Pointage", "Place", 0, QApplication::UnicodeUTF8));
    resultList->setHorizontalHeaderItem(4, __colItem4);

    QTableWidgetItem *__colItem5 = new QTableWidgetItem();
    __colItem5->setText(QApplication::translate("Pointage", "Points", 0, QApplication::UnicodeUTF8));
    resultList->setHorizontalHeaderItem(5, __colItem5);
    btnToggleQualif->setText(QApplication::translate("Pointage", "Disqualifier/requalifier", 0, QApplication::UnicodeUTF8));
    btnGrille->setText(QApplication::translate("Pointage", "&Grille de d\303\251part", 0, QApplication::UnicodeUTF8));
    btnGrille->setShortcut(QApplication::translate("Pointage", "Alt+G", 0, QApplication::UnicodeUTF8));
    btnSauvePointage->setText(QApplication::translate("Pointage", "Sauvegarder le pointage", 0, QApplication::UnicodeUTF8));
    btnSauvePointage->setShortcut(QString());
    btnCalculer->setText(QApplication::translate("Pointage", "&Calculer la grille d'arriv\303\251e", 0, QApplication::UnicodeUTF8));
    btnCalculer->setShortcut(QApplication::translate("Pointage", "Alt+C", 0, QApplication::UnicodeUTF8));
    btnSauver->setText(QApplication::translate("Pointage", "&Valider le classement et quitter", 0, QApplication::UnicodeUTF8));
    btnSauver->setShortcut(QApplication::translate("Pointage", "Alt+V", 0, QApplication::UnicodeUTF8));
    btnAnnuler->setText(QApplication::translate("Pointage", "&Fermer", 0, QApplication::UnicodeUTF8));
    btnAnnuler->setShortcut(QApplication::translate("Pointage", "Alt+F", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Pointage);
    } // retranslateUi

};

namespace Ui {
    class Pointage: public Ui_Pointage {};
} // namespace Ui

#endif // UI_POINTAGE_H
