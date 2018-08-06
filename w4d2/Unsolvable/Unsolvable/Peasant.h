#pragma once

#include "Farm.h"

#include <string>
#include <vector>

class Peasant
{
public:
    Peasant();
    Peasant(const std::string& name);
    void Enroll(Farm* farm);
    void Quit(const std::string& farmName);
    std::string GetName() const { return m_name; };
    ~Peasant();

private:
    std::vector<Farm*> m_farms;
    std::string m_name;
};

