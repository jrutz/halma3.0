#ifndef REMOTEAI_H
#define REMOTEAI_H

#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <cstring>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class RemoteAI
{
public:
    RemoteAI();
    RemoteAI(QString url);
    void SetConnectionURL(QString url);
    bool TestConnectionURL(QString url);
    int* PostJsonData(int numPieces, int destSize, int piecesX[], int piecesY[], int destX[],
                            int destY[], int enemyX[], int enemyY[],
                            int enemyDestX[], int enemyDestY[]);
    QJsonObject MakeJsonObject(int numPieces, int destSize, int piecesX[], int piecesY[], int destX[],
                               int destY[], int enemyX[], int enemyY[],
                               int enemyDestX[], int enemyDestY[]);


private:
    QString connectionUrl;
    QNetworkAccessManager *networkManager;
    QString sampleAI;
    QString sampleAI_2;
    QString derekAI;

    QString sampleJsonString;
};

#endif // REMOTEAI_H
