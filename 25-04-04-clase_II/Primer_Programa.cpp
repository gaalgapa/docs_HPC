#include <iostream>
#include <string>

int main(void)
{
    std::string name;
    std::cout << "escriba su nombre por favor:" << std::endl;
    std::getline(std::cin, name);
    std::cout << "Bienvenido " + name + "\n";
    return 0;
}