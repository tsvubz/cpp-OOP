#include <iostream> // cin, cout, endl
#include <vector> // vector
#include <cmath> // sqrt, pow
#include <algorithm> // sort, min, max, reverse
#include <numeric> // accumulate
#include <limits> // numeric_limits
#include <string> // string, stoi, to_string

class Fraction {
friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    // Print the whole number if it exists.
    if (f.whole != 0 && f.whole > 0) {
        out << f.whole << " " << f.numerator << '/' << f.denominator;
    } else {
        // Print the fraction as "numerator/denominator" if the whole number is 0.
        out << f.numerator << '/' << f.denominator;
    }
    // Return the output stream.
    return out;
}

private:
    int whole;
    int numerator;
    int denominator;
    
public:
    //Constructors
    Fraction(int n, int d) : numerator(n), denominator(d) {}
    Fraction(int w, int n, int d) : whole(w), numerator(n), denominator(d) {}
    Fraction(int val) : Fraction(val, 1) {}
    


    //Methods
    //Add Fractions
    Fraction operator+(const Fraction& other) const {
        return {(numerator * other.denominator) + (other.numerator * denominator), denominator * other.denominator};
    }
    Fraction operator+(int val) const {
        return {numerator + (val * denominator), denominator};
    }
    //Multiply Fractions
    Fraction operator*(const Fraction& other) const{
        return {numerator * other.numerator, denominator * other.denominator};
    }

    //Convert to Decimal
    double toDecimal() const {
        return numerator / static_cast<double>(denominator);
    }

    //Convert to Percent
    double toPercent() const {
        return toDecimal() * 100;
    }

    //Simplifying Fractions
    Fraction simplify() const {
        int gcd = std::__gcd(numerator, denominator);
        return {numerator / gcd, denominator / gcd};
    }

    //convert improper fraction to mixed fraction
    Fraction toMixed() const {
        int newWhole = numerator / denominator;
        int newNumerator = numerator % denominator;

        return {newWhole, newNumerator, denominator};
    }

    // Convert mixed fraction to improper fraction
    Fraction toImproper() const {
        int newNumerator = whole * denominator + numerator;
        return {newNumerator, denominator};
    }
};

int main() {
    Fraction f1(3, 4);
    Fraction f2(2, 3);
    Fraction f3(1, 2);
    Fraction f4(16, 24);
    Fraction f5(15, 4);
    Fraction f6(3, 1, 4);

    std::cout << f1 * 5 << std::endl;
    std::cout <<  f1 + f2 << std::endl;

    double x = f2.toDecimal();
    std::cout << x << std::endl;

    double y = f1.toPercent();
    std::cout << y << "%" << std::endl;

    std::cout << f4.simplify() << std::endl;

    Fraction mixed = f5.toMixed();
    std::cout << mixed << std::endl;

    Fraction improper = f6.toImproper();
    std::cout << improper << std::endl;

    return 0;
}