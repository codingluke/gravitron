#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer: public QObject
{
    Q_OBJECT

    public:
        TcpServer(QObject * parent = 0);
        ~TcpServer();

    public slots:
        void acceptConnection();
        void startRead();
        void startListen(int port);

    private:
        QTcpServer server;
        QTcpSocket* client;
};

#endif
