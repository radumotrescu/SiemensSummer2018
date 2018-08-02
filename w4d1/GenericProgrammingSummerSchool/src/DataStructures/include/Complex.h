#include <iostream>

struct Complex {
	Complex(const double re, const double im);

    Complex operator+(const Complex& other) const ;
	
	double real;
	double imaginary;
};

std::ostream& operator<<(std::ostream& os, const Complex& complex);