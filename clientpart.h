#ifndef CLIENTPART_H
#define CLIENTPART_H

#include <QWidget>
#include<QTcpSocket>
namespace Ui {
class ClientPart;
}

class ClientPart : public QWidget
{
    Q_OBJECT

public:
    explicit ClientPart(QWidget *parent = nullptr);
    ~ClientPart();

private slots:
    void on_connectbutton_clicked();

    void on_sendbutton_clicked();

    void on_disconnectbutton_clicked();

private:
    Ui::ClientPart *ui;
    QTcpSocket *tcpsocket;
};

#endif // CLIENTPART_H
