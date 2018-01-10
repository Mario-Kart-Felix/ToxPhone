#pragma once

#include "shared/steady_timer.h"
#include "shared/qt/quuidex.h"
#include "shared/qt/communication/host_point.h"
#include <QWidget>

namespace Ui {
class ConnectionWidget;
}

class ConnectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionWidget(QWidget *parent = 0);
    ~ConnectionWidget();

    void setInfo(const QString& info);

    const communication::HostPoint& hostPoint() const {return _hostPoint;}
    void setHostPoint(const communication::HostPoint&);

    bool isPointToPoint() const {return _isPointToPoint;}
    void setPointToPoint(bool val) {_isPointToPoint = val;}

    const QUuidEx& applId() const {return _applId;}
    void setApplId(const QUuidEx& val) {_applId = val;}

    bool connectStatus() const {return _connectStatus;}
    void setConnectStatus(bool val);

    int lifeTimeInterval() const {return _lifeTimeInterval;}
    void setLifeTimeInterval(int val) {_lifeTimeInterval = val;}

    void resetLifeTimer() {_lifeTimer.reset();}
    bool lifeTimeExpired() const;

private:
    Ui::ConnectionWidget *ui;

    communication::HostPoint _hostPoint;
    bool _isPointToPoint;
    QUuidEx _applId;
    bool _connectStatus = {false};
    int _lifeTimeInterval = {0};
    steady_timer _lifeTimer;
};
