#ifndef IPLAYER_H_
# define IPLAYER_H_

# include <string>

class IPlayer
{
public:
  enum		type
    {HUMAN, IA};
  enum		color
    {BLUE = 1, RED};

public:
  virtual ~IPlayer() {}

public:
  virtual type		getType() const = 0;
  virtual color		getColor() const = 0;
};

#endif /* !IPLAYER_H_ */
