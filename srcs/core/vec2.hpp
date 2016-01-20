#ifndef VEC2_HPP_
#define VEC2_HPP_

#include <cmath>

typedef int cordinate;

struct vec2
{
  cordinate	x;
  cordinate	y;
  
  vec2()
    : x(0), y(0)
  {}
  

  vec2(cordinate const & a, cordinate const & b)
    : x(a), y(b)
  {}
  
  vec2(cordinate * c)
    : x(c[0]), y(c[1])
  {}
  
  vec2(cordinate const & c)
    : x(c), y(c)
  {}
  
  vec2(vec2 const & c)
    : x(c.x), y(c.y)
  {}
  
  vec2 &		operator=(const vec2 & c)
  {
    x = c.x;
    y = c.y;
    return *this;
  }
  
  vec2 		operator-(const vec2 & b) const
  {
    return{ x - b.x, y - b.y };
  }

  vec2 		operator+(const vec2 & b) const
  {
    return{ x + b.x, y + b.y};
  }
  
  vec2 		operator*(const vec2 & b) const
  {
    return{ x * b.x, y * b.y };
  }
  
  vec2 		operator/(const vec2 & b) const
  {
    return{ x / b.x, y / b.y };
  }
  
  vec2 & 		operator-=(const vec2 & b)
  {
    x -= b.x;
    y -= b.y;
    return *this;
  }
  
  vec2 & 		operator+=(const vec2 & b)
  {
    x += b.x;
    y += b.y;
    return *this;
  }
  
  vec2 & 		operator*=(const vec2 & b)
  {
    x *= b.x;
    y *= b.y;
    return *this;
  }
  
  vec2 & 		operator/=(const vec2 & b)
  {
    x /= b.x;
    y /= b.y;
    return *this;
  }
  
  
  vec2 		operator-(const cordinate b) const
  {
    return{ x - b, y - b };
  }
  
  vec2 		operator+(const cordinate b) const
  {
    return{ x + b, y + b };
  }
  
  vec2 		operator*(const cordinate b) const
  {
    return{ x * b, y * b };
  }
  
  vec2 		operator/(const cordinate b) const
  {
    return{ x / b, y / b };
  }
    
  vec2 & 		operator-=(const cordinate b)
  {
    x -= b;
    y -= b;
    return *this;
  }
  
  vec2 & 		operator+=(const cordinate b)
  {
    x += b;
    y += b;
    return *this;
  }
  
  vec2 & 		operator*=(const cordinate b)
  {
    x *= b;
    y *= b;
    return *this;
  }
  
  vec2 & 		operator/=(const cordinate b)
  {
    x /= b;
    y /= b;
    return *this;
  }
  
  vec2		operator-() const
  {
    return{ -x, -y };
  }
  
  inline cordinate & operator[](unsigned int i)
  {
    return reinterpret_cast<cordinate *>(this)[i];
  }
  
  bool		operator==(const vec2 & b) const
  {
    return x == b.x && y == b.y;
  }
  
  void		clear()
  {
    x = 0;
    y = 0;
  }
  
  cordinate	dot(const vec2 & b) const
  {
    return{ x * b.x + y * b.y };
  }
  
  cordinate	length() const
  {
    return cordinate(sqrt(x * x + y * y));
  }
  
  vec2 &	normalie()
  {
    cordinate len = length();
    if (len != 0)
      *this /= len;
    return *this;
  }
 
  bool		inBound(vec2 minMax)
  {
    return (x > minMax.x && y > minMax.x && x < minMax.y && y < minMax.y);
  }
};

#endif /* VEC2_HPP_ */
