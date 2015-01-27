#include "headers/TcpClient.h"
#include <iostream>
#include <QHostAddress>
#include <QDebug>
#include <sstream>

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
        client.flush();
    } else {
        qDebug() << "Client not connected to a host";
    }
}

void TcpClient::transfer(set<int> inputs)
{
    ostringstream x;
    x << "i";
    for(set<int>::iterator it = inputs.begin(); it != inputs.end(); it++) {
        x << *it;
        if (it != (--inputs.end())) {
            x << ",";
        }
    }
    x << "\n";
    transfer(QString::fromStdString(x.str()));
}

void TcpClient::startTransfer()
{
    emit connected();
}

void TcpClient::startRead()
{
    buffer += client.readAll();
    if (buffer.endsWith("\n")) {
        emit received(buffer);
        buffer = "";
    }
}

