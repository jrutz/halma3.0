#ifndef REMOTEAI_H
#define REMOTEAI_H

#include <QString>

class RemoteAI
{
public:
    RemoteAI(QString url);
    void SetConnectionURL(QString url);
    QString PostJsonData(QString data);

private:
    QString connectionUrl;
};

#endif // REMOTEAI_H
