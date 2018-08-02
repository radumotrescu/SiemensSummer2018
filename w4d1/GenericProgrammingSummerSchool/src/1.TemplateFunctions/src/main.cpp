#include <iostream>

#include <Amount.h>
#include <Complex.h>

int add(int x, int y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}

Complex add(const Complex& x, const Complex& y) {
    auto re = x.real + y.real;
    auto im = x.imaginary + y.imaginary;
	return Complex(re, im);
}

Amount add(const Amount& x, const Amount& y) {
    auto dollars = x.dollars + y.dollars + (x.cents + y.cents) / 100;
    auto cents = (x.cents + y.cents ) % 100;
	return Amount(dollars, cents);
}

template<typename T> T add(const T& x, const T& y) {
    return x + y;
}

/************************************************************************************************************************/

int main() {
	int one { 1 };
	int two { 2 };

	std::cout << "1 + 2 = " << add(one, two) << std::endl;

	/************************************************************************************************************************/

	double threePointFive { 3.5 };
	double fourPointSix { 4.6 };

	std::cout << "3.5 + 4.6 = " << add(threePointFive, fourPointSix) << std::endl;

	/************************************************************************************************************************/

	Amount electricityBill(15, 90);
	Amount gasBill(20, 30);

	std::cout << "I have to pay " << add(electricityBill, gasBill)  << " for gas and electricity" << std::endl;

	/************************************************************************************************************************/

	Complex somethingComplex(2.0, 0.0);
	Complex anotherComplexThing(3.0, 24.0);

	std::cout << "The total complexity is " << add(somethingComplex, anotherComplexThing) << std::endl;

    std::cout << "1 + 2 = " << add<int>(one, two) << std::endl;
    std::cout << "3.5 + 4.6 = " << add<double>(threePointFive, fourPointSix) << std::endl;
    std::cout << "I have to pay " << add<Amount>(electricityBill, gasBill) << " for gas and electricity" << std::endl;
    std::cout << "The total complexity is " << add<Complex>(somethingComplex, anotherComplexThing) << std::endl;

	return 0;
}