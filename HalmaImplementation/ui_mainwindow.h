/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionSomething;
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_5;
    QLineEdit *namePlayerOne;
    QFrame *frame;
    QRadioButton *playerOneAI;
    QRadioButton *playerOneHuman;
    QLabel *label_3;
    QLineEdit *playerOneURL;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label_6;
    QLineEdit *namePlayerTwo;
    QFrame *frame_2;
    QRadioButton *playerTwoHuman;
    QRadioButton *playerTwoAI;
    QLabel *label_4;
    QLineEdit *playerTwoURL;
    QPushButton *pushButton;
    QLabel *HalmaLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(358, 551);
        QPalette palette;
        QBrush brush(QColor(212, 221, 228, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(254, 255, 250, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(139, 124, 102, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        MainWindow->setPalette(palette);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionSomething = new QAction(MainWindow);
        actionSomething->setObjectName(QStringLiteral("actionSomething"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QFont font;
        font.setFamily(QStringLiteral("Georgia"));
        centralWidget->setFont(font);
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 70, 261, 371));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Georgia"));
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        namePlayerOne = new QLineEdit(formLayoutWidget);
        namePlayerOne->setObjectName(QStringLiteral("namePlayerOne"));

        formLayout->setWidget(1, QFormLayout::FieldRole, namePlayerOne);

        frame = new QFrame(formLayoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(200, 30));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        playerOneAI = new QRadioButton(frame);
        playerOneAI->setObjectName(QStringLiteral("playerOneAI"));
        playerOneAI->setGeometry(QRect(10, 10, 146, 19));
        playerOneHuman = new QRadioButton(frame);
        playerOneHuman->setObjectName(QStringLiteral("playerOneHuman"));
        playerOneHuman->setGeometry(QRect(170, 10, 69, 19));

        formLayout->setWidget(2, QFormLayout::SpanningRole, frame);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        playerOneURL = new QLineEdit(formLayoutWidget);
        playerOneURL->setObjectName(QStringLiteral("playerOneURL"));

        formLayout->setWidget(5, QFormLayout::FieldRole, playerOneURL);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(7, QFormLayout::LabelRole, verticalSpacer);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_2);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_6);

        namePlayerTwo = new QLineEdit(formLayoutWidget);
        namePlayerTwo->setObjectName(QStringLiteral("namePlayerTwo"));

        formLayout->setWidget(9, QFormLayout::FieldRole, namePlayerTwo);

        frame_2 = new QFrame(formLayoutWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(200, 30));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        playerTwoHuman = new QRadioButton(frame_2);
        playerTwoHuman->setObjectName(QStringLiteral("playerTwoHuman"));
        playerTwoHuman->setGeometry(QRect(170, 0, 69, 19));
        playerTwoAI = new QRadioButton(frame_2);
        playerTwoAI->setObjectName(QStringLiteral("playerTwoAI"));
        playerTwoAI->setGeometry(QRect(10, 0, 146, 19));

        formLayout->setWidget(11, QFormLayout::SpanningRole, frame_2);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(12, QFormLayout::LabelRole, label_4);

        playerTwoURL = new QLineEdit(formLayoutWidget);
        playerTwoURL->setObjectName(QStringLiteral("playerTwoURL"));

        formLayout->setWidget(12, QFormLayout::FieldRole, playerTwoURL);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 450, 113, 32));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        pushButton->setFont(font3);
        HalmaLabel = new QLabel(centralWidget);
        HalmaLabel->setObjectName(QStringLiteral("HalmaLabel"));
        HalmaLabel->setGeometry(QRect(30, 10, 281, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(36);
        font4.setBold(true);
        font4.setWeight(75);
        HalmaLabel->setFont(font4);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 358, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Halma 3.0", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0));
        actionSomething->setText(QApplication::translate("MainWindow", "Something", 0));
        label->setText(QApplication::translate("MainWindow", "Player One", 0));
        label_5->setText(QApplication::translate("MainWindow", "Player Name", 0));
        playerOneAI->setText(QApplication::translate("MainWindow", "Artificial Intelligence", 0));
        playerOneHuman->setText(QApplication::translate("MainWindow", "Human", 0));
        label_3->setText(QApplication::translate("MainWindow", "URL:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Player Two", 0));
        label_6->setText(QApplication::translate("MainWindow", "Player Name", 0));
        playerTwoHuman->setText(QApplication::translate("MainWindow", "Human", 0));
        playerTwoAI->setText(QApplication::translate("MainWindow", "Artificial Intelligence", 0));
        label_4->setText(QApplication::translate("MainWindow", "URL:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Start Game", 0));
        HalmaLabel->setText(QApplication::translate("MainWindow", "Halma 3.0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
