#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H
#include <cellmanager.h>
#include <QString>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QIcon>
#include <QList>
#include <QColor>



namespace Ui {
class battlefield;
}

class battlefield : public QWidget
{
    Q_OBJECT

public:
    explicit battlefield(QWidget *parent = 0);
    void setTeamNameText(QString one, QString two);
    void setTeamOneURL(QString);
    void setTeamTwoURL(QString);
    void setTeamOneType(bool type);
    void setTeamTwoType(bool type);
    void setBaseValues();
    void initializeEverything();
    QColor lightRed;
    QColor medRed;
    QColor darkRed;
    QColor black;
    QColor grey;
    QColor lightBlue;
    QColor medBlue;
    QColor darkBlue;
    QColor green;
    QColor pinkish;


    cellManager boardManager;



    ~battlefield();

protected slots:


private slots:


    void on_battleTable_cellClicked(int row, int column);



private:
    Ui::battlefield *ui;

    QString teamOneName;
    QString teamTwoName;
    QString oneType;
    QString twoType;
    QString teamOneURL;
    QString teamTwoURL;
    bool isOneHuman;
    bool isTwoHuman;
    int playerOneMoves;
    int playerTwoMoves;

    QTableWidgetItem* firstCellClicked;
    QTableWidgetItem* secondCellClicked;
    bool oneChecked;
    bool twoChecked;





};

#endif // BATTLEFIELD_H
