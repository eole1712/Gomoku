#ifndef CASE_HPP_
# define CASE_HPP_

class Case
{
public:
  enum	caseContent {EMPTY = 0, BLUE, RED};

  Case();
  ~Case();

  Case::caseContent	getContent() const;
  char			getHeuristic() const;

  void			setContent(Case::caseContent);
  void			setHeuristic(char);

private:
  Case::caseContent	_content;
  char			_heuristic;
};

#endif /* !CASE_HPP_ */
