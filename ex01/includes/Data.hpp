#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <ostream>

struct Data {
    std::string name;
    int age;
    std::string nickname;
};

std::ostream &operator<<(std::ostream &stream, const Data &data); 

#endif