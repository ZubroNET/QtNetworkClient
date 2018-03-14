#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QDataStream>
#include <QInputDialog>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void connectToServer();
    void sendData(QString data);

private slots:
    void connectionCreated();

private:
    Ui::MainWindow *ui;
    QDataStream stream;
    QTcpSocket *conn;
    QString address = "213.168.188.214";
    quint16 port = 19060;
};

#endif // MAINWINDOW_H
