#include <iostream>

struct Complex {
	Complex(const double re, const double im);

    auto operator+(const Complex& other) const -> Complex;
	
	double real;
	double imaginary;
};

auto operator<<(std::ostream& os, const Complex& complex)->std::ostream&;