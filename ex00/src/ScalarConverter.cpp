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

bool isChar(const std::string &str) {
    return (str.length() == 1 && !std::isdigit(str[0]));
}

bool isInt(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    size_t i = (str[0] == '-' || str[0] == '+');
    size_t len = str.length();
    if (i == len) {
        return false;
    }
    for (; i < len; i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool isFloat(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    bool hasDot = false;
    bool hasF = false;
    size_t i = (str[0] == '-' || str[0] == '+');
    size_t len = str.length();
    if (i == len) {
        return false;
    }
    if (str == "nanf" || str == "-inff" || str == "+inff") {
        return true;
    }  
    for (; i < len; i++) {
        if (str[i] == '.') {
            hasDot = true;
        }
        else if (str[i] == 'f') {
            hasF = true;
        }
        else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    if (!hasDot || !hasF) {
        return false;
    }
    return true;
}

bool isDouble(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    bool hasDot = false;
    size_t i = (str[0] == '-' || str[0] == '+');
    size_t len = str.length();
    if (i == len) {
        return false;
    }
    if (str == "nan" || str == "-inf" || str == "+inf") {
        return true;
    }
    for (; i < len; i++) {
        if (str[i] == '.') {
            hasDot = true;
        }
        else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    if (!hasDot) {
        return false;
    }
    return true;
}

int parser(std::string &cppLiteral) {
    if (isChar(cppLiteral)) {
        return CHAR;
    }
    else if (isInt(cppLiteral)) {
        return INT;
    }
    else if (isFloat(cppLiteral)) {
        return FLOAT;
    }
    else if (isDouble(cppLiteral)) {
        return DOUBLE;
    }
    return UNKNOWN;
}

char toChar(const std::string &str) {
    return str[0];
}

float toFloat(const std::string &str) {
    char *end;
    //const char *specialFloatCases[] = {"+inff", "-inff", "nanf"};
    float f = std::strtof(str.c_str(), &end);
    // if(std::isnan(f)) {

    // }
    // else if (std::isinf(f)) {
    // }
    return f;
}

double toDouble(const std::string &str) {
    char *end;
    //const char *specialDoubleCases[] = {"+inf", "-inf", "nan"};

    double d = std::strtod(str.c_str(), &end);
    // if(std::isnan(d)) {

    // }
    // else if (std::isinf(d)) {
    // }
    return d;
}

long toLong(const std::string &str) {
    long l = std::atol(str.c_str());
    return l;
}

void fromChar(const std::string &str) {
    char c = toChar(str);

    std::cout << "char: ";
    if (!isascii(c)) {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(c)) {
        std::cout << "non displayble" << std::endl;
    }
    else {
        std::cout << "'" << c << "'" << std::endl;
    }
}

void fromInt(const std::string &str) {
    std::cout << "int: ";
    std::cout << toLong(str) << std::endl;
}

void fromFloat(const std::string &str) {
    std::cout << "float: ";
    std::cout << std::setprecision(1) << std::fixed << toFloat(str) << "f" << std::endl;
}

void fromDouble(const std::string &str) {
    std::cout << "double: ";
    std::cout << std::setprecision(1) << std::fixed << toDouble(str) << std::endl;
}

void printLiterals(const std::string &cppLiteral, int type) {
    (void)type;
    fromChar(cppLiteral);
    fromInt(cppLiteral);
    fromFloat(cppLiteral);
    fromDouble(cppLiteral);
}

void ScalarConverter::convert(std::string &cppLiteral) {
    int type = parser(cppLiteral);
    if (type == CHAR) {
        std::cout << "The parameter is a char literal" << std::endl;
    }
    else if (type == INT) {
        std::cout << "The parameter is an int literal" << std::endl;
    }
    else if (type == FLOAT) {
        std::cout << "The parameter is a float literal" << std::endl;
    }
    else if (type == DOUBLE) {
        std::cout << "The parameter is a double literal" << std::endl;
    }
    else {
        std::cout << "The parameter is not one of the types accepted" << std::endl;
    }
    printLiterals(cppLiteral, type);
}