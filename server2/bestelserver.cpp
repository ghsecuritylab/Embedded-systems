#include "bestelserver.h"
#include <QTcpSocket>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QList>
#include <QThread>

bestelServer::bestelServer(QObject *parent) : QObject(parent)
{
    m_tcpServer = new QTcpServer;
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(serverConnected()));
    m_tcpServer->listen(QHostAddress::Any, 55555);
    qDebug() << "Server gestart";
}

void bestelServer::serverConnected()
{
    qDebug() << "Connected";
    m_connection = m_tcpServer->nextPendingConnection();
    connect(m_connection, SIGNAL(readyRead()), this, SLOT(dataOntvangen()));
}

void bestelServer::dataOntvangen()
{
    QString buffer = m_connection->readAll();
    QList<QString> inputBuffer;
    int id;

    qDebug() << buffer;

    inputBuffer = buffer.split(", ");

    if(inputBuffer[0]=="hoofdmenu")
    {
        /*
         * Hoofdmenu opsturen.
         * als eerste word de hoeveelheid elementen opgestuurd
         * menuitem => id;naam
         * als laatste stuurt men "END"
         */

        QString buffer;
        QFile file("hoofdMenu.txt");
        QList<QString> hoofdmenuLijst;
        int i;

        //Hoofdmenu file openen
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(0, "Error!", "Kon hoofdmenu file niet openen!");
        }

        QTextStream in(&file);

        //Hoofdmenu inlezen en opsturen naar client
        while(!in.atEnd())
        {
            buffer = in.readLine();
            if(buffer!="")
            {
                hoofdmenuLijst.append(buffer);
            }
        }
        for(i=0;i<hoofdmenuLijst.count();i++)
        {
            m_connection->write(hoofdmenuLijst[i].toUtf8());
            m_connection->write(";");
        }
        qDebug() << "Hoofdmenu verzonden";
    }
    else if (inputBuffer[0] == "PRICE")
    {
        QFile file("onderMenu.txt");
        QList<QString> bufferLijst;

        //Hoofdmenu file openen
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(0, "Error!", "Kon hoofdmenu file niet openen!");
        }

        QTextStream in(&file);

        //Hoofdmenu inlezen en opsturen naar client
        while(!in.atEnd())
        {
            buffer = in.readLine();
            if(buffer!="")
            {
                bufferLijst = buffer.split(", ");
                if(bufferLijst[0] == inputBuffer[1])
                {
                    if(bufferLijst[1] == inputBuffer[2])
                    {
                        m_connection->write(bufferLijst[3].toUtf8());
                    }
                }
            }
        }
    }
    else if (inputBuffer[0] == "IMG")
    {
        QFile file("afbeeldingen/0_0.txt");

        m_connection->write(("Afbeelding"));
        qDebug() << "Afbeelding verzonden";
    }
    else
    {
        id = buffer.toInt();

        QFile file("onderMenu.txt");
        QList<QString> bufferLijst;
        QList<QString> ondermenuLijst;
        int i;

        //Hoofdmenu file openen
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(0, "Error!", "Kon hoofdmenu file niet openen!");
        }

        QTextStream in(&file);

        //Hoofdmenu inlezen en opsturen naar client
        while(!in.atEnd())
        {
            buffer = in.readLine();
            if(buffer!="")
            {
                bufferLijst = buffer.split(", ");
                if(bufferLijst[1].toInt() == id)
                {
                    ondermenuLijst.append(buffer);
                    qDebug() << buffer;
                }
            }
        }
        if(ondermenuLijst.count() > 0)
        {
            for(i=0;i<ondermenuLijst.count();i++)
            {
                m_connection->write(ondermenuLijst[i].toUtf8());
                m_connection->write(";");
            }
            qDebug() << "Ondermenu verzonden";
        }
        else
        {
            m_connection->write("NULL");
            qDebug() << "Leeg ondermenu verzonden";
        }
    }
}

