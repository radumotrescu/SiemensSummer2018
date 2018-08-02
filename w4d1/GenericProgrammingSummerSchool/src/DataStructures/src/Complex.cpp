#include <Complex.h>

Complex::Complex(const double re, const double im)
	: real(re), imaginary(im) { }

auto operator<<(std::ostream& os, const Complex& complex) -> std::ostream& {
	os << complex.real << " + " << complex.imaginary << "i";
	return os;
}

auto Complex::operator+(const Complex& other) const -> Complex {
    auto x = *this;
    auto y = other;
    auto re = x.real + y.real;
    auto im = x.imaginary + y.imaginary;
    return Complex(re, im);
}