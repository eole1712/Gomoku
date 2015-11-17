#include "drawingArea.hpp"
#include <QGraphicsRectItem>
#include <iostream>

drawingArea::drawingArea(QWidget *parent) :
    QGraphicsView(parent), _scene(this)
{
    int width = this->width() * -1;
    int height = this->height() * -1;
    int wincr = (this->width() * 2) / 19;
    int hincr = (this->height() * 2) / 19;

    setScene(&_scene);
    //std::cout << this->width() * -1 << ", " << this->height() * -1 << std::endl;
    while (width < this->width())
    {
        while (height < this->height()) {
            //std::cout << width << ", " << height << std::endl;
            _items.push_back(new QGraphicsRectItem(width, height, wincr, hincr, _scene.activePanel()));
            height += hincr;
        }
        width += wincr;
    }
}

void drawingArea::drawSomething()
{
    for(auto rect : _items)
      _scene.addItem(rect);

    std::cout << this->width() * -1 << ", " << this->height() * -1 << std::endl;
    //_scene.addRect(this->width() * -1, this->height() * -1, (this->width() * 2) / 19, (this->height() * 2) / 19);
     //_scene.addRect(this->width() * -1, this->height() * -1, (this->width() * 2) / 19, (this->height() * 2) / 19);
    setScene(&_scene);
}
