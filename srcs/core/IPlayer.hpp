#ifndef IPLAYER_H_
# define IPLAYER_H_

class IPlayer
{
public:
  enum		type
    {HUMAN, AI};
  enum		color
    {BLUE = 1, RED};

public:
  virtual ~IPlayer() {}

public:
  virtual unsigned int  getPoints() const = 0;
  virtual void    addPoints(unsigned int points) = 0;
  virtual type		getType() const = 0;
  virtual color		getColor() const = 0;
  virtual void		setPosition(unsigned int x, unsigned int y) = 0;
  virtual unsigned int	getX() const = 0;
  virtual unsigned int	getY() const = 0;
};

#endif /* !IPLAYER_H_ */
