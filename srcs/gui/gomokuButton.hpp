#ifndef GOMOKUBUTTON_HPP
#define GOMOKUBUTTON_HPP

#include <QPushButton>

class GomokuButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GomokuButton(int x, int y, QWidget *parent = 0);
    int getX() const;
    int getY() const;
signals:


public slots:

private:
    int _x;
    int _y;
};

#endif // GOMOKUBUTTON_HPP
