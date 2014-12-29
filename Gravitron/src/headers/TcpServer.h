#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>

class TcpServer: public QObject
{
    Q_OBJECT

    public:
        TcpServer(QObject * parent = 0);
        ~TcpServer();

        Q_INVOKABLE void transfer(QString message);

    public slots:
        void acceptConnection();
        void startRead();
        void startListen(int port);

    signals:
        void received(QString message);

    private:
        QTcpServer server;
        QTcpSocket* client = NULL;
};

#endif
