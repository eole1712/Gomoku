#ifndef WINCHANGER_HPP
#define WINCHANGER_HPP

#include <QFrame>
#include <QStackedWidget>

class winChanger : public QStackedWidget
{
    Q_OBJECT
public:
    explicit winChanger(QWidget *parent = 0);

signals:

public slots:
    void nextWidget();
    void prevWidget();

};

#endif // WINCHANGER_HPP
