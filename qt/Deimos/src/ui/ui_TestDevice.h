#ifndef UI_TESTDEVICE_H
#define UI_TESTDEVICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

class Ui_TestDevice
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *keyCodeA;
    QLabel *label_2;
    QLineEdit *keyCodeB;
    QLabel *label_3;
    QLineEdit *keyCodeC;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *okButton;

    void setupUi(QDialog *TestDevice)
    {
    TestDevice->setObjectName(QString::fromUtf8("TestDevice"));
    TestDevice->resize(QSize(318, 132).expandedTo(TestDevice->minimumSizeHint()));
    gridLayout = new QGridLayout(TestDevice);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(TestDevice);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    hboxLayout->addWidget(label);

    keyCodeA = new QLineEdit(groupBox);
    keyCodeA->setObjectName(QString::fromUtf8("keyCodeA"));
    keyCodeA->setAlignment(Qt::AlignHCenter);
    keyCodeA->setReadOnly(true);

    hboxLayout->addWidget(keyCodeA);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    hboxLayout->addWidget(label_2);

    keyCodeB = new QLineEdit(groupBox);
    keyCodeB->setObjectName(QString::fromUtf8("keyCodeB"));
    keyCodeB->setAlignment(Qt::AlignHCenter);
    keyCodeB->setReadOnly(true);

    hboxLayout->addWidget(keyCodeB);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    hboxLayout->addWidget(label_3);

    keyCodeC = new QLineEdit(groupBox);
    keyCodeC->setObjectName(QString::fromUtf8("keyCodeC"));
    keyCodeC->setAlignment(Qt::AlignHCenter);
    keyCodeC->setReadOnly(true);

    hboxLayout->addWidget(keyCodeC);


    gridLayout1->addLayout(hboxLayout, 0, 0, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);

    okButton = new QPushButton(TestDevice);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout1->addWidget(okButton);


    gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);

    retranslateUi(TestDevice);
    QObject::connect(okButton, SIGNAL(clicked()), TestDevice, SLOT(accept()));

    QMetaObject::connectSlotsByName(TestDevice);
    } // setupUi

    void retranslateUi(QDialog *TestDevice)
    {
    TestDevice->setWindowTitle(QApplication::translate("TestDevice", "Test", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("TestDevice", "Test de la r\303\251ception", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("TestDevice", "Code :", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("TestDevice", ":", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("TestDevice", ":", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("TestDevice", "OK", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(TestDevice);
    } // retranslateUi

};

namespace Ui {
    class TestDevice: public Ui_TestDevice {};
} // namespace Ui

#endif // UI_TESTDEVICE_H
