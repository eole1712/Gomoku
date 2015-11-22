#include "gomokuButton.hpp"

GomokuButton::GomokuButton(int x, int y, QWidget *) :
    QPushButton(""), _x(x), _y(y)
{
    setStyleSheet("background-color:grey;max-width: 100%;height: auto;");
}


int GomokuButton::getX() const
{
    return _x;
}

int GomokuButton::getY() const
{
    return _y;
}
