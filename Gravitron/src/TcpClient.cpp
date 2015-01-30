#include "headers/TcpClient.h"
#include <QHostAddress>
#include <QDebug>
#include <sstream>

using namespace std;

/**
 * Default constructor. Connects the socket signals for
 * connection status and read status.
 *
 * @param parent  The Parent QObject.
 */
TcpClient::TcpClient(QObject* parent): QObject(parent)
{
    connect(&client, SIGNAL(connected()),
            this, SIGNAL(connected()));
    connect(&client, SIGNAL(readyRead()),
            this, SLOT(startRead()));
}

/**
 * Deconstructor, coses the TcpSocket.
 */
TcpClient::~TcpClient()
{
    client.close();
}

/**
 * Starts a connection to a host.
 *
 * @param address   Host ip adress
 * @param port      Host port
 */
void TcpClient::start(QString address, quint16 port)
{
    QHostAddress addr(address);
    client.connectToHost(addr, port);
}

/**
 * Transfers a string message over the network.
 *
 * @param message   String message to transfer.
 */
void TcpClient::transfer(QString message)
{
    if (client.state() == QAbstractSocket::ConnectedState) {
        client.write(message.toStdString().c_str(), message.length());
        client.flush();
    } else {
        qDebug() << "Client not connected to a host";
    }
}

/**
 * Transfers a set of input codes to the server.
 * This could be done somewhere else, cause of convenience its in this class.
 *
 * @param message   Set of input codes to deliver.
 */
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

/**
 * Entrypoint of Network inputs. Reads the received message.
 * When it ends with a newline \n it emitts the signal received.
 * When it ends not with a newline it just writes the message into to buffer.
 * the buffer gets concatinated with the new received input unitl a newline is here.
 */
void TcpClient::startRead()
{
    buffer += client.readAll();
    if (buffer.endsWith("\n")) {
        emit received(buffer);
        buffer = "";
    }
}

