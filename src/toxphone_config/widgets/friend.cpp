#include "friend.h"
#include "ui_friend.h"

FriendWidget::FriendWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendWidget)
{
    ui->setupUi(this);
}

FriendWidget::~FriendWidget()
{
    delete ui;
}

void FriendWidget::setProperties(const data::FriendItem& val)
{
    _properties = val;

    QString msg;
    if (!_properties.nameAlias.isEmpty())
        msg = QString("%1 (%2)").arg(_properties.nameAlias)
                                .arg(_properties.name);
    else
        msg = _properties.name;

    ui->labelFriendName->setText(msg);

    msg = _properties.statusMessage.trimmed();
    ui->labelFriendStatus->setText(msg);
    ui->labelFriendStatus->setVisible(!msg.isEmpty());

    if (_properties.phoneNumber != 0)
        ui->labelPhoneNumber->setText(QString("*%1#").arg(_properties.phoneNumber));
    else
        ui->labelPhoneNumber->clear();

//    switch (_properties.changeFlag)
//    {
//        case data::FriendItem::ChangeFlag::Name:
//            fw->setName(friendItem.name);
//            break;
//        case data::FriendItem::ChangeFlag::StatusMessage:
//            fw->setStatusMessage(friendItem.statusMessage);
//            break;
//        case data::FriendItem::ChangeFlag::IsConnecnted:
//            fw->setConnectStatus(friendItem.isConnecnted);
//            break;
//        default:
//            break;
//    }

    if (_properties.isConnecnted)
        ui->labelOnlineStatus->setText("O");
    else
        ui->labelOnlineStatus->setText("X");
}

//QString FriendWidget::name() const
//{
//    return ui->labelFriendName->text();
//}

//void FriendWidget::setName(const QString& val)
//{
//    QString ss = ui->labelFriendName->text();

//    ui->labelFriendName->setText(val);
//}

//void FriendWidget::setStatusMessage(const QString& val)
//{
//    ui->labelFriendStatus->setText(val);
//}

//QByteArray FriendWidget::publicKey() const
//{
//    return _publicKey;
//}

//void FriendWidget::setPublicKey(const QByteArray& val)
//{
//    _publicKey = val;

//}

//void FriendWidget::setConnectStatus(bool val)
//{
//    _isConnected = val;
//    if (_isConnected)
//        ui->labelOnlineStatus->setText("O");
//    else
//        ui->labelOnlineStatus->setText("X");

//}
