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
    QLabel *oneType;
    QLabel *moveNumTwo;
    QLabel *moveNumOne;
    QLabel *playerOne;
    QLabel *playerTwo;
    QLabel *label_3;
    QLabel *twoType;
    QLabel *nameOne;
    QSpacerItem *verticalSpacer;
    QLabel *nameTwo;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_4;
    QLabel *moveName;
    QLabel *gosling;
    QTableWidget *battleTable;

    void setupUi(QWidget *battlefield)
    {
        if (battlefield->objectName().isEmpty())
            battlefield->setObjectName(QStringLiteral("battlefield"));
        battlefield->resize(1173, 867);
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
        label->setGeometry(QRect(30, 10, 911, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        makeMove = new QPushButton(battlefield);
        makeMove->setObjectName(QStringLiteral("makeMove"));
        makeMove->setGeometry(QRect(290, 800, 141, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Georgia"));
        font2.setPointSize(14);
        makeMove->setFont(font2);
        gridLayoutWidget = new QWidget(battlefield);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(830, 100, 181, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        oneType = new QLabel(gridLayoutWidget);
        oneType->setObjectName(QStringLiteral("oneType"));
        QFont font3;
        font3.setFamily(QStringLiteral("Georgia"));
        font3.setItalic(true);
        oneType->setFont(font3);

        gridLayout->addWidget(oneType, 2, 0, 1, 1);

        moveNumTwo = new QLabel(gridLayoutWidget);
        moveNumTwo->setObjectName(QStringLiteral("moveNumTwo"));
        QFont font4;
        font4.setFamily(QStringLiteral("Georgia"));
        font4.setPointSize(24);
        moveNumTwo->setFont(font4);

        gridLayout->addWidget(moveNumTwo, 9, 1, 1, 1);

        moveNumOne = new QLabel(gridLayoutWidget);
        moveNumOne->setObjectName(QStringLiteral("moveNumOne"));
        moveNumOne->setFont(font4);

        gridLayout->addWidget(moveNumOne, 3, 1, 1, 1);

        playerOne = new QLabel(gridLayoutWidget);
        playerOne->setObjectName(QStringLiteral("playerOne"));
        QFont font5;
        font5.setFamily(QStringLiteral("Georgia"));
        font5.setPointSize(18);
        playerOne->setFont(font5);

        gridLayout->addWidget(playerOne, 0, 0, 1, 1);

        playerTwo = new QLabel(gridLayoutWidget);
        playerTwo->setObjectName(QStringLiteral("playerTwo"));
        playerTwo->setFont(font5);

        gridLayout->addWidget(playerTwo, 6, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 9, 0, 1, 1);

        twoType = new QLabel(gridLayoutWidget);
        twoType->setObjectName(QStringLiteral("twoType"));
        twoType->setFont(font3);

        gridLayout->addWidget(twoType, 8, 0, 1, 1);

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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        nameTwo = new QLabel(gridLayoutWidget);
        nameTwo->setObjectName(QStringLiteral("nameTwo"));
        QFont font7;
        font7.setFamily(QStringLiteral("Georgia"));
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setWeight(75);
        nameTwo->setFont(font7);

        gridLayout->addWidget(nameTwo, 7, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        line = new QFrame(battlefield);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 50, 1001, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(battlefield);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(920, 500, 241, 61));
        QFont font8;
        font8.setFamily(QStringLiteral("Georgia"));
        font8.setPointSize(36);
        label_4->setFont(font8);
        moveName = new QLabel(battlefield);
        moveName->setObjectName(QStringLiteral("moveName"));
        moveName->setGeometry(QRect(930, 560, 221, 171));
        moveName->setFont(font4);
        moveName->setFrameShape(QFrame::NoFrame);
        moveName->setScaledContents(true);
        moveName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        moveName->setWordWrap(true);
        gosling = new QLabel(battlefield);
        gosling->setObjectName(QStringLiteral("gosling"));
        gosling->setGeometry(QRect(750, 510, 171, 221));
        gosling->setPixmap(QPixmap(QString::fromUtf8(":/images/ryanGosling.png")));
        gosling->setScaledContents(true);
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

        retranslateUi(battlefield);

        QMetaObject::connectSlotsByName(battlefield);
    } // setupUi

    void retranslateUi(QWidget *battlefield)
    {
        battlefield->setWindowTitle(QApplication::translate("battlefield", "Halma Battlefield", 0));
        label->setText(QApplication::translate("battlefield", "Halma 3.1 (v. Gentle Feedback from Ryan Gosling)", 0));
        makeMove->setText(QApplication::translate("battlefield", "Have the AI Move", 0));
        oneType->setText(QString());
        moveNumTwo->setText(QString());
        moveNumOne->setText(QString());
        playerOne->setText(QApplication::translate("battlefield", "Player One", 0));
        playerTwo->setText(QApplication::translate("battlefield", "Player Two", 0));
        label_3->setText(QApplication::translate("battlefield", "Move Number", 0));
        twoType->setText(QString());
        nameOne->setText(QString());
        nameTwo->setText(QString());
        label_2->setText(QApplication::translate("battlefield", "Move Number", 0));
        label_4->setText(QApplication::translate("battlefield", "Oh hey,", 0));
        moveName->setText(QString());
        gosling->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class battlefield: public Ui_battlefield {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEFIELD_H
