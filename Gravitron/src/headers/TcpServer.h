#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

/**
 * Definition of the TcpServer. Holds a QTcpServer and
 * a QTcpSocket of the client. At the moment its just
 * posible to have one client!
 */
class TcpServer: public QObject
{
    Q_OBJECT

    private:
        /** A QTcpServer */
        QTcpServer server;

        /** A QTcpSocket for the client */
        QTcpSocket* client = NULL;

        /** Buffer to merge splitted packages */
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
        void clientConnected();
};

#endif
