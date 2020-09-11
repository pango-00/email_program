#include "serverpart.h"
#include "ui_serverpart.h"

Serverpart::Serverpart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Serverpart)
{
    ui->setupUi(this);
    TcpServer=NULL;
    TcpSocket=NULL;
    TcpServer =new QTcpServer(this);
    TcpServer->listen(QHostAddress::Any,8173);

    setWindowTitle("服务器：8173");

    connect(TcpServer,&QTcpServer::newConnection,
            [=]()
            {
                TcpSocket=TcpServer->nextPendingConnection();
                QString ip=TcpSocket->peerAddress().toString();
                qint16 port=TcpSocket->peerPort();
                QString temp=QString("[%1:%2]:成功连接").arg(ip).arg(port);

                ui->textRead->setText(temp);

                connect(TcpSocket,&QTcpSocket::readyRead,
                [=]()
                {
                    QByteArray array = TcpSocket->readAll();
                    ui->textRead->append(array);
                }

                );

            }
            );

}

Serverpart::~Serverpart()
{
    delete ui;
}


void Serverpart::on_buttonSend_clicked()
{
    if(TcpSocket==NULL){
        return;
    }
    QString str=ui->textWrite->toPlainText();
    TcpSocket->write(str.toUtf8().data());
}

void Serverpart::on_buttonDis_clicked()
{
    if(TcpSocket==NULL){
        return;
    }
    TcpSocket->disconnectFromHost();
    TcpSocket->close();
    TcpSocket=NULL;

}
