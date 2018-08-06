#pragma once

#include <string>
#include <vector>

class Farm;

class Peasant
{
public:
    Peasant();
    Peasant(const std::string& name);
    void Enroll(Farm* farm);
    void Quit(const std::string& farmName);
    std::string GetName() const { return m_name; };
	std::string Work() {
		return "I'm working";
	}
	~Peasant() = default;

private:
    std::vector<Farm*> m_farms;
    std::string m_name;
};

