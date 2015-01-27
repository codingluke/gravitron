#include "headers/TcpServer.h"
#include <iostream>
#include <QDebug>

using namespace std;

TcpServer::TcpServer(QObject* parent): QObject(parent)
{
}

TcpServer::~TcpServer()
{
    server.close();
    if (client != NULL) {
        client->close();
    }
}

void TcpServer::startListen(int port)
{
    qDebug() << "TcpServer: startListen";
    connect(&server, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));
    server.listen(QHostAddress::Any, port);
}

void TcpServer::acceptConnection()
{
    client = server.nextPendingConnection();
    connect(client, SIGNAL(readyRead()),
            this, SLOT(startRead()));
    emit clientConnected();
    transfer("helloclient\n");
}

void TcpServer::transfer(QString message)
{
    if (client && client->state() == QAbstractSocket::ConnectedState) {
        client->write(message.toStdString().c_str(), message.length());
        client->flush();
    }
}

void TcpServer::startRead()
{
    buffer += client->readAll();
    if (buffer.endsWith("\n")) {
        emit received(buffer);
        buffer = "";
    }
}
