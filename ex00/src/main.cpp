#include "../includes/ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
  if (ac == 2) {
    std::string parameter = (std::string)av[1];
    
    ScalarConverter::convert(parameter);
  } else {
    std::cout << "Number of arguments invalid" << std::endl;
  }
  return 0;
}