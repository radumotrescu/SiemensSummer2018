#include <Amount.h>

#include <iomanip>

Amount::Amount(const int dollars, const int cents)
	: dollars(dollars), cents(cents) { }

auto operator<<(std::ostream& os, const Amount& amount) -> std::ostream& {
	os << "$" << amount.dollars << "." << std::setw(2) << std::setfill('0') << amount.cents;
	return os;
}

auto Amount::operator+(const Amount& other) const -> Amount {
    Amount result(0, 0);
    result.dollars = other.dollars + this->dollars + (other.cents + this->cents) / 100;
    result.cents = (other.cents + this->cents) % 100;

    return result;
}