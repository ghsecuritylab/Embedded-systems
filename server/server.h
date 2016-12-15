#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "QTcpServer"
#include "QtWidgets"

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    void setData(QString);

private:
    QTcpServer *m_tcpServer;
    QByteArray m_data;

private slots:
    void serverConnected(void);
};

#endif // SERVER_H
