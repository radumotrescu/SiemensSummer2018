#include <Amount.h>

#include <iomanip>

Amount::Amount(const int dollars, const int cents)
	: dollars(dollars), cents(cents) { }

std::ostream& operator<<(std::ostream& os, const Amount& amount) {
	os << "$" << amount.dollars << "." << std::setw(2) << std::setfill('0') << amount.cents;
	return os;
}

Amount Amount::operator+(const Amount& other) const {
    Amount result(0, 0);
    result.dollars = other.dollars + this->dollars + (other.cents + this->cents) / 100;
    result.cents = (other.cents + this->cents) % 100;

    return result;
}