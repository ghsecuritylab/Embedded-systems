#include "server.h"
#include "QTcpSocket"
#include "mainwindow.h"
#include "QHostAddress"
#include "QVariant"

server::server(QObject *parent) : QObject(parent)
{
    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(serverConnected()));
    m_tcpServer->listen(QHostAddress::Any, 55555);
    qDebug() << "Server gestart";
}

void server::setData(QString input)
{
    QVariant v(input);
    m_data = v.toByteArray();
}

void server::serverConnected()
{
    qDebug() << "connected";
    QTcpSocket *connection = m_tcpServer->nextPendingConnection();
    connect(connection, SIGNAL(disconnected()), connection, SLOT(deleteLater()));
    QHostAddress address = connection->peerAddress();
    Q_IPV6ADDR ip = address.toIPv6Address();

    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);

    connection->write("HTTP/1.1 200 OK\r\n"
     "Cache-Control: no-cache\r\n"
     "Cache-Control: private\r\n"
     "Pragma: no-cache\r\n"
     "Content-type: text/html\r\n\r\n" );


    connection->write("<h1>Hieronder komen alle logs</h1><br><br><hr><br>");
    connection->write(m_data);
    //connection->disconnectFromHost();
}



