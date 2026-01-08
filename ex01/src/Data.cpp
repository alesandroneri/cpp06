#include "../includes/Data.hpp"

std::ostream &operator<<(std::ostream &stream, const Data &data) {    
    stream << "name: "<< data.name << std::endl;
    stream << "nickname: "<< data.nickname << std::endl;
    stream << "age: "<< data.age << std::endl;
    return stream;
}