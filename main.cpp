#include <iostream>
#include <numeric>

class Fraction {
    int numerator = 1;
    int denominator = 1;
public:

    Fraction(int num = 1, int den = 1){
        if (den == 0) {
            std::cerr << "Denominator can't be zeroes\n";
            den = 1;
        }
        numerator = num;
        denominator = den;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    void SetNumerator(int num) {
        numerator = num;
    }
    int GetNumerator() const { return numerator; }
    void SetDenominator(int den) {
        if (den == 0) {
            std::cerr << "Denominator cannot be 0 (set to 0)\n";
            denominator  = 1;
            return;
        }

        if (den < 0) {
            denominator = -den;
            numerator = -numerator;
        }
        else denominator = den;
    }
    int GetDenominator() const { return denominator; }

    void PrintFraction() const { std::cout << std::endl << numerator << "/" << denominator << std::endl; }

    void RoundFraction() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        int deviser = std::gcd(abs(numerator), abs(denominator));
        numerator /= deviser;
        denominator /= deviser;
    }

    void AddFraction (const Fraction& fraction) const{
        Fraction result;
        result.SetDenominator(std::lcm(this->denominator, fraction.GetDenominator()));
        result.SetNumerator(this->numerator * (result.GetDenominator() / this->denominator) +
            fraction.GetNumerator() * (result.GetDenominator() / fraction.GetDenominator()));
        result.RoundFraction();
        std::cout << this->numerator << "/" <<  this->denominator << " + " << fraction.GetNumerator() << "/" << fraction.GetDenominator()
        << " = " << result.GetNumerator() << "/" << result.GetDenominator() << std::endl ;
    }
    void MinusFraction(const Fraction& fraction) const {
        Fraction result;
        result.SetDenominator(std::lcm(this->denominator, fraction.GetDenominator()));
        result.SetNumerator(this->numerator * (result.GetDenominator() / this->denominator) -
                    fraction.GetNumerator() * (result.GetDenominator() / fraction.GetDenominator()));
        result.RoundFraction();
        std::cout << this->numerator << "/" <<  this->denominator << " - " << fraction.GetNumerator() << "/" << fraction.GetDenominator()
        << " = " << result.GetNumerator() << "/" << result.GetDenominator() << std::endl ;
    }
    void MultiplyFraction(const Fraction& fraction) const {
        Fraction result;
        result.SetNumerator(this->numerator * fraction.GetNumerator());
        result.SetDenominator(this->denominator * fraction.GetDenominator());
        result.RoundFraction();
        std::cout << this->numerator << "/" << this->denominator << " * " << fraction.GetNumerator() << "/" << fraction.GetDenominator()
       << " = " << result.GetNumerator() << "/" << result.GetDenominator() << std::endl ;
    }
    void DivideFraction(const Fraction& fraction) const {
        Fraction result;
        if (fraction.GetNumerator() == 0) {
            std::cerr << "Can't complete division by zere\n";
            return;
        }
        result.SetNumerator(this->numerator * fraction.GetDenominator());
        result.SetDenominator(this->denominator * fraction.GetNumerator());
        result.RoundFraction();
        std::cout << this->numerator << "/" << this->denominator << " / " << fraction.GetNumerator() << "/" << fraction.GetDenominator()
       << " = " << result.GetNumerator() << "/" << result.GetDenominator() << std::endl ;
    }

};
int main() {
    Fraction a(2, 3);
    Fraction b(4, 5);

    std::cout << "Initial fractions:\n";
    a.PrintFraction();
    b.PrintFraction();

    std::cout << "\nAddition:\n";
    a.AddFraction(b);

    std::cout << "\nSubtraction:\n";
    a.MinusFraction(b);

    std::cout << "\nMultiplication:\n";
    a.MultiplyFraction(b);

    std::cout << "\nDivision:\n";
    a.DivideFraction(b);

    std::cout << "\nSet/Get and Reduction:\n";
    Fraction c;
    c.SetNumerator(20);
    c.SetDenominator(30);
    std::cout << "Before reduction: ";
    c.PrintFraction();

    c.RoundFraction();
    std::cout << "After reduction: ";
    c.PrintFraction();

    return 0;
}


