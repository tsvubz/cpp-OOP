#include <iostream>

// Add two numbers
double sum(double a, double b) {
    return a + b;
}   

//Subtract two numbers
double sub(double a, double b) {
    if (a > b) {
        return a - b;
    }
    else {
        return b - a;
    }
}

// Multiply two numbers
double mul(double a, double b) {
    return a * b;
}

// Divide Two numbers
double divide(double a, double b) {
    if (b != 0) {
        return a / static_cast<double>(b);
    }
    else {
        std::cout << "Cannot divide by zero!" << std::endl;
        return 0;
    }
}


int main() {

    double a, b;

    std::cout << "Enter the first number: ";
    std::cin >> a;
    std::cout << "Enter the second number: ";
    std::cin >> b;

    std::cout << "Choose math operation: " << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;

    int option;
    std::cin >> option;
    
    switch(option) {
        case 1:
            std::cout << "The sum of " << a << " and " << b << " is " << sum(a, b) << std::endl;
            break;
        case 2:
            std::cout << "The difference of " << a << " and " << b << " is " << sub(a, b) << std::endl;
            break;
        case 3:
            std::cout << "The product of " << a << " and " << b << " is " << mul(a, b) << std::endl;
            break;
        case 4:
            std::cout << "The quotient of " << a << " and " << b << " is " << divide(a, b) << std::endl;
            break;
        default:
            std::cout << "Invalid option!" << std::endl;
    }

    return 0;
}