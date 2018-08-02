#include <iostream>
#include <sstream>
#include <map>

class Force {
public:
	enum class Units {
		N,
		mN,
		lbf,
		// etc..
	};

	static auto ToString(Units unit) -> std::string& {
		static std::map<Units, std::string> representations = {
			{Units::N, "N"},
			{Units::mN, "mN"},
			{Units::lbf, "lbf"}
		};

		return representations[unit];
	}
};

class Mass {
public:
	enum class Units {
		kg,
		g,
		lb,
		// etc..
	};

	static auto ToString(Units unit) -> std::string& {
		static std::map<Units, std::string> representations = {
			{ Units::kg, "kg" },
			{ Units::g, "g" },
			{ Units::lb, "lb" }
		};

		return representations[unit];
	}
};

class Velocity {
public:
	enum class Units {
		m_s,
		km_h,
		// etc..
	};

	static auto ToString(Units unit) -> std::string& {
		static std::map<Units, std::string> representations = {
			{ Units::m_s, "m/s" },
			{ Units::km_h, "km/h" }
		};

		return representations[unit];
	}
};

class Dimensionless {

};


template<typename T> class Parameter {
public:
    Parameter(double value, typename T::Units unit) : m_value(value), m_unit(unit) { }
    ~Parameter() { }

    auto SetValue(const double value) -> Parameter& {
        m_value = value;
        return *this;
    }

    auto SetUnit(const typename T::Units unit) -> Parameter& {
        m_unit = unit;
        return *this;
    }

    auto Set(const double value, const typename T::Units unit) -> Parameter& {
        m_value = value;
        m_unit = unit;
        return *this;
    }

    auto ToString() const -> std::string {
        std::stringstream str;
        str << m_value << " " << T::ToString(m_unit);

        return str.str();
    }

private:
    double m_value;
    typename T::Units m_unit;
};

template<> class Parameter<Dimensionless> {
public:
    Parameter(const double value) : m_value(value) { }
    ~Parameter() { }

    auto SetValue(const double value) -> Parameter& {
        m_value = value;
        return *this;
    }

    auto ToString() -> std::string {
        std::stringstream str;
        str << m_value;

        return str.str();
    }
private:
    double m_value;
};

auto main() -> int {
	// Uncomment the part below when implementation is done

	Parameter<Force> force(3.5, Force::Units::mN);
	Parameter<Mass> mass(70, Mass::Units::kg);
	Parameter<Dimensionless> scale(2.0);

	std::cout << "Force: " << force.ToString() << std::endl;
	std::cout << "Mass: " << mass.ToString() << std::endl;
	std::cout << "Scale: " << scale.ToString() << std::endl;

	return 0;
}
