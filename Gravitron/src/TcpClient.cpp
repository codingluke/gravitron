#include "headers/TcpClient.h"
#include <QHostAddress>
#include <QDebug>

TcpClient::TcpClient(QObject* parent): QObject(parent)
{
    connect(&client, SIGNAL(connected()),
            this, SLOT(startTransfer()));
}

TcpClient::~TcpClient()
{
    client.close();
}

void TcpClient::start(QString address, quint16 port)
{
    QHostAddress addr(address);
    client.connectToHost(addr, port);
}

void TcpClient::startTransfer()
{
    qDebug() << "kukuk";
    client.write("Hello, world", 13);
}
