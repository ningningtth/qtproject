/*#include <udpclient.h>

Client::Client(QObject *parent)
    : QObject(parent)
{
    cudpSocket = new QUdpSocket(this);
    
    cudpSocket.bind(QHostAddress::Any, 12345);
        connect(cudpSocket, &QUdpSocket::readyread, this, &Client::processPendingDatagrams());
}

Client::~Client()
{
    cudpSocket->close();
}
//send massage
void Client::sendMessge(const QString &message)
{
    QByteArray datagrams = message.toUtf8();
    cudpSocket->writeDatagram(datagrams, QHostAddress::LocalHost, 12345); //send message to server
}
//send image
void Client::sendImage(const QString &filePath)
{
    
    QFile file(&filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file" << file.errorString();
        return;
    }
    QByteArray imageData = file.readAll();
    cudpSocket->writeDatagram(imageData, QHostAddress::Any, 12346);
}

void Client::connectToClient(const QString &clientAddress)
{
    sendMessage("/connect" + clientAddress + "hello!");
}*/
/*
void Client::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagrams;
        datagrams.resize(cudpSocket->pendingDatagramSize()); //set datagrame's length
        //sender
        QHostAddress senderAddress; //ip of sender
        quint16 senderPort;         //sender of port

        //read datagrame,receive message from server
        cudpSocket->readDatagram(datagrams.data(), datagrams.size(), &senderAddress, &senderPort);

        /*QString message = QString::fromUtf8(datagrams);
        //qDebug() << message;
        emit messageReceived(senderAddress.toString(), message);
    }
    }*/
