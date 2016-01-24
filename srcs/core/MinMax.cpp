#include "MinMax.hpp"

 #include <iostream>
#include <fstream>

MinMax::MinMax(Node::MapType map)
{
  m_current = new Node(map, std::pair<int, int>(0, 0));
}

MinMax::~MinMax()
{

}

std::pair<int, int> MinMax::evaluate(int depth)
{
    Node *best = nullptr;
    std::ofstream os;

    os.open("graph.dot");

    m_current->evaluate(depth, Node::loose, Node::win);
    os << "digraph MinMax {" << std::endl;
    m_current->print(os);
    os << "}" << std::endl;
    for (auto& elem : m_current->getChildren())
    {
        std::cout << "children note " << elem->getNote() << "vs " << m_current->getNote() << std::endl;
        if (elem->getNote() == m_current->getNote())
        {
            best = elem;
            break;
        }
    }

    std::cout << "ok" << std::endl;
    if (best == nullptr) {
        std::cerr << "wtf?" << std::endl;
        return std::make_pair(0, 0);
    }
    m_current->deleteExcept(best->getMove(), true);
    m_current = best;
    std::cout << m_current->getNote() << std::endl;

    return m_current->getMove();
}
