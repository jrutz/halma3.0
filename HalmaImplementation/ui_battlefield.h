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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_battlefield
{
public:
    QLabel *label;
    QPushButton *makeMove;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *moveNumOne;
    QSpacerItem *verticalSpacer;
    QLabel *playerOne;
    QLabel *nameTwo;
    QLabel *oneType;
    QLabel *nameOne;
    QLabel *label_3;
    QLabel *playerTwo;
    QLabel *label_2;
    QLabel *moveNumTwo;
    QLabel *twoType;
    QFrame *line;
    QTableWidget *battleTable;
    QLabel *label_4;
    QLabel *moveName;

    void setupUi(QWidget *battlefield)
    {
        if (battlefield->objectName().isEmpty())
            battlefield->setObjectName(QStringLiteral("battlefield"));
        battlefield->resize(1069, 1509);
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
        makeMove->setGeometry(QRect(870, 460, 141, 31));
        gridLayoutWidget = new QWidget(battlefield);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(810, 40, 211, 374));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        moveNumOne = new QLabel(gridLayoutWidget);
        moveNumOne->setObjectName(QStringLiteral("moveNumOne"));
        QFont font2;
        font2.setFamily(QStringLiteral("Georgia"));
        font2.setPointSize(24);
        moveNumOne->setFont(font2);

        gridLayout->addWidget(moveNumOne, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        playerOne = new QLabel(gridLayoutWidget);
        playerOne->setObjectName(QStringLiteral("playerOne"));
        QFont font3;
        font3.setFamily(QStringLiteral("Georgia"));
        font3.setPointSize(18);
        playerOne->setFont(font3);

        gridLayout->addWidget(playerOne, 0, 0, 1, 1);

        nameTwo = new QLabel(gridLayoutWidget);
        nameTwo->setObjectName(QStringLiteral("nameTwo"));
        QFont font4;
        font4.setFamily(QStringLiteral("Georgia"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        nameTwo->setFont(font4);

        gridLayout->addWidget(nameTwo, 7, 0, 1, 1);

        oneType = new QLabel(gridLayoutWidget);
        oneType->setObjectName(QStringLiteral("oneType"));
        QFont font5;
        font5.setFamily(QStringLiteral("Georgia"));
        font5.setItalic(true);
        oneType->setFont(font5);

        gridLayout->addWidget(oneType, 2, 0, 1, 1);

        nameOne = new QLabel(gridLayoutWidget);
        nameOne->setObjectName(QStringLiteral("nameOne"));
        QFont font6;
        font6.setFamily(QStringLiteral("Georgia"));
        font6.setPointSize(18);
        font6.setBold(true);
        font6.setWeight(75);
        font6.setKerning(false);
        font6.setStyleStrategy(QFont::NoAntialias);
        nameOne->setFont(font6);

        gridLayout->addWidget(nameOne, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 9, 0, 1, 1);

        playerTwo = new QLabel(gridLayoutWidget);
        playerTwo->setObjectName(QStringLiteral("playerTwo"));
        playerTwo->setFont(font3);

        gridLayout->addWidget(playerTwo, 6, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        moveNumTwo = new QLabel(gridLayoutWidget);
        moveNumTwo->setObjectName(QStringLiteral("moveNumTwo"));
        moveNumTwo->setFont(font2);

        gridLayout->addWidget(moveNumTwo, 9, 1, 1, 1);

        twoType = new QLabel(gridLayoutWidget);
        twoType->setObjectName(QStringLiteral("twoType"));
        twoType->setFont(font5);

        gridLayout->addWidget(twoType, 8, 0, 1, 1);

        line = new QFrame(battlefield);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 50, 611, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        battleTable = new QTableWidget(battlefield);
        if (battleTable->columnCount() < 18)
            battleTable->setColumnCount(18);
        if (battleTable->rowCount() < 18)
            battleTable->setRowCount(18);
        battleTable->setObjectName(QStringLiteral("battleTable"));
        battleTable->setGeometry(QRect(30, 80, 702, 702));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(battleTable->sizePolicy().hasHeightForWidth());
        battleTable->setSizePolicy(sizePolicy);
        battleTable->setMinimumSize(QSize(702, 702));
        battleTable->setMaximumSize(QSize(702, 702));
        battleTable->setBaseSize(QSize(702, 702));
        battleTable->setAutoFillBackground(false);
        battleTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        battleTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        battleTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        battleTable->setTabKeyNavigation(false);
        battleTable->setProperty("showDropIndicator", QVariant(false));
        battleTable->setDragDropOverwriteMode(false);
        battleTable->setAlternatingRowColors(false);
        battleTable->setSelectionMode(QAbstractItemView::NoSelection);
        battleTable->setIconSize(QSize(39, 39));
        battleTable->setGridStyle(Qt::DotLine);
        battleTable->setWordWrap(false);
        battleTable->setCornerButtonEnabled(false);
        battleTable->setRowCount(18);
        battleTable->setColumnCount(18);
        battleTable->horizontalHeader()->setVisible(false);
        battleTable->horizontalHeader()->setDefaultSectionSize(39);
        battleTable->horizontalHeader()->setHighlightSections(false);
        battleTable->horizontalHeader()->setMinimumSectionSize(39);
        battleTable->verticalHeader()->setVisible(false);
        battleTable->verticalHeader()->setDefaultSectionSize(39);
        battleTable->verticalHeader()->setMinimumSectionSize(39);
        label_4 = new QLabel(battlefield);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 820, 241, 61));
        QFont font7;
        font7.setFamily(QStringLiteral("Georgia"));
        font7.setPointSize(36);
        label_4->setFont(font7);
        moveName = new QLabel(battlefield);
        moveName->setObjectName(QStringLiteral("moveName"));
        moveName->setGeometry(QRect(260, 830, 571, 41));
        moveName->setFont(font2);

        retranslateUi(battlefield);

        QMetaObject::connectSlotsByName(battlefield);
    } // setupUi

    void retranslateUi(QWidget *battlefield)
    {
        battlefield->setWindowTitle(QApplication::translate("battlefield", "Halma Battlefield", 0));
        label->setText(QApplication::translate("battlefield", "Halma 3.0", 0));
        makeMove->setText(QApplication::translate("battlefield", "Make Next Move", 0));
        moveNumOne->setText(QString());
        playerOne->setText(QApplication::translate("battlefield", "Player One", 0));
        nameTwo->setText(QString());
        oneType->setText(QString());
        nameOne->setText(QString());
        label_3->setText(QApplication::translate("battlefield", "Move Number", 0));
        playerTwo->setText(QApplication::translate("battlefield", "Player Two", 0));
        label_2->setText(QApplication::translate("battlefield", "Move Number", 0));
        moveNumTwo->setText(QString());
        twoType->setText(QString());
        label_4->setText(QApplication::translate("battlefield", "Make a move:", 0));
        moveName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class battlefield: public Ui_battlefield {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEFIELD_H
