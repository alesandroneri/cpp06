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
private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &copy);
  ScalarConverter &operator=(const ScalarConverter &copy);

public:
  static void convert(const std::string &cppLiteral);
};

#endif