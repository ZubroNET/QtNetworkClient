#include "client.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QDataStream>

client::client() :  QObject::QObject()
{
    conn = new QTcpSocket();
    connect(conn, &QTcpSocket::connected, this, &client::connectionCreated);
    conn->connectToHost(QHostAddress(serverAddress), serverPort);
    connect(conn, &QTcpSocket::readyRead, this, &client::gotData);
}

void client::connectionCreated()
{
    qDebug() << "Connection created";
}

void client::gotData()
{
    qDebug() << "Data from server: " << conn->readAll();
}

void client::sendData(QByteArray data)
{
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
    output << data;
    conn->write(block);
}
