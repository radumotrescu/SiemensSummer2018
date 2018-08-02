#include <Complex.h>

Complex::Complex(const double re, const double im)
	: real(re), imaginary(im) { }

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
	os << complex.real << " + " << complex.imaginary << "i";
	return os;
}

Complex Complex::operator+(const Complex& other) const {
    auto x = *this;
    auto y = other;
    auto re = x.real + y.real;
    auto im = x.imaginary + y.imaginary;
    return Complex(re, im);
}