#include "headers/TcpClient.h"
#include <iostream>
#include <QHostAddress>
#include <QDebug>

using namespace std;

TcpClient::TcpClient(QObject* parent): QObject(parent)
{
    connect(&client, SIGNAL(connected()),
            this, SLOT(startTransfer()));
    connect(&client, SIGNAL(readyRead()),
            this, SLOT(startRead()));
}

TcpClient::~TcpClient()
{
    client.close();
}

void TcpClient::start(QString address, quint16 port)
{
    qDebug() << "TcpClient: start";
    QHostAddress addr(address);
    client.connectToHost(addr, port);
}

void TcpClient::transfer(QString message)
{
    if (client.state() == QAbstractSocket::ConnectedState) {
        client.write(message.toStdString().c_str(), message.length());
    } else {
        qDebug() << "Client not connected to a host";
    }
}

void TcpClient::startTransfer()
{
    qDebug() << "TcpClient: startTransfer";
    transfer("hello");
}

void TcpClient::startRead()
{
    char buffer[1024] = {0};
    client.read(buffer, client.bytesAvailable());
    cout << "client: " << buffer << endl;
    emit received(QString(buffer));
}

