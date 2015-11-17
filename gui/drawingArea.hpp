#ifndef DRAWINGAREA_HPP
#define DRAWINGAREA_HPP

#include <QGraphicsView>
#include <QGraphicsScene>

class drawingArea : public QGraphicsView
{
    Q_OBJECT
public:
    explicit drawingArea(QWidget *parent = 0);

signals:

public slots:
    void drawSomething();
private:
    QGraphicsScene _scene;
    std::vector<QRect> _cases;
    std::vector<QGraphicsRectItem*> _items;
};

#endif // DRAWINGAREA_HPP
