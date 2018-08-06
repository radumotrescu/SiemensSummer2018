#pragma once

#include "Peasant.h"

#include <string>
#include <vector>

class Farm
{
public:
    Farm();
    Farm(const std::string& name);
    void Hire(Peasant* peasant);
    void Fire(const std::string& peasantName);
    std::string GetName() const { return m_name; };
    ~Farm();

private:
    std::vector<Peasant*> m_peasants;
    std::string m_name;
};

