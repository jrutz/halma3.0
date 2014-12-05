#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>
#include <QIcon>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QVector>

#include "memoryhandler.h"



using namespace std;

/* NEEDS TO KNOW:
 *What button was pushed
 *Return the name of the image in that button
 *Set a new image if necessary
 *Timers etc.
 *
 *First Button = until 5 seconds after second button.
 *Disables all other buttons while that occurs.
 *Check if other buttons should be disabled.
 *Check which click it is.
*/


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->dynamicWinner->hide(); //Hides the winner GUI
    ui->easyButton->setChecked(true); //Automatically sets the program to easy

    //Hides everything that has to do with the hard level

   level = 1;
   disableHard();
   numberOfScores = 1;
   ui->match9->hide();
   ui->match10->hide();
   ui->match11->hide();
   ui->match12->hide();
   ui->saveScoreButton->setDisabled(true);
   setScores();
}

GameWindow::~GameWindow()
{
    delete ui;
}

//Sets the two pushed buttons to the base
void GameWindow :: setPicture()
{
    primaryButton->setIcon(QIcon(":/easy/base"));
    secondaryButton->setIcon(QIcon(":/easy/base"));
}

//Disables buttons associated with hard level
void GameWindow :: disableHard()
{
    ui->hardButton_1->hide();
    ui->hardButton_2->hide();
    ui->hardButton_3->hide();
    ui->hardButton_4->hide();
    ui->hardButton_5->hide();
    ui->hardButton_6->hide();
    ui->hardButton_7->hide();
    ui->hardButton_8->hide();
}

//Sets to visible buttons associated with hard level
void GameWindow:: enableHard()
{
    ui->hardButton_1->setVisible(true);
    ui->hardButton_2->setVisible(true);
    ui->hardButton_3->setVisible(true);
    ui->hardButton_4->setVisible(true);
    ui->hardButton_5->setVisible(true);
    ui->hardButton_6->setVisible(true);
    ui->hardButton_7->setVisible(true);
    ui->hardButton_8->setVisible(true);

    ui->match9->setVisible(true);
    ui->match10->setVisible(true);
    ui->match11->setVisible(true);
    ui->match12->setVisible(true);
}

//Hides everything
void GameWindow::disableEverything()
{
    ui->button_1->hide();
    ui->button_2->hide();
    ui->button_3->hide();
    ui->button_4->hide();
    ui->button_5->hide();
    ui->button_6->hide();
    ui->button_7->hide();
    ui->button_8->hide();
    ui->button_9->hide();
    ui->button_10->hide();
    ui->button_11->hide();
    ui->button_12->hide();
    ui->button_13->hide();
    ui->button_14->hide();
    ui->button_15->hide();
    ui->button_16->hide();
}

//Makes everything visible
void GameWindow:: connectEverything()
{
    ui->button_1->setVisible(true);
    ui->button_2->setVisible(true);
    ui->button_3->setVisible(true);
    ui->button_4->setVisible(true);
    ui->button_5->setVisible(true);
    ui->button_6->setVisible(true);
    ui->button_7->setVisible(true);
    ui->button_8->setVisible(true);
    ui->button_9->setVisible(true);
    ui->button_10->setVisible(true);
    ui->button_11->setVisible(true);
    ui->button_12->setVisible(true);
    ui->button_13->setVisible(true);
    ui->button_14->setVisible(true);
    ui->button_15->setVisible(true);
    ui->button_16->setVisible(true);

}

//Enables every single button
void GameWindow::enableEverything()
{

        ui->button_1->setEnabled(true);
        ui->button_2->setEnabled(true);
        ui->button_3->setEnabled(true);
        ui->button_4->setEnabled(true);
        ui->button_5->setEnabled(true);
        ui->button_6->setEnabled(true);
        ui->button_7->setEnabled(true);
        ui->button_8->setEnabled(true);
        ui->button_9->setEnabled(true);
        ui->button_10->setEnabled(true);
        ui->button_11->setEnabled(true);
        ui->button_12->setEnabled(true);
        ui->button_13->setEnabled(true);
        ui->button_14->setEnabled(true);
        ui->button_15->setEnabled(true);
        ui->button_16->setEnabled(true);


        ui->hardButton_1->setEnabled(true);
        ui->hardButton_2->setEnabled(true);
        ui->hardButton_3->setEnabled(true);
        ui->hardButton_4->setEnabled(true);
        ui->hardButton_5->setEnabled(true);
        ui->hardButton_6->setEnabled(true);
        ui->hardButton_7->setEnabled(true);
        ui->hardButton_8->setEnabled(true);

}

//Sets up a new gameplay on easy, re-randomizes board, resets matches & tries.
void GameWindow::on_easyButton_clicked()
{
    handle.randomizeEasy();
    disableHard();
    matchesNum = 0;
    tries = 0;
    level = 1;
    ui->dynamicMatches->setText("0");
    ui->dynamicTries->setText("0");
    ui->dynamicWinner->hide();
    enableEverything();


    ui->match9->hide();
    ui->match10->hide();
    ui->match11->hide();
    ui->match12->hide();
    hideMatches();
    ui->saveScoreButton->setDisabled(true);
}

//Sets up a new gameplay on hard, re-randomizes board, resets matches & tries.
void GameWindow::on_hardButton_clicked()
{

    enableHard();
    matchesNum = 0;
    tries = 0;
    level = 2;
    ui->dynamicMatches->setText("0");
    ui->dynamicTries->setText("0");
    ui->dynamicWinner->hide();
    enableEverything();
    handle.randomizeHard();
    hideMatches();
    ui->saveScoreButton->setDisabled(true);

}

//Sets up a new gameplay on whatever level has been chosen, resets matches & tries
void GameWindow::on_newGameButton_clicked()
{
    ui->dynamicMatches->setText("0");
    ui->dynamicTries->setText("0");
    ui->dynamicWinner->hide();
    matchesNum = 0;
    tries = 0;
    if(level==1)
         handle.randomizeEasy();
    if(level==2)
    {
        handle.randomizeHard();
        enableHard();
    }
    hideMatches();
    enableEverything();
    ui->saveScoreButton->setDisabled(true);
}

//Sets matches to blank
void GameWindow::hideMatches()
{
    ui->match1->setIcon(QIcon(""));
    ui->match2->setIcon(QIcon(""));
    ui->match3->setIcon(QIcon(""));
    ui->match4->setIcon(QIcon(""));
    ui->match5->setIcon(QIcon(""));
    ui->match6->setIcon(QIcon(""));
    ui->match7->setIcon(QIcon(""));
    ui->match8->setIcon(QIcon(""));
    ui->match9->setIcon(QIcon(""));
    ui->match10->setIcon(QIcon(""));
    ui->match11->setIcon(QIcon(""));
    ui->match12->setIcon(QIcon(""));
}

//Checks which button is pushed in the sequence and acts accordingly
void GameWindow :: checkAbility()
{
    //Sets the second button as the button pushed
    if(disabilityCheck == 1)
    {
        secondaryButton = currentButton;
        secondaryButtonNumber=buttonNumber;
        disabilityCheck++;
        if(primaryButtonNumber == secondaryButtonNumber)
        {
            disabilityCheck--;
            return;
        }
        disableEverything();
        disableHard();
    }

    //Sets first button as button pushed
    if(disabilityCheck == 0)
    {
        primaryButton = currentButton;
        primaryButtonNumber = buttonNumber;
        disabilityCheck++;
    }

    //Compares the buttons, sets them back to original as long as the user doesn't click the same button twice
    if(disabilityCheck == 2)
    {
        primaryButton->setVisible(true);
        secondaryButton->setVisible(true);
        disabilityCheck = 0;
        tries++;
        ui->dynamicTries->setText(QString::number(tries));

        if(handle.textForButton(primaryButtonNumber,level)==handle.textForButton(secondaryButtonNumber, level))
        {
            primaryButton->setDisabled(true);
            secondaryButton->setDisabled(true);

            matchesNum++;
            ui->dynamicMatches->setText(QString::number(matchesNum));
            setMatches();
        }

        QTimer::singleShot(2000,this,SLOT(setPicture()));
        QTimer::singleShot(2000, this,SLOT(connectEverything()));
        if(level==2)
        {
            QTimer::singleShot(2000, this,SLOT(enableHard()));
        }
    }
}

//Sets the match buttons
void GameWindow :: setMatches()
{
    if(matchesNum == 1)
        ui->match1->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    if(matchesNum==2)
        ui->match2->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    if(matchesNum==3)
        ui->match3->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    if(matchesNum==4)
        ui->match4->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    if(matchesNum==5)
        ui->match5->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    if(matchesNum==6)
        ui->match6->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    if(matchesNum==7)
        ui->match7->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    if(matchesNum==8)
    {
        ui->match8->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
        if(level == 1)
        {
            QTimer::singleShot(2000, this,SLOT(youWin()));
            ui->saveScoreButton->setEnabled(true);
        }
    }
    if(matchesNum==9)
    {
         ui->match9->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    }
    if(matchesNum==10)
    {
         ui->match10->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    }
    if(matchesNum==11)
    {
         ui->match11->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    }
    if(matchesNum==12)
    {
         ui->match12->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
            QTimer::singleShot(2000, this,SLOT(youWin()));
            ui->saveScoreButton->setEnabled(true);
    }

}

//Displays the "You win" text
void GameWindow:: youWin()
{
    ui->dynamicWinner->setVisible(true);
}

//FOR ALL BUTTONS CLICKED
/*Sets the button clicked to "Current Button"
Sets the button number to the button clicked 1-24
Sets the icon of the button using the textForButton method using the button number and level
Checks which button (first/second) is being pressed in the checkDisability() function*/

void GameWindow::on_button_1_clicked()
{
    currentButton = ui->button_1;
    buttonNumber = 1;
    ui->button_1->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
    checkAbility();
}

void GameWindow::on_button_2_clicked()
{
    currentButton = ui->button_2;
    buttonNumber = 2;
    ui->button_2->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_3_clicked()
{
    currentButton = ui->button_3;
    buttonNumber = 3;
    ui->button_3->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_4_clicked()
{
    currentButton = ui->button_4;
    buttonNumber = 4;
    ui->button_4->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_5_clicked()
{
    currentButton = ui->button_5;
    buttonNumber = 5;
    ui->button_5->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_6_clicked()
{
    currentButton = ui->button_6;
    buttonNumber = 6;
    ui->button_6->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_7_clicked()
{
    currentButton = ui->button_7;
    buttonNumber = 7;
    ui->button_7->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_8_clicked()
{
    currentButton = ui->button_8;
    buttonNumber = 8;
    ui->button_8->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_9_clicked()
{
    currentButton = ui->button_9;
    buttonNumber = 9;
    ui->button_9->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_10_clicked()
{
    currentButton = ui->button_10;
    buttonNumber = 10;
    ui->button_10->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_11_clicked()
{
    currentButton = ui->button_11;
    buttonNumber = 11;
    ui->button_11->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_12_clicked()
{
    currentButton = ui->button_12;
    buttonNumber = 12;
    ui->button_12->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_13_clicked()
{
    currentButton = ui->button_13;
    buttonNumber = 13;
    ui->button_13->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_14_clicked()
{
    currentButton = ui->button_14;
    buttonNumber = 14;
    ui->button_14->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_15_clicked()
{
    currentButton = ui->button_15;
    buttonNumber = 15;
    ui->button_15->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_button_16_clicked()
{
    currentButton = ui->button_16;
    buttonNumber = 16;
    ui->button_16->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}


void GameWindow::on_hardButton_1_clicked()
{
    currentButton = ui->hardButton_1;
    buttonNumber = 17;
    ui->hardButton_1->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_hardButton_2_clicked()
{
    currentButton = ui->hardButton_2;
    buttonNumber = 18;
    ui->hardButton_2->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_hardButton_3_clicked()
{
    currentButton = ui->hardButton_3;
    buttonNumber = 19;
    ui->hardButton_3->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_hardButton_4_clicked()
{
    currentButton = ui->hardButton_4;
    buttonNumber = 20;
    ui->hardButton_4->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_hardButton_5_clicked()
{
    currentButton = ui->hardButton_5;
    buttonNumber = 21;
    ui->hardButton_5->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_hardButton_6_clicked()
{
    currentButton = ui->hardButton_6;
    buttonNumber = 22;
    ui->hardButton_6->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_hardButton_7_clicked()
{
    currentButton = ui->hardButton_7;
    buttonNumber = 23;
    ui->hardButton_7->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow::on_hardButton_8_clicked()
{
    currentButton = ui->hardButton_8;
    buttonNumber = 24;
    ui->hardButton_8->setIcon(QIcon(handle.textForButton(buttonNumber, level)));
     checkAbility();
}

void GameWindow:: setScores()
{
    for(int i = 0; i <20; i++)
    {
        highScoreInt[i]= 1000;
        highScorer[i]="";
        highScoreLevel[i]=0;
    }

}

void GameWindow::on_saveScoreButton_clicked()
{
    for(int i = 0; i <= 19; i++)
    {
        if(tries < highScoreInt[i])
        {
            highScoreInt[i+1]= highScoreInt[i];
            highScoreInt[i]=tries;

            highScorer[i+1]=highScorer[i];
            highScorer[i] = ui->nameLineEdit->text();

            highScoreLevel[i+1]=highScoreLevel[i];
            highScoreLevel[i]=level;
            break;
        }
    }

    for(int i = 0; i < numberOfScores; i++)
    {
        playerString+= QString::number(i+1)+". ";
        playerString+= highScorer[i]+ " ";
        playerString+= QString::number(highScoreInt[i])+" ";
        playerString+= "LEVEL: "+QString::number(highScoreLevel[i])+"\n";
    }

    ui->highScoreBrowser->setText(playerString);
    playerString ="";
    numberOfScores++;
}


