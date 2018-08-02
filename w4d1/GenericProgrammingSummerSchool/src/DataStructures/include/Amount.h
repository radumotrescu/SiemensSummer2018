#include <iostream>

struct Amount {
	Amount(const int dollars, const int cents);

    Amount operator+(const Amount& other) const;
	
	int dollars;
	int cents;
};

std::ostream& operator<<(std::ostream& os, const Amount& amount);