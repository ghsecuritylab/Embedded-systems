#ifndef BESTELSERVER_H
#define BESTELSERVER_H

#include <QObject>
#include <QTcpServer>

class bestelServer : public QObject
{
    Q_OBJECT
public:
    explicit bestelServer(QObject *parent = 0);

private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_connection;

signals:

public slots:

private slots:
    void serverConnected(void);
    void dataOntvangen(void);
};

#endif // BESTELSERVER_H
