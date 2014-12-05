/********************************************************************************
** Form generated from reading UI file 'battlefield.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEFIELD_H
#define UI_BATTLEFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_battlefield
{
public:
    QLabel *label;
    QPushButton *makeMove;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *fromMoveTwo;
    QLabel *nameOne;
    QLabel *fromMoveOne;
    QLabel *moveLabelOne;
    QLabel *toMoveOne;
    QLabel *fromLabTwo;
    QSpacerItem *verticalSpacer;
    QLabel *moveLabelTwo;
    QLabel *toLabTwo;
    QLabel *fromLabOne_2;
    QLabel *playerTwo;
    QLabel *playerOne;
    QLabel *fromLabOne;
    QLabel *nameTwo;
    QLabel *toMoveTwo;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *moveNumOne;
    QLabel *moveNumTwo;
    QLabel *oneType;
    QLabel *twoType;
    QFrame *line;

    void setupUi(QWidget *battlefield)
    {
        if (battlefield->objectName().isEmpty())
            battlefield->setObjectName(QStringLiteral("battlefield"));
        battlefield->resize(640, 480);
        QPalette palette;
        QBrush brush(QColor(252, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(254, 255, 248, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        battlefield->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Georgia"));
        battlefield->setFont(font);
        label = new QLabel(battlefield);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 181, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        makeMove = new QPushButton(battlefield);
        makeMove->setObjectName(QStringLiteral("makeMove"));
        makeMove->setGeometry(QRect(460, 440, 141, 31));
        gridLayoutWidget = new QWidget(battlefield);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(420, 70, 211, 364));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        fromMoveTwo = new QLabel(gridLayoutWidget);
        fromMoveTwo->setObjectName(QStringLiteral("fromMoveTwo"));

        gridLayout->addWidget(fromMoveTwo, 14, 1, 1, 1);

        nameOne = new QLabel(gridLayoutWidget);
        nameOne->setObjectName(QStringLiteral("nameOne"));
        nameOne->setFont(font);

        gridLayout->addWidget(nameOne, 1, 0, 1, 1);

        fromMoveOne = new QLabel(gridLayoutWidget);
        fromMoveOne->setObjectName(QStringLiteral("fromMoveOne"));

        gridLayout->addWidget(fromMoveOne, 5, 1, 1, 1);

        moveLabelOne = new QLabel(gridLayoutWidget);
        moveLabelOne->setObjectName(QStringLiteral("moveLabelOne"));

        gridLayout->addWidget(moveLabelOne, 4, 0, 1, 1);

        toMoveOne = new QLabel(gridLayoutWidget);
        toMoveOne->setObjectName(QStringLiteral("toMoveOne"));

        gridLayout->addWidget(toMoveOne, 6, 1, 1, 1);

        fromLabTwo = new QLabel(gridLayoutWidget);
        fromLabTwo->setObjectName(QStringLiteral("fromLabTwo"));

        gridLayout->addWidget(fromLabTwo, 14, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 1);

        moveLabelTwo = new QLabel(gridLayoutWidget);
        moveLabelTwo->setObjectName(QStringLiteral("moveLabelTwo"));

        gridLayout->addWidget(moveLabelTwo, 13, 0, 1, 1);

        toLabTwo = new QLabel(gridLayoutWidget);
        toLabTwo->setObjectName(QStringLiteral("toLabTwo"));

        gridLayout->addWidget(toLabTwo, 15, 0, 1, 1);

        fromLabOne_2 = new QLabel(gridLayoutWidget);
        fromLabOne_2->setObjectName(QStringLiteral("fromLabOne_2"));

        gridLayout->addWidget(fromLabOne_2, 6, 0, 1, 1);

        playerTwo = new QLabel(gridLayoutWidget);
        playerTwo->setObjectName(QStringLiteral("playerTwo"));
        QFont font2;
        font2.setFamily(QStringLiteral("Georgia"));
        font2.setPointSize(18);
        playerTwo->setFont(font2);

        gridLayout->addWidget(playerTwo, 9, 0, 1, 1);

        playerOne = new QLabel(gridLayoutWidget);
        playerOne->setObjectName(QStringLiteral("playerOne"));
        playerOne->setFont(font2);

        gridLayout->addWidget(playerOne, 0, 0, 1, 1);

        fromLabOne = new QLabel(gridLayoutWidget);
        fromLabOne->setObjectName(QStringLiteral("fromLabOne"));

        gridLayout->addWidget(fromLabOne, 5, 0, 1, 1);

        nameTwo = new QLabel(gridLayoutWidget);
        nameTwo->setObjectName(QStringLiteral("nameTwo"));
        nameTwo->setFont(font);

        gridLayout->addWidget(nameTwo, 10, 0, 1, 1);

        toMoveTwo = new QLabel(gridLayoutWidget);
        toMoveTwo->setObjectName(QStringLiteral("toMoveTwo"));

        gridLayout->addWidget(toMoveTwo, 15, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 12, 0, 1, 1);

        moveNumOne = new QLabel(gridLayoutWidget);
        moveNumOne->setObjectName(QStringLiteral("moveNumOne"));

        gridLayout->addWidget(moveNumOne, 3, 1, 1, 1);

        moveNumTwo = new QLabel(gridLayoutWidget);
        moveNumTwo->setObjectName(QStringLiteral("moveNumTwo"));

        gridLayout->addWidget(moveNumTwo, 12, 1, 1, 1);

        oneType = new QLabel(gridLayoutWidget);
        oneType->setObjectName(QStringLiteral("oneType"));

        gridLayout->addWidget(oneType, 2, 0, 1, 1);

        twoType = new QLabel(gridLayoutWidget);
        twoType->setObjectName(QStringLiteral("twoType"));

        gridLayout->addWidget(twoType, 11, 0, 1, 1);

        line = new QFrame(battlefield);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 50, 611, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(battlefield);

        QMetaObject::connectSlotsByName(battlefield);
    } // setupUi

    void retranslateUi(QWidget *battlefield)
    {
        battlefield->setWindowTitle(QApplication::translate("battlefield", "Form", 0));
        label->setText(QApplication::translate("battlefield", "Halma 3.0", 0));
        makeMove->setText(QApplication::translate("battlefield", "Make Next Move", 0));
        fromMoveTwo->setText(QString());
        nameOne->setText(QString());
        fromMoveOne->setText(QString());
        moveLabelOne->setText(QApplication::translate("battlefield", "Move", 0));
        toMoveOne->setText(QString());
        fromLabTwo->setText(QApplication::translate("battlefield", "From:", 0));
        moveLabelTwo->setText(QApplication::translate("battlefield", "Move", 0));
        toLabTwo->setText(QApplication::translate("battlefield", "To:", 0));
        fromLabOne_2->setText(QApplication::translate("battlefield", "To:", 0));
        playerTwo->setText(QApplication::translate("battlefield", "Player Two", 0));
        playerOne->setText(QApplication::translate("battlefield", "Player One", 0));
        fromLabOne->setText(QApplication::translate("battlefield", "From:", 0));
        nameTwo->setText(QString());
        toMoveTwo->setText(QString());
        label_2->setText(QApplication::translate("battlefield", "Move Number", 0));
        label_3->setText(QApplication::translate("battlefield", "Move Number", 0));
        moveNumOne->setText(QString());
        moveNumTwo->setText(QString());
        oneType->setText(QString());
        twoType->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class battlefield: public Ui_battlefield {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEFIELD_H
