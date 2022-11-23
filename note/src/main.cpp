#include <iostream>
#include <string>
#include "parenthese.hpp"

int main()
{
    std::string str;
    std::cout << "Les parenthese sont elles ok ?";
    getline(std::cin, str);

    if (check_parentheses(str))
    {
        std::cout << "Cool tout est bon !";
    }
    else
    {
        std::cout << "Nope problème !";
    };
}