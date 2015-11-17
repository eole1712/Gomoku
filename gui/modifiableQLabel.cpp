#include "modifiableQLabel.hpp"
#include <iostream>

/*!
 * \brief modifiableQLabel::modifiableQLabel spécifie QLabel pour pouvoir mettre un message quand un bouton est cliqué
 * \param parent
 */

modifiableQLabel::modifiableQLabel(QWidget *parent) :
    QLabel(parent)
{
}

void modifiableQLabel::setQLabel()
{
    std::cout << "yolo je passe" << std::endl;
    this->setText("Un bouton a été Cliqué !");
}
