#include "../includes/ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    if (this != &copy) {
        *this = copy;
    }
    return *this;
}

std::string toChar(std::string &str) {
    if (str.length() == 1) {
        if (!isascii(str[0])) {
            return "impossible";
        }
        if (std::isprint(str[0])) {
    
            return "'" + str + "'";
        }
        else {
            return "non displayble";
        }
    }
    return "impossible";
}

float toFloat(std::string &str) {
    char *end;
    //const char *specialFloatCases[] = {"+inff", "-inff", "nanf"};
    float f = std::strtof(str.c_str(), &end);
    if(std::isnan(f)) {

    }
    else if (std::isinf(f)) {
    }
    return f;
}

double toDouble(std::string &str) {
    char *end;
    //const char *specialDoubleCases[] = {"+inf", "-inf", "nan"};

    double d = std::strtod(str.c_str(), &end);
    if(std::isnan(d)) {

    }
    else if (std::isinf(d)) {
    }
    return d;
}

int toInt(std::string &str) {
    long i = std::atol(str.c_str());
    if (i < INT_MIN || i > INT_MAX) {
        //impossible
    }
    return (int)i;
}

void ScalarConverter::convert(std::string &cppLiteral) {
    if (cppLiteral.empty())
        return;
    std::cout << "char: " << toChar(cppLiteral) << std::endl;
    std::cout << "int: " << toInt(cppLiteral) << std::endl;
    std::cout << "float: " << std::setprecision(1) << std::fixed << toFloat(cppLiteral) << "f" << std::endl;
    std::cout << "double: " << toDouble(cppLiteral) << std::endl;
}