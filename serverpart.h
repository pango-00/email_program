#ifndef SERVERPART_H
#define SERVERPART_H
#include<QTcpServer>
#include<QTcpSocket>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Serverpart; }
QT_END_NAMESPACE

class Serverpart : public QWidget
{
    Q_OBJECT

public:
    Serverpart(QWidget *parent = nullptr);
    ~Serverpart();

private slots:
    void on_buttonSend_clicked();

    void on_buttonDis_clicked();

private:
    Ui::Serverpart *ui;
    QTcpServer * TcpServer;
    QTcpSocket * TcpSocket;
};
#endif // SERVERPART_H
