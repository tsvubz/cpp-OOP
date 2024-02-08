#include <iostream>
#include <cmath>
#include <numeric>

class Calculator {
    private: 
        double x; 
        double y;

    public:
    Calculator(double x, double y) : x(x), y(y) {};

    // Methods

    // Add
    double add() const {
        return x + y;
    }

    // Subtract
    double subtract() const {
        return x - y;
    }

    // Multiply
    double multiply() const {
        return x * y;
    }

    // Divide 
    double divide() const {
        if (y != 0) {
            return x / static_cast<double>(y);
        } else {
        std::cout << "Cannot divide by zero!" << std::endl;
        return 0;
        }
    }

    // Modulo
    double modulo(int x, int y) const{
        if (y != 0) {
            return x % y;
        }
        return NAN;
    }

    // Factorial
    int factorial(int x) const{
        return std::tgamma(x + 1);
    }

    // Exponential
    double exponential(double x, int y) {
        return std::pow(x, y);
    }

};

int main() {

    Calculator c1(18, 9);

   
    double drum = c1.divide();
    std::cout << drum << std::endl;

    return 0;
}