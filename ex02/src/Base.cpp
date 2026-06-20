#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <string>
#include <ctime>
#include <iostream>
#include <exception>

Base::~Base(){}

Base * generate(void) {
    Base *b = NULL;
    static int counter = 0;
    std::srand(std::time(0) + counter++);

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

void identify(Base *p) {
    if (p == NULL) {
        std::cout << "Pointer is NULL" << std::endl;
        return;
    }
    if (dynamic_cast<A *>(p) != NULL) {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p) != NULL) {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p) != NULL) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p) {

    try {
        static_cast<void>(dynamic_cast<A &>(p));
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        static_cast<void>(dynamic_cast<B &>(p));
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        static_cast<void>(dynamic_cast<C &>(p));
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e) {}
}