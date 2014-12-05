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
    RemoteAI(QString url);
    void SetConnectionURL(QString url);
    bool testConnectionURL(QString url);
    QByteArray PostJsonData(QByteArray data);


private:
    QString connectionUrl;
    QNetworkAccessManager *networkManager;
    char* sampleAI;
    char* sampleAI_2;

    QString sampleJsonString;
};

#endif // REMOTEAI_H
