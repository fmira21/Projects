#include "mutantstack.hpp"
#include <list>


int main()
{
    // Mstack
    std::cout << BOLDWHITE << "My MutantStack: " << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    std::cout << DEFAULT << std::endl << std::endl;

    // List
    std::cout << BOLDWHITE << "Standard list: " << DEFAULT << std::endl;
    std::cout << BOLDBLUE;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator itl = lst.begin();
    std::list<int>::iterator itel = lst.end();
    ++itl;
    --itl;
    while (itl != itel)
    {
    std::cout << *itl << std::endl;
    ++itl;
    }
    std::list<int> sl(lst);
    std::cout << DEFAULT << std::endl << std::endl;

    // Deque
    std::cout << BOLDWHITE << "Standard deque: " << DEFAULT << std::endl;
    std::cout << BOLDBLUE;
    std::deque<int> dq;
    dq.push_back(5);
    dq.push_back(17);
    std::cout << dq.back() << std::endl;
    dq.pop_back();
    std::cout << dq.size() << std::endl;
    dq.push_back(3);
    dq.push_back(5);
    dq.push_back(737);
    dq.push_back(0);
    std::deque<int>::iterator itd = dq.begin();
    std::deque<int>::iterator ited = dq.end();
    ++itd;
    --itd;
    while (itd != ited)
    {
    std::cout << *itd << std::endl;
    ++itd;
    }
    std::deque<int> sd(dq);
    std::cout << DEFAULT << std::endl << std::endl;

    return 0;
}