#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>

Base::~Base(){}

Base * generate(void) {
    Base *b = NULL;
    std::string cases[3] = {"A", "B", "C"};

    int i = std::rand() % 3;
    switch (i)
    {
        case 0:
        b = dynamic_cast<Base *>(new A());
        break;
    case 1:
        b = dynamic_cast<Base *>(new B());
        break;
    case 2:
        b = dynamic_cast<Base *>(new C());
        break;
    default:
        break;
    }
    return b;
}
void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Pointer is NULL" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    if (typeid(p) == typeid(A))
        std::cout << "A" << std::endl;
    else if (typeid(p) == typeid(B))
        std::cout << "B" << std::endl;
    else if (typeid(p) == typeid(C))
        std::cout << "C" << std::endl;
}