#ifndef GOMOKUBUTTON_HPP
#define GOMOKUBUTTON_HPP

#include <QPushButton>
#include <QMouseEvent>

class GomokuButton : public QPushButton
{
    Q_OBJECT
public:
    typedef std::function<void (QMouseEvent* e)> MouseEventHandler;
    explicit GomokuButton(int x, int y, QWidget *parent = 0);
    int getX() const;
    int getY() const;
    void OnMouseMove(MouseEventHandler);
    void mouseMoveEvent(QMouseEvent* e);
    void setEmpty(bool isDefined);
    bool isEmpty();
signals:


public slots:

private:
    int _x;
    int _y;
    MouseEventHandler _mouseMove;
    bool _colorDerfined = false;
};

#endif // GOMOKUBUTTON_HPP
