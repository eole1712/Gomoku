//
//  Case.hpp
//  Gomoku
//
//  Created by Grisha Ghukasyan on 23/01/2016.
//
//

#ifndef Case_hpp
#define Case_hpp

#include <cmath>
#include <stdint.h>

class Case {
    
public:
    enum dir {NW = 0, N, NE, W, E, SW, S, SE};
    enum pat2 {YX = 0, YOX, YOOX, YOOOX};
    enum pat3 {YXX = 0, YOXX, YOOXX, YXOX, YXOOX, YOXOX, XYX, XYOX, XYOOX, XOYOX};
    enum pat4 {YXXX = 0, YOXXX, YXOXX, YXXOX, XYXX, XYOXX, XYXOX};
    enum pat5 {YXXXX = 0, XYXXX, XXYXX};

public:
    Case();
    ~Case();
    
public:
    void    setValue2(dir, pat2, bool color, bool);
    void    setValue3(dir, pat3, bool color, bool);
    void    setValue4(dir, pat4, bool color, bool);
    void    setValue5(dir, pat5, bool color, bool);
    
public:
    bool    getValue2(dir, pat2, bool color) const;
    bool    getValue3(dir, pat3, bool color) const;
    bool    getValue4(dir, pat4, bool color) const;
    bool    getValue5(dir, pat5, bool color) const;
    
public:
    void    setColor(bool);
    bool    getColor() const;

public:
    void    setEmpty(bool);
    bool    isEmpty() const;
    
public:
    void    setPosable(bool color, bool value);
    bool    getPosable(bool color);

private:
    uint64_t    tab[3];
    uint8_t     prop;
};

#endif /* Case_hpp */
