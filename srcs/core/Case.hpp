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
    enum caseContent {EMPTY, BLUE, RED};
    
public:
    enum dir {N = 0, NW, W, SW, S, SE, E, NE};
    enum pat2 : unsigned int {YX = 0, YOX, YOOX, YOOOX};
    enum pat3 : unsigned int {YXX = 0, YOXX, YOOXX, YXOX, YXOOX, YOXOX, XYOX, XYOOX, XOYOX, XYX};
    enum pat4 : unsigned int {YXXX = 0, YOXXX, YXOXX, YXXOX, XYXX, XYOXX, XYXOX};
    enum pat5 : unsigned int {YXXXX = 0, XYXXX, XXYXX};

public:
    Case();
    ~Case();
    
    Case(Case const &unit);
    
public:
    void clear();
    
public:
    void    setValue2(dir, pat2, bool color, bool);
    void    setValue3(dir, pat3, bool color, bool);
    void    setValue4(dir, pat4, bool color, bool);
    void    setValue5(dir, pat5, bool color, bool);

public:
    void    resetValue(dir, bool color);
    
public:
    bool    getValue2(dir, pat2, bool color) const;
    bool    getValue3(dir, pat3, bool color) const;
    bool    getValue4(dir, pat4, bool color) const;
    bool    getValue5(dir, pat5, bool color) const;
    
public:
    void    setColor(bool);
    void    setContent(caseContent);
    
    bool            getColor() const;
    caseContent     getContent() const;

public:
    void    setEmpty(bool);
    bool    isEmpty() const;
    
public:
    void    setPosable(bool color, bool value);
    bool    getPosable(bool color);

private:
    uint64_t    tab[6];
    uint8_t     prop;
};

#endif /* Case_hpp */
