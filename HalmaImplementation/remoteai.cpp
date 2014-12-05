#include "remoteai.h"

RemoteAI::RemoteAI(QString url = "") {
    connectionUrl = url;
    networkManager = new QNetworkAccessManager();

    sampleAI_2 = "http://lyle.smu.edu/~coyle/halmagame/code/makeOneMove.php";
    sampleAI = "http://lyle.smu.edu/~tbgeorge/cse4345/a1/getMove.php";
    derekAI = "http://lyle.smu.edu/~dphanekham/4345/HW11.php";

    sampleJsonString =  QString::fromStdString("{\"pieces\":[{\"y\":14,\"x\":0,\"team\":0},{\"y\":15,\"x\":0,\"team\":0},")
    + QString::fromStdString( "{\"y\":16,\"x\":0,\"team\":0},{\"y\":17,\"x\":0,\"team\":0},{\"y\":14,\"x\":1,\"team\":0},")
    + QString::fromStdString( "{\"y\":15,\"x\":1,\"team\":0},{\"y\":16,\"x\":1,\"team\":0},{\"y\":17,\"x\":1,\"team\":0},")
    + QString::fromStdString("{\"y\":14,\"x\":2,\"team\":0},{\"y\":15,\"x\":2,\"team\":0},{\"y\":16,\"x\":2,\"team\":0},")
    + QString::fromStdString("{\"y\":17,\"x\":2,\"team\":0}],\"destinations\":[{\"y\":0,\"x\":17,\"team\":-1},")
    + QString::fromStdString("{\"y\":1,\"x\":17,\"team\":-1},{\"y\":2,\"x\":17,\"team\":-1},{\"y\":0,\"x\":16,\"team\":-1},")
    + QString::fromStdString("{\"y\":1,\"x\":16,\"team\":-1},{\"y\":2,\"x\":16,\"team\":-1},{\"y\":0,\"x\":15,\"team\":-1},")
    + QString::fromStdString("{\"y\":1,\"x\":15,\"team\":-1},{\"y\":2,\"x\":15,\"team\":-1}],\"boardSize\":18,\"enemy\":")
    + QString::fromStdString("[{\"y\":14,\"x\":15,\"team\":1},{\"y\":15,\"x\":15,\"team\":1},{\"y\":16,\"x\":15,\"team\":1},")
    + QString::fromStdString("{\"y\":17,\"x\":15,\"team\":1},{\"y\":14,\"x\":16,\"team\":1},{\"y\":13,\"x\":14,\"team\":1},")
    + QString::fromStdString("{\"y\":16,\"x\":16,\"team\":1},{\"y\":17,\"x\":16,\"team\":1},{\"y\":13,\"x\":16,\"team\":1},")
    + QString::fromStdString("{\"y\":15,\"x\":17,\"team\":1},{\"y\":16,\"x\":17,\"team\":1},{\"y\":17,\"x\":17,\"team\":1}]")
    + QString::fromStdString(",\"enemydestinations\":[{\"y\":0,\"x\":0,\"team\":-1},{\"y\":1,\"x\":0,\"team\":-1},{\"y\":")
    + QString::fromStdString("2,\"x\":0,\"team\":-1},{\"y\":0,\"x\":1,\"team\":-1},{\"y\":1,\"x\":1,\"team\":-1},")
    + QString::fromStdString("{\"y\":2,\"x\":1,\"team\":-1},{\"y\":0,\"x\":2,\"team\":-1},{\"y\":1,\"x\":2,\"team\":-1},")
    + QString::fromStdString("{\"y\":2,\"x\":2,\"team\":-1}]}");


}

void RemoteAI::SetConnectionURL(QString url) {
    connectionUrl = url;
}

bool RemoteAI::TestConnectionURL(QString url) {
    return false;
}

/*

*/
QJsonObject RemoteAI::MakeJsonObject(int numPieces,int destSize, int piecesX[], int piecesY[], int destX[],
                                     int destY[], int enemyX[], int enemyY[],
                                     int enemyDestX[], int enemyDestY[]) {
    QJsonObject JsonObject;
    QJsonArray piecesJsonArray;
    QJsonArray enemyJsonArray;
    QJsonArray destJsonArray;
    QJsonArray enemyDestJsonArray;

    for(int i=0; i< numPieces; i++) {
        QJsonObject temp;
        QJsonObject temp2;
        temp.insert("x", piecesX[i]);
        temp.insert("y", piecesY[i]);
        temp2.insert("x", enemyX[i]);
        temp2.insert("y", enemyY[i]);

        piecesJsonArray.append(temp);
        enemyJsonArray.append(temp2);
    }

    for(int i=0; i< destSize; i++) {
        QJsonObject temp;
        QJsonObject temp2;
        temp.insert("x", destX[i]);
        temp.insert("y", destY[i]);
        temp2.insert("x", enemyDestX[i]);
        temp2.insert("y", enemyDestY[i]);

        destJsonArray.append(temp);
        enemyDestJsonArray.append(temp2);
    }

    JsonObject.insert("boardSize", 18);
    JsonObject.insert("pieces", piecesJsonArray);
    JsonObject.insert("destinations", destJsonArray);
    JsonObject.insert("enemy", enemyJsonArray);
    JsonObject.insert("enemydestinations", enemyDestJsonArray);
    return JsonObject;
}

QByteArray RemoteAI::PostJsonData(QByteArray data) {

    int px [3] = { 1, 1, 1};
    int py [3] = { 1, 1, 1};
    QJsonObject JsonObject = MakeJsonObject(3,3,px,py,px,py,px,py,px,py);
    qDebug() << "JsonObject" << JsonObject["pieces"].toArray().at(0).toObject()["x"].toInt();
    QJsonDocument doc;
    doc.setObject(JsonObject);
    QByteArray j = doc.toJson();
    //qDebug() << j;
    // create custom temporary event loop on stack
        QEventLoop eventLoop;

        // "quit()" the event-loop, when the network request "finished()"
        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        // the HTTP request
        //url needs to be cstring
        QNetworkRequest req( QUrl( QString::fromStdString(derekAI)) );
        req.setRawHeader("Content-Type", "application/json");
        //QNetworkReply *reply = mgr.get(req);
        QNetworkReply *reply = mgr.post(req, j);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        if (reply->error() == QNetworkReply::NoError) {
            //success
            QString strReply = (QString)reply->readAll();

            //parse json
            qDebug() << "Success" << strReply;
            delete reply;
            QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

            QJsonObject jsonObj = jsonResponse.object();

            int from_x = jsonObj["from"].toObject()["x"].toInt();
            int from_y = jsonObj["from"].toObject()["y"].toInt();


            int to_x = from_x;
            int to_y = from_y;
            if (jsonObj["to"].isArray()) {
                QJsonArray a = jsonObj["to"].toArray();
                to_x = a.at(a.size()-1).toObject()["x"].toInt();
                to_y = a.at(a.size()-1).toObject()["y"].toInt();
            }

            qDebug() << "from x:" << from_x;
            qDebug() << "from y:" << from_y;
            qDebug() << "to x:" << to_x;
            qDebug() << "to y:" << to_y;


        }
        else {
            //failure
            qDebug() << "Failure" <<reply->errorString();
            delete reply;
        }

}
