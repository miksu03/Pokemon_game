#ifndef UDPCLIENT_H
#define UDPCLIENT_H
#include "userpokemon.h"
#include "calculations.h"
#include "attack.h"

#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include <QObject>
#include <QUdpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QQuickItem>
#include <QTimer>
#include <QDebug>
#include <QHostInfo>

class UdpClient: public QObject
{
    Q_OBJECT
    Q_PROPERTY(double remoteProgressBarValue READ remoteProgressBarValue NOTIFY remoteProgressBarValueChanged)
    Q_PROPERTY(double localProgressBarValue READ localProgressBarValue NOTIFY localProgressBarValueChanged)
    Q_PROPERTY(QObject* localPokemon READ localPokemon WRITE setLocalPokemon NOTIFY localPokemonChanged)
    Q_PROPERTY(QObject* remotePokemon READ remotePokemon NOTIFY remotePokemonChanged)
    Q_PROPERTY(bool ready READ ready WRITE setReady NOTIFY readyChanged FINAL)
public:
    UdpClient(QObject *parent = nullptr)
            : QObject(parent)
            , m_localPokemon{nullptr}
            , m_remotePokemon{new UserPokemon()}
    {
        qDebug() << "Instance!";
        // Create a UDP socket
        socket = new QUdpSocket(this);

        // Connect the socket's readyRead signal to the readPendingDatagrams slot
        connect(socket, &QUdpSocket::readyRead, this, &UdpClient::readPendingDatagrams);

        // Set the IP address and port number of the remote host
        ipAddress = QHostAddress::LocalHost;
        port = 1234;
        m_ready = false;
        startTimer(50);
    }
    static QObject* getInstance(QQmlEngine *, QJSEngine *);
    Q_INVOKABLE void setIpAddress(QString ip);
    Q_INVOKABLE QString getIpAdress();
    void sendJsonObject(QJsonObject jsonObject);
    double remoteProgressBarValue() const;
    double localProgressBarValue() const;
    Q_INVOKABLE void lowerProgressBarLocal(double timeInSeconds);
    Q_INVOKABLE void attackAttack(int attackIndex);
    void setLocalProgressBarValue(double value);
signals:
    void localProgressBarValueChanged();
    void remoteProgressBarValueChanged();
    void localPokemonChanged();
    void remotePokemonChanged();
    void readyChanged();
protected:
    void timerEvent(QTimerEvent *event) override;
private slots:
    // Slot called when the UDP socket has pending datagrams to read
    void readPendingDatagrams();
private:
    Attack attackCalc;
    Sentable table;
    UserPokemon* m_localPokemon;
    UserPokemon* m_remotePokemon;
    UserPokemon* localPokemon(){return m_localPokemon;}
    UserPokemon* remotePokemon(){return m_remotePokemon;}
    void setLocalPokemon(QObject* obj);
    void setRemoteProgressBarValue(double value);
    QTimer remoteStamina;
    QTimer localStamina;
    QUdpSocket *socket;
    bool m_ready;
    bool ready(){return m_ready;}
    void setReady(bool readiness){m_ready = readiness;emit readyChanged();}
    static QHostAddress ipAddress;
    quint16 port;
    QMetaObject::Connection localStaminaConnection;
    QMetaObject::Connection remoteStaminaConnection;
    double m_localProgressBarValue = 0;
    double m_remoteProgressBarValue = 0;
    bool m_firstPacketSent = false;
    QQmlApplicationEngine* engine;
    void lowerProgressBarRemote(double timeInSeconds);
    Calculations m_calc;
};

#endif // UDPCLIENT_H
