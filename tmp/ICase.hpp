#ifndef ICASE_H_
# define ICASE_H_

class ICase
{
public:
  virtual ~ICase() {}
  virtual getHeuristic() const = 0;
};

#endif /* !ICASE_H_ */
