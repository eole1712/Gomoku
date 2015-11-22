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
    this->setText("not Implemented : Player vs IA");
}
