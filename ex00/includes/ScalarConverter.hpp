#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum Type {
    CHAR,
    FLOAT,
    DOUBLE,
    INT,
    UNKNOWN,
};

class ScalarConverter {
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);

        /*
        toChar
        toInt
        toFloat
        toDouble
        */

        static void convert(std::string &cppLiteral);
};

#endif