#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToServer()
{
    QTextStream(stdout) << "Connecting to server... ";
    conn = new QTcpSocket();
    conn->connectToHost(QHostAddress(address), port);
    connect(conn, &QTcpSocket::connected, this, &MainWindow::connectionCreated);
}

void MainWindow::sendData(QString data)
{
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_9);
    output << data;
    conn->write(block);
}

void MainWindow::connectionCreated()
{
    QTextStream(stdout) << " Connected" << endl;
    stream.setDevice(conn);
    stream.setVersion(QDataStream::Qt_5_9);
    stream.startTransaction();
    sendData(QString("HELO").toLatin1());
}
