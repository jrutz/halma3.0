#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QString>
#include <QWidget>



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

    ~battlefield();

protected slots:


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





};

#endif // BATTLEFIELD_H
