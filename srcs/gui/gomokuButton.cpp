#include "gomokuButton.hpp"
#include <iostream>

GomokuButton::GomokuButton(int x, int y, QWidget *) :
    QPushButton(""), _x(x), _y(y)
{
    setStyleSheet("background-color:grey;max-width: 100%;height: auto;");
    setMouseTracking(true);
}


int GomokuButton::getX() const
{
    return _x;
}

int GomokuButton::getY() const
{
    return _y;
}

void GomokuButton::OnMouseMove(MouseEventHandler action)
{
    _mouseMove = action;
}

void GomokuButton::mouseMoveEvent(QMouseEvent* e)
{
    _mouseMove(e);
}

void GomokuButton::setEmpty(bool isDefined)
{
    _colorDerfined = isDefined;
}

bool GomokuButton::isEmpty()
{
    return !_colorDerfined;
}
