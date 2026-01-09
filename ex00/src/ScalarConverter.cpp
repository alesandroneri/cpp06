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

static bool isChar(const std::string &str) {
    return (str.length() == 1 && !std::isdigit(str[0]));
}

static bool isInt(const std::string &str) {
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

static bool isFloat(const std::string &str) {
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
    if (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff") {
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

static bool isDouble(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    bool hasDot = false;
    size_t i = (str[0] == '-' || str[0] == '+');
    size_t len = str.length();
    if (i == len) {
        return false;
    }
    if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf") {
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

static int parser(std::string &cppLiteral) {
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

static char toChar(const std::string &str) {
    return str[0];
}

static float toFloat(const std::string &str) {
    char *end;
    float f = std::strtof(str.c_str(), &end);
    return f;
}

static double toDouble(const std::string &str) {
    char *end;
    double d = std::strtod(str.c_str(), &end);
    return d;
}

static long toLong(const std::string &str) {
    long l = std::atol(str.c_str());
    return l;
}

static void fromChar(const std::string &str) {
    char c = toChar(str);
    if (!isascii(c)) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(c)) {
        std::cout << "char: non displayble" << std::endl;
    }
    else {
        std::cout << "char: '" << c << "'" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(c) << std::endl;

}

static void printChar(int c)
{
    if (!isascii(c)) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(c)) {
        std::cout << "char: non displayble" << std::endl;
    }
    else {
        std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
    }
}

static void fromInt(const std::string &str) {
    long l = toLong(str);
    int i = std::atoi(str.c_str());
    printChar(static_cast<char>(i));
    l > INT_MAX || l < INT_MIN ? std::cout << "int: impossible" << std::endl : std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(i) << std::endl;
}

static void fromFloat(const std::string &str) {
    float f = toFloat(str);
    long l = toLong(str);

    if(std::isnan(f) || std::isinf(f)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else {
        printChar(static_cast<char>(f));
        l > INT_MAX || l < INT_MIN ? std::cout << "int: impossible" << std::endl : std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void fromDouble(const std::string &str) {
    double d = toDouble(str);
    long l = toLong(str);
    if(std::isnan(d) || std::isinf(d)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else {
        printChar(static_cast<char>(d));
        l > INT_MAX || l < INT_MIN ? std::cout << "int: impossible" << std::endl : std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

static void printLiterals(const std::string &cppLiteral, int type) {
    if (type == CHAR) {
        fromChar(cppLiteral);
    }
    else if (type == INT) {
        fromInt(cppLiteral);
    }
    else if (type == FLOAT) {
        fromFloat(cppLiteral);
    }
    else if (type == DOUBLE) {
        fromDouble(cppLiteral);
    }
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