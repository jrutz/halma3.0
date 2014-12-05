#include "remoteai.h"
#include <QNetworkAccessManager>

RemoteAI::RemoteAI(QString url = "")
{
    connectionUrl = url;
}

void RemoteAI::SetConnectionURL(QString url)
{
    connectionUrl = url;
}

QString RemoteAI::PostJsonData(QString data)
{
    return "lol";
}
