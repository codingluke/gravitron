#include "headers/TcpServer.h"

/**
 * Default constructor.
 *
 * @param parent    The parent QObject
 */
TcpServer::TcpServer(QObject* parent): QObject(parent)
{
}

/**
 * Destructor. Closes the server and the client if existent.
 */
TcpServer::~TcpServer()
{
    server.close();
    if (client != NULL) {
        client->close();
    }
}

/**
 * Lets the server listen to a port and connects the signal for
 * new connections to acceptConnections.
 *
 * @param port  the port to listen to.
 */
void TcpServer::startListen(int port)
{
    connect(&server, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));
    server.listen(QHostAddress::Any, port);
}

/**
 * Accepts a connections, gets the connected client and connects the clients
 * signal readyRead to the own startRead slot. Emits the signal clientConnected.
 */
void TcpServer::acceptConnection()
{
    client = server.nextPendingConnection();
    connect(client, SIGNAL(readyRead()),
            this, SLOT(startRead()));
    emit clientConnected();
}

/**
 * Starts to transfer a string message to the client.
 *
 * @param message to transfer.
 */
void TcpServer::transfer(QString message)
{
    if (client && client->state() == QAbstractSocket::ConnectedState) {
        client->write(message.toStdString().c_str(), message.length());
        client->flush();
    } else {
        qDebug() << "No connected client";
    }
}

/**
 * Entrypoint of Network inputs. Reads the received message.
 * When it ends with a newline \n it emitts the signal received.
 * When it ends not with a newline it just writes the message into to buffer.
 * the buffer gets concatinated with the new received input unitl a newline is here.
 */
void TcpServer::startRead()
{
    buffer += client->readAll();
    if (buffer.endsWith("\n")) {
        emit received(buffer);
        buffer = "";
    }
}
