#include <iostream>

#include <iomanip>

#include <math.h>

int main()

{

    double e = 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274; // 100 digits
    std::cout << "To how many decimal places?" << std::endl;
    int decimalPlace;
    std::cin >> decimalPlace;

    if (decimalPlace <= 0)
    {
        std::cout << "2";
    }
    else
    {
        std::cout << std::fixed << std::setprecision(decimalPlace) << e;
    }
    return 0;
}