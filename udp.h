#pragma once
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
//#include <QMutex>
#include <QObject>
#include <QThread>
#include <QtNetwork/QUdpSocket>

/*class ImageSenderThread : public QThread
{
    Q_OBJECT
public:
    ImageSenderThread(QObject *parent = nuuptr);

public slots:
    void sendImage(const QString &fileName, const QHostAddress &address.quint16 port);

protected:
    void run() override;

private:
    QString fileName;
    QHostAddress address;
    quint16 prot;
};
*/
class P2PNetwork : public QObject
{
    Q_OBJECT
public:
    explicit P2PNetwork(QObject *parent = nullptr);
    ~P2PNetwork();

    void startNetwork(const QHostAddress &localAddress, quint localPort);

signals:
    void messageReceived(const QString &sender, const QString &message);
    void imageRecevied(const QString &sender, const QByteArray &imageData);

public slots:
    void sendMessage(const QString &message);
    void sendImage();
    //void start(const QHostAddress &localAddress, quint localPort);

private slots:
    void processPendingDatagrams(); //handle data received

private:
    QUdpSocket *udpSocket;
    QHostAddress localAddress;
    quint16 localPort;
    bool running;
    //  ImageSenderThread *imageSenderThread;

    //void setupConnections();
};
