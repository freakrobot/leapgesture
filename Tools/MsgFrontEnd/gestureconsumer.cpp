#include "gestureconsumer.h"

GestureConsumer::GestureConsumer(QWidget *parent) :
    QDialog(parent), tcpServer(0), networkSession(0)
{
    statusLabel = new QLabel;
        quitButton = new QPushButton(tr("Quit"));
        quitButton->setAutoDefault(false);

        QNetworkConfigurationManager manager;
        if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
            // Get saved network configuration
            QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
            settings.beginGroup(QLatin1String("QtNetwork"));
            const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
            settings.endGroup();

            // If the saved network configuration is not currently discovered use the system default
            QNetworkConfiguration config = manager.configurationFromIdentifier(id);
            if ((config.state() & QNetworkConfiguration::Discovered) !=
                QNetworkConfiguration::Discovered) {
                config = manager.defaultConfiguration();
            }

            networkSession = new QNetworkSession(config, this);
            connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

            statusLabel->setText(tr("Opening network session."));
            networkSession->open();
        } else {
            sessionOpened();
        }

            fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
                     << tr("You've got to think about tomorrow.")
                     << tr("You will be surprised by a loud noise.")
                     << tr("You will feel hungry again in another hour.")
                     << tr("You might have mail.")
                     << tr("You cannot kill time without injuring eternity.")
                     << tr("Computers are not intelligent. They only think they are.");

            connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
            connect(tcpServer, SIGNAL(newConnection()), this, SLOT(gc_recv()));
            //connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(gc_recv()));
                //connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(displayError(QAbstractSocket::SocketError)));

            QHBoxLayout *buttonLayout = new QHBoxLayout;
            buttonLayout->addStretch(1);
            buttonLayout->addWidget(quitButton);
            buttonLayout->addStretch(1);

            QVBoxLayout *mainLayout = new QVBoxLayout;
            mainLayout->addWidget(statusLabel);
            mainLayout->addLayout(buttonLayout);
            setLayout(mainLayout);

            setWindowTitle(tr("Fortune Server"));
}

void GestureConsumer::sessionOpened()
{
    // Save the used configuration
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::LocalHost,15501)) {
        QMessageBox::critical(this, tr("Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }
//    QString ipAddress;
//    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
//    // use the first non-localhost IPv4 address
//    for (int i = 0; i < ipAddressesList.size(); ++i) {
//        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
//            ipAddressesList.at(i).toIPv4Address()) {
//            ipAddress = ipAddressesList.at(i).toString();
//            break;
//        }
//    }
//    // if we did not find one, use IPv4 localhost
//    if (ipAddress.isEmpty())
//        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
//    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
//                            "Run the Fortune Client example now.")
//                         .arg(ipAddress).arg(tcpServer->serverPort()));
}

void GestureConsumer::gc_recv()
{
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));
    QDataStream in(clientConnection);
    QString buf;
    in>>buf;
    std::cout<<buf.toStdString()<<std::endl;
}
