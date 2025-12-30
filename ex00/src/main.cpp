#include "../includes/ScalarConverter.hpp"

int main (int ac, char **av) {
    if (ac == 2) {
        ScalarConverter conv;

        std::string parameter = (std::string) av[1];
        conv.convert(parameter);
    }
    return 0;
}