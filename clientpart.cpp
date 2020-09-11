#include "clientpart.h"
#include "ui_clientpart.h"
#include<QHostAddress>
ClientPart::ClientPart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientPart)
{
    ui->setupUi(this);

    tcpsocket=NULL;
    tcpsocket=new QTcpSocket(this);
    setWindowTitle("客户端");
    connect(tcpsocket,&QTcpSocket::connected,
            [=]()
            {
                ui->textEditrear->setText("成功和服务器建立连接！");
            }
            );
    connect(tcpsocket,&QTcpSocket::readyRead,
            [=]()
            {
                QByteArray array = tcpsocket->readAll();
                ui->textEditrear->append(array);

            }
            );
}

ClientPart::~ClientPart()
{
    delete ui;
}

void ClientPart::on_connectbutton_clicked()
{
    QString ip=ui->lineEditIP->text();
    qint16 port=ui->lineEditPort->text().toInt();
    tcpsocket->connectToHost(QHostAddress(ip),port);

}

void ClientPart::on_sendbutton_clicked()
{
    QString str=ui->textwrite->toPlainText();
    tcpsocket->write(str.toUtf8().data());
}

void ClientPart::on_disconnectbutton_clicked()
{
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
}
