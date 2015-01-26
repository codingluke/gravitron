#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <set>

using namespace std;

class TcpClient: public QObject
{
    Q_OBJECT

    private:
        QTcpSocket client;
        QString buffer;

    public:
        TcpClient(QObject* parent = 0);
        ~TcpClient();

        Q_INVOKABLE void start(QString address, quint16 port);

    public slots:
        void startTransfer();
        void startRead();
        Q_INVOKABLE void transfer(QString message);
        Q_INVOKABLE void transfer(set<int> inputs);

    signals:
        void received(QString message);
        void connected();
};

#endif
