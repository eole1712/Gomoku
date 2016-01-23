#ifndef CASE_HPP_
# define CASE_HPP_

class Case
{
public:
  enum	caseContent {EMPTY = 0, BLUE, RED};

  Case();
  ~Case();

  Case::caseContent	getContent() const;
  char			getHeuristic(unsigned int numPlayer) const;

  void			setContent(Case::caseContent);
  void			setHeuristic(unsigned int numPlayer, char heuristic);

private:
  Case::caseContent	_content;
  char			_heuristic[2];
};

#endif /* !CASE_HPP_ */
