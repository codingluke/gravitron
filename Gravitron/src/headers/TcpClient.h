#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>

class TcpClient: public QObject
{
    Q_OBJECT

    private:
        QTcpSocket client;

    public:
        TcpClient(QObject* parent = 0);
        ~TcpClient();

        Q_INVOKABLE void start(QString address, quint16 port);
        Q_INVOKABLE void transfer(QString message);

    public slots:
        void startTransfer();
        void startRead();

    signals:
        void received(QString message);
};

#endif
