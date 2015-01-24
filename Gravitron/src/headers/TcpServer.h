#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <vector>
#include "GameActorView.h"

class TcpServer: public QObject
{
    Q_OBJECT

    private:
        QTcpServer server;
        QTcpSocket* client = NULL;
        QString buffer;

    public:
        TcpServer(QObject * parent = 0);
        ~TcpServer();

    public slots:
        void acceptConnection();
        void startRead();
        void startListen(int port);

        Q_INVOKABLE void transfer(QString message);

    signals:
        void received(QString message);

};

#endif
