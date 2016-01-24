#ifndef VEC2_HPP_
#define VEC2_HPP_

#include <cmath>

struct vec2
{
  int	x;
  int	y;
  
  vec2()
    : x(0), y(0)
  {}
  

  vec2(int const & a, int const & b)
    : x(a), y(b)
  {}
  
  vec2(int * c)
    : x(c[0]), y(c[1])
  {}
  
  vec2(int const & c)
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
  
  
  vec2 		operator-(const int b) const
  {
    return{ x - b, y - b };
  }
  
  vec2 		operator+(const int b) const
  {
    return{ x + b, y + b };
  }
  
  vec2 		operator*(const int b) const
  {
    return{ x * b, y * b };
  }
  
  vec2 		operator/(const int b) const
  {
    return{ x / b, y / b };
  }
    
  vec2 & 		operator-=(const int b)
  {
    x -= b;
    y -= b;
    return *this;
  }
  
  vec2 & 		operator+=(const int b)
  {
    x += b;
    y += b;
    return *this;
  }
  
  vec2 & 		operator*=(const int b)
  {
    x *= b;
    y *= b;
    return *this;
  }
  
  vec2 & 		operator/=(const int b)
  {
    x /= b;
    y /= b;
    return *this;
  }
  
  vec2		operator-() const
  {
    return{ -x, -y };
  }
  
  inline int & operator[](unsigned int i)
  {
    return reinterpret_cast<int *>(this)[i];
  }
  
  bool		operator==(const vec2 & b) const
  {
    return x == b.x && y == b.y;
  }

  bool		operator!=(const vec2 & b) const
  {
    return x != b.x || y != b.y;
  }
  
  void		clear()
  {
    x = 0;
    y = 0;
  }
  
  int	dot(const vec2 & b) const
  {
    return{ x * b.x + y * b.y };
  }
  
  int	length() const
  {
    return int(sqrt(x * x + y * y));
  }
  
  vec2 &	normalie()
  {
    int len = length();
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
