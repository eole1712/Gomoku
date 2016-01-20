#ifndef CASE_HPP_
# define CASE_HPP_

class Case
{
public:
  enum	caseContent {EMPTY = 0, BLUE, RED};

  Case();
  ~Case();

  Case::caseContent	getCaseContent();

  void			setCaseContent(Case::caseContent);

private:
  Case::caseContent	_content;
};

#endif /* !CASE_HPP_ */
