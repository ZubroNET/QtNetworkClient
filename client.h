#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>

class client : public QObject
{
    Q_OBJECT
public:

    client();
    void sendData(QByteArray data);

private slots:
    void connectionCreated();
    void gotData();

private:
    QTcpSocket *conn;
    QString serverAddress = "213.168.188.214";
    int serverPort = 19060;
};

#endif // CLIENT_H
