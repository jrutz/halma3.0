#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include "memoryhandler.h"

#include <QMainWindow>
#include <QPushButton>
#

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    
private slots:

    void setPicture();

    void on_button_1_clicked();

    void on_button_2_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_button_7_clicked();

    void on_button_8_clicked();

    void on_button_9_clicked();

    void on_button_10_clicked();

    void on_button_11_clicked();

    void on_button_12_clicked();

    void on_button_13_clicked();

    void on_button_14_clicked();

    void on_button_15_clicked();

    void on_button_16_clicked();

    void checkAbility();

    void disableEverything();

    void connectEverything();

    void youWin();

    void disableHard();

    void on_easyButton_clicked();

    void on_hardButton_clicked();

    void enableHard();

    void enableEverything();

    void on_hardButton_1_clicked();

    void on_hardButton_2_clicked();

    void on_hardButton_3_clicked();

    void on_hardButton_4_clicked();

    void on_hardButton_5_clicked();

    void on_hardButton_6_clicked();

    void on_hardButton_7_clicked();

    void on_hardButton_8_clicked();

    void hideMatches();

    void on_newGameButton_clicked();

    void on_saveScoreButton_clicked();

    void setScores();


private:
    Ui::GameWindow *ui;
    QPushButton* primaryButton;
    QPushButton* secondaryButton;
    QPushButton* currentButton;

    QString buttonImage;
    //QString secondaryButtonImage;

    int disabilityCheck = 0;
    int buttonNumber;
    int primaryButtonNumber;
    int secondaryButtonNumber;
    int numberOfScores;
    int matchesNum=0;
    int tries = 0;
    int level;
    QString playerString="";
    QString highScorer[20];
    int highScoreInt[20];
    int highScoreLevel[20];

    void setMatches();

    memoryHandler handle;
};

#endif // GAMEWINDOW_H
