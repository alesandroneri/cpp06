
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    std::srand(std::time(0));
    std::cout << "Testing with pointers:" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* obj = generate();
        std::cout << "Object " << i << ": ";
        identify(obj);
        delete obj;
    }
    
    std::cout << "\nTesting with references:" << std::endl;
    A a;
    B b;
    C c;
    
    std::cout << "Reference 1: ";
    identify(a);
    
    std::cout << "Reference 2: ";
    identify(b);
    
    std::cout << "Reference 3: ";
    identify(c);
    
    std::cout << "\nTesting with converted pointers to references:" << std::endl;
    Base* obj1 = new A();
    Base* obj2 = new B();
    Base* obj3 = new C();
    
    std::cout << "Obj1: ";
    identify(*obj1);
    
    std::cout << "Obj2: ";
    identify(*obj2);
    
    std::cout << "Obj3: ";
    identify(*obj3);
    
    delete obj1;
    delete obj2;
    delete obj3;
    
    return 0;
}