#ifndef UI_NEWAPPLICATION_H
#define UI_NEWAPPLICATION_H

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

class Ui_NewApplication
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *applicationName;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *startCapture;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QLabel *textLabel5;
    QLabel *textLabel6;
    QFrame *frame;
    QGridLayout *gridLayout1;
    QLineEdit *className;

    void setupUi(QDialog *NewApplication)
    {
    NewApplication->setObjectName(QString::fromUtf8("NewApplication"));
    NewApplication->resize(QSize(325, 178).expandedTo(NewApplication->minimumSizeHint()));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(NewApplication->sizePolicy().hasHeightForWidth());
    NewApplication->setSizePolicy(sizePolicy);
    NewApplication->setSizeGripEnabled(false);
    NewApplication->setModal(true);
    gridLayout = new QGridLayout(NewApplication);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(NewApplication);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
    font.setPointSize(8);
    font.setBold(false);
    font.setItalic(false);
    font.setUnderline(false);
    font.setWeight(50);
    font.setStrikeOut(false);
    label->setFont(font);
    label->setScaledContents(true);
    label->setAlignment(Qt::AlignCenter);
    label->setWordWrap(true);

    gridLayout->addWidget(label, 4, 0, 1, 1);

    applicationName = new QLineEdit(NewApplication);
    applicationName->setObjectName(QString::fromUtf8("applicationName"));

    gridLayout->addWidget(applicationName, 1, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(41, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    startCapture = new QPushButton(NewApplication);
    startCapture->setObjectName(QString::fromUtf8("startCapture"));

    hboxLayout->addWidget(startCapture);

    buttonOk = new QPushButton(NewApplication);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
    buttonOk->setAutoDefault(false);
    buttonOk->setDefault(false);

    hboxLayout->addWidget(buttonOk);

    buttonCancel = new QPushButton(NewApplication);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
    buttonCancel->setAutoDefault(true);

    hboxLayout->addWidget(buttonCancel);


    gridLayout->addLayout(hboxLayout, 5, 0, 1, 1);

    textLabel5 = new QLabel(NewApplication);
    textLabel5->setObjectName(QString::fromUtf8("textLabel5"));

    gridLayout->addWidget(textLabel5, 0, 0, 1, 1);

    textLabel6 = new QLabel(NewApplication);
    textLabel6->setObjectName(QString::fromUtf8("textLabel6"));

    gridLayout->addWidget(textLabel6, 2, 0, 1, 1);

    frame = new QFrame(NewApplication);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Plain);
    gridLayout1 = new QGridLayout(frame);
    gridLayout1->setSpacing(0);
    gridLayout1->setMargin(0);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    className = new QLineEdit(frame);
    className->setObjectName(QString::fromUtf8("className"));
    className->setFrame(false);
    className->setAlignment(Qt::AlignHCenter);
    className->setReadOnly(true);

    gridLayout1->addWidget(className, 0, 0, 1, 1);


    gridLayout->addWidget(frame, 3, 0, 1, 1);

    retranslateUi(NewApplication);
    QObject::connect(buttonOk, SIGNAL(clicked()), NewApplication, SLOT(accept()));
    QObject::connect(buttonCancel, SIGNAL(clicked()), NewApplication, SLOT(reject()));

    QMetaObject::connectSlotsByName(NewApplication);
    } // setupUi

    void retranslateUi(QDialog *NewApplication)
    {
    NewApplication->setWindowTitle(QApplication::translate("NewApplication", "Nouveau logiciel", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("NewApplication", "Apr\303\250s avoir lanc\303\251 la capture, vous avez 5 secondes pour cliquer sur la fen\303\252tre du logiciel \303\240 param\303\251trer.", 0, QApplication::UnicodeUTF8));
    startCapture->setText(QApplication::translate("NewApplication", "Lancer la capture", 0, QApplication::UnicodeUTF8));
    buttonOk->setText(QApplication::translate("NewApplication", "OK", 0, QApplication::UnicodeUTF8));
    buttonOk->setShortcut(QApplication::translate("NewApplication", "", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("NewApplication", "Annuler", 0, QApplication::UnicodeUTF8));
    buttonCancel->setShortcut(QApplication::translate("NewApplication", "", 0, QApplication::UnicodeUTF8));
    textLabel5->setText(QApplication::translate("NewApplication", "Nom du logiciel :", 0, QApplication::UnicodeUTF8));
    textLabel6->setText(QApplication::translate("NewApplication", "Nom de la classe (lancez la capture) :", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(NewApplication);
    } // retranslateUi

};

namespace Ui {
    class NewApplication: public Ui_NewApplication {};
} // namespace Ui

#endif // UI_NEWAPPLICATION_H
