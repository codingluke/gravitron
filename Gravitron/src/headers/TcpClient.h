#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>

class TcpClient: public QObject
{
  Q_OBJECT

  public:
    TcpClient(QObject* parent = 0);
    ~TcpClient();

    void start(QString address, quint16 port);

  public slots:
    void startTransfer();

  private:
    QTcpSocket client;
};

#endif
