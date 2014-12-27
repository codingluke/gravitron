#include "headers/TcpServer.h"
#include <iostream>
#include <QDebug>

using namespace std;

TcpServer::TcpServer(QObject* parent): QObject(parent)
{
    //connect(&server, SIGNAL(newConnection()),
            //this, SLOT(acceptConnection()));
    //server.listen(QHostAddress::Any, 8888);
}

TcpServer::~TcpServer()
{
    server.close();
}

void TcpServer::startListen(int port)
{
    connect(&server, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));
    server.listen(QHostAddress::Any, port);
}

void TcpServer::acceptConnection()
{
    qDebug() << "AcceptConnection";
    client = server.nextPendingConnection();
    connect(client, SIGNAL(readyRead()),
            this, SLOT(startRead()));
}

void TcpServer::startRead()
{
    char buffer[1024] = {0};
    client->read(buffer, client->bytesAvailable());
    cout << buffer << endl;
    client->close();
}
