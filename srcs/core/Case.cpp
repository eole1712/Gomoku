#include <iostream>
#include "Case.hpp"

Case::Case()
{
    for (int i = 0; i < 6; i++) {
        tab[i] = 0;
    }
    prop = 0;
    setPosable(false, true);
    setPosable(true, true);
    setEmpty(true);
}

Case::~Case()
{
}

Case::Case(Case const &unit)
{
    if (&unit != this) {
        for (int i = 0; i < 6; i++) {
            tab[i] = unit.tab[i];
        }
        prop = unit.prop;
    }
}

void    Case::clear()
{
    for (int i = 0; i < 6; i++) {
        tab[i] = 0;
    }
    prop = 0;
}

bool    Case::isEmpty() const
{
    return (prop & 0b1000) >> 3;
}

void    Case::setEmpty(bool value)
{
    prop = (prop & 0b0111) + (value * 0b1000);
}

bool    Case::getColor() const
{
    return (prop & 0b0100) >> 2;
}

void                Case::setContent(caseContent c)
{
    setEmpty(c == EMPTY);
    setColor(c == RED);
    setPosable(false, c == EMPTY);
    setPosable(true, c == EMPTY);
}

Case::caseContent    Case::getContent() const
{
    if (isEmpty())
        return EMPTY;
    else
        return getColor() ? RED : BLUE;
}

void    Case::setColor(bool value)
{
    prop = (prop & 0b1011) + (value * 0b0100);
}

bool    Case::getPosable(bool color)
{
  //  std::cout << "YO" << (int)prop << "OY" << std::endl;

   // std::cout << "Blue : " << (int)((prop & 0b0010) >> 1) << "RED : " << (int)((prop & 0b0001)) << std::endl;
    if (color == false)
        return (prop & 0b0010) >> 1;
    else
        return (prop & 0b0001);
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
    //std::cout << "GET " << (int)d << " " << (int)p << " " << (int)color;

    uint64_t    pos = (63 - (32 * color) - (p * 8 + d));
    
    //std::cout << " " << ((tab[0] & (uint64_t)(pow(2, pos))) >> pos) << std::endl;
    
    return (tab[0] & (uint64_t)(pow(2, pos))) >> pos;
}

void    Case::setValue2(Case::dir d, Case::pat2 p, bool color, bool value)
{
    //std::cout << "SET " << (int)d << " " << (int)p << " " << (int)color << " " << (int)value << std::endl;
    uint64_t    pos = (63 - (32 * color) - (p * 8 + d));
    uint64_t    pow_of_pos = std::pow(2, pos);
    
    tab[0] = (tab[0] & (UINT64_MAX - pow_of_pos)) + (value * pow_of_pos);
}

bool    Case::getValue3(Case::dir d, Case::pat3 p, bool color) const
{
    int         i = 1;
    
    int pos = (63 - (80 * color) - (p * 8 + d));
    
    while (pos < 0) {
        pos += 64;
        i += 1;
    }
    
    return (tab[i] & (uint64_t)(pow(2, pos))) >> pos;
}

void        Case::setValue3(Case::dir d, Case::pat3 p, bool color, bool value)
{
    int         i = 1;

    int pos = (63 - (80 * color) - (p * 8 + d));
    
    while (pos < 0) {
        pos += 64;
        i += 1;
    }
    
    uint64_t    pow_of_pos = std::pow(2, pos);
    tab[i] = (tab[i] & (UINT64_MAX - pow_of_pos)) + (value * pow_of_pos);
    
    if (p == XOYOX || p == XYX) {
        d = (dir)(((int)(d) + 4) % 8);
        i = 1;
        pos = (63 - (80 * color) - (p * 8 + d));
        
        while (pos < 0) {
            pos += 64;
            i += 1;
        }
        
        pow_of_pos = std::pow(2, pos);
        tab[i] = (tab[i] & (UINT64_MAX - pow_of_pos)) + (value * pow_of_pos);
    }
}

bool    Case::getValue4(Case::dir d, Case::pat4 p, bool color) const
{
    //std::cout << (int)d << " " << (int)p << " " << (int)color;
    
    int         i = 3;
    
    int pos = (31 - (56 * color) - (p * 8 + d));
    
    while (pos < 0) {
        pos += 64;
        i += 1;
    }
    
    //std::cout << " " << ((tab[i] & (uint64_t)(pow(2, pos))) >> pos) << std::endl;
    
    return (tab[i] & (uint64_t)(pow(2, pos))) >> pos;
}

void        Case::setValue4(Case::dir d, Case::pat4 p, bool color, bool value)
{
    int         i = 3;
    
    int pos = (31 - (56 * color) - (p * 8 + d));
    
    while (pos < 0) {
        pos += 64;
        i += 1;
    }
    
    uint64_t    pow_of_pos = std::pow(2, pos);
    tab[i] = (tab[i] & (UINT64_MAX - pow_of_pos)) + (value * pow_of_pos);
}

bool    Case::getValue5(Case::dir d, Case::pat5 p, bool color) const
{
    int pos = (47 - (24 * color) - (p * 8 + d));
    
    return (tab[5] & (uint64_t)(pow(2, pos))) >> pos;
}

void        Case::setValue5(Case::dir d, Case::pat5 p, bool color, bool value)
{
    int pos = (47 - (24 * color) - (p * 8 + d));
    
    uint64_t    pow_of_pos = std::pow(2, pos);
    tab[5] = (tab[5] & (UINT64_MAX - pow_of_pos)) + (value * pow_of_pos);
    
    if (p == XXYXX) {
        d = (dir)(((int)(d) + 4) % 8);
        pos = (47 - (24 * color) - (p * 8 + d));
        
        uint64_t    pow_of_pos = std::pow(2, pos);
        tab[5] = (tab[5] & (UINT64_MAX - pow_of_pos)) + (value * pow_of_pos);

    }
}

void        Case::resetValue(Case::dir d, bool color)
{
    for (unsigned int i = 0; i < 4; i++) {
        setValue2(d, (pat2)(i), color, false);
    }
    for (unsigned int i = 0; i < 10; i++) {
        setValue3(d, (pat3)(i), color, false);
    }
    for (unsigned int i = 0; i < 7; i++) {
        setValue4(d, (pat4)(i), color, false);
    }
    for (unsigned int i = 0; i < 3; i++) {
        setValue5(d, (pat5)(i), color, false);
    }
}

