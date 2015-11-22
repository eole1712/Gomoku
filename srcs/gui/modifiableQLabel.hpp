#ifndef MODIFIABLEQLABEL_HPP
#define MODIFIABLEQLABEL_HPP

#include <QWidget>
#include <QLabel>

class modifiableQLabel : public QLabel
{
    Q_OBJECT
public:
    explicit modifiableQLabel(QWidget *parent = 0);

signals:


public slots:
    void setQLabel();
};

#endif // MODIFIABLEQLABEL_HPP
