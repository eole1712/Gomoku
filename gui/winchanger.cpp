#include "winchanger.hpp"
#include <iostream>

/*!
 * \brief winChanger::winChanger :
 * Herite de QStackedWidget et implemente des slots de séléction de vue
 * \param parent
 */

winChanger::winChanger(QWidget *parent) :
    QStackedWidget(parent)
{
}

void winChanger::nextWidget()
{
    this->setCurrentIndex(0);
    std::cout << this->currentIndex() << std::endl;
}

void winChanger::prevWidget()
{
    this->setCurrentIndex(1);
    std::cout << this->currentIndex() << std::endl;
}
