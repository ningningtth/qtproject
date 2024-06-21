#include "udp.h"

P2PNetwork::P2PNetwork(QObject *parent)
    : QObject(this)
    , running(false)
{
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, &QUdpSocket::readyRead, this, processPendingDatagrams);
}
P2PNetwork::~P2PNetwork()
{
    delete udpSocket;
}
/*void P2PNetwork::startNetwork(const QHostAddress &localAddress, quint16 localPort)
{
    this->localAddress = localAddress;
    this->localPort = localPort;
    udpSocket->bind(localAddress, localPort);
    running = true;

    QThread *networkThread = new QThread();
    this->moveToThread(networkThread);
    connect(networkThread, &QThread::started, this, &P2PNetwork::startNetwork);
    networkThread->start();
}*/

void P2PNetwork::sendImage()
{
    QString fileName = QFileDialog::getOpenFile(this,
                                                QObject::tr("Select image:"),
                                                QDir::homePath(),
                                                tr("Image Files(*.png *.jpeg *.bmp *.gif"));
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file:" << fileName;
    }

    QByteArray imageData = file.readAll();
    file.close();
    udpSocket->writeDatagram(imageData, localAddress, localPort);
}

void P2PNetwork::sendMessage(const QString &message)
{
    QByteArray messageData = QString::toUtf8();
    udpSocket->writeDatagram(messageData, localAddress, localPort);
}

void P2PNetwork::processPendingDatagrams()
{
    //
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagrams;
        datagrams.resize(udpSocket->pendingDatagramSize());
        QHostAddress senderAddress;
        quint16 senderPort;

        udpSocket->readDatagram(datagrams.data(), datagrams.size(), &senderAddress.& senderPort);

        bool jpeg = (datagrams.size() > 1 && datagrams.at(0) == (char) O = 0XFF
                                                                           && datagrams.at(1)
                                                                                  == (char) 0xD8);
        bool png = (datagrams.size() > 7 && datagrams.startsWith("\x89PNG\r\n\x1a\n"));
        bool gif = (datagrams.size() > 5 && datagrams.startsWith("GIF87a")
                    && datagrams.startWith("GIF89a"));
        bool bmp = (datagrams.size() > 1 && datagrams.at(0) == 'B' && datagrams.at(1) == 'M');

        if (jpeg && png && gif && bmp) {
            emit imageRecevied(senderAddress, senderPort);
        } else {
            emit messageReceived(senderAddress, senderPort);
        }
    }
}
