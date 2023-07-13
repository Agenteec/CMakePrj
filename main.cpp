#include <iostream>
#include "math.h"

int main() {
    int a = 5;
    int b = 3;

    int sum = add(a, b);
    int difference = subtract(a, b);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;

    return 0;
}