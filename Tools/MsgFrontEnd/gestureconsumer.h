#ifndef GESTURECONSUMER_H
#define GESTURECONSUMER_H

#include <QtWidgets>
#include <QtNetwork>
#include <stdlib.h>
#include <QObject>
#include <iostream>

class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;
class GestureConsumer : public QDialog
{
    Q_OBJECT
public:
    explicit GestureConsumer(QWidget *parent = 0);

signals:

public slots:
    void sessionOpened();
    void gc_recv();

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    QTcpServer *tcpServer;
    QStringList fortunes;
    QNetworkSession *networkSession;

};

#endif // GESTURECONSUMER_H
