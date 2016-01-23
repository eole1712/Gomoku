#include "Case.hpp"

Case::Case()
{
    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 0;
    prop = 0;
    
    setEmpty(true);
}

Case::~Case()
{
}

bool    Case::isEmpty() const
{
    return prop & 0b1000;
}

void    Case::setEmpty(bool value)
{
    prop = (prop & 0b0111) + (value * 0b1000);
}

bool    Case::getColor() const
{
    return prop & 0b0100;
}

void    Case::setColor(bool value)
{
    prop = (prop & 0b1011) + (value * 0b0100);
}

bool    Case::getPosable(bool color)
{
    if (color == false)
        return prop & 0b0010;
    else
        return prop & 0b0001;
}

void    Case::setPosable(bool color, bool value)
{
    if (color == false)
        prop = (prop & 0b1101) + (value * 0b0010);
    else
        prop = (prop & 0b1110) + (value * 0b0001);
}

// 1111111111 = 2^10 - 1
// 0000011111 = 2^5 - 1
// 0000100000 = 2^5
// 1111011111 = (2^10 - 1) - 2^5

bool    Case::getValue2(Case::dir d, Case::pat2 p, bool color) const
{
    uint64_t    pos = (63 - (32 * color) - (p * 8 + d));

    return (tab[0] & (uint64_t)(pow(2, pos))) >> pos;
}

void    Case::setValue2(Case::dir d, Case::pat2 p, bool color, bool value)
{
    uint64_t    pos = (63 - (32 * color) - (p * 8 + d));
    uint64_t    pow_of_pos = std::pow(2, pos);
    
    tab[0] = (tab[0] & (UINT64_MAX - pow_of_pos)) + (value * pow_of_pos);
}


bool    Case::getValue3(Case::dir d, Case::pat3 p) const
{
    //return tab[0] & (uint64_t)(std::pow(2, (63 - (p * 8 + d))));
}

void    Case::setValue3(Case::dir d, Case::pat3 p, bool value)
{
    if (p < XYX)
    {
        int nb = 32 + (p * 8 + d);
        if (nb <= 63)
        {
            uint64_t    pos = std::pow(2, (63 - nb));
            
            tab[0] = std::pow(2, 63) + (tab[0] & (pos - 1)) + (value * pos);
        }
        else
        {
            uint64_t    pos = std::pow(2, (126 - nb));
            
            tab[1] = (tab[1] & (pos - 1)) + (value * pos);
        }
    }
    else
    {
        uint64_t pos = std::pow(2, (17 - (p - 5)));

        tab[1] = (tab[1] & (pos - 1)) + (value * pos);
    }
}