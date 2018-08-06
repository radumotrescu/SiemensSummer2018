#include "Peasant.h"



Peasant::Peasant()
{
}

Peasant::Peasant(const std::string & name) :m_name(name)
{
}

void Peasant::Enroll(Farm * farm)
{
    m_farms.push_back(farm);
}

void Peasant::Quit(const std::string & farmName)
{
    for (const auto& farm : m_farms)
        if (farm->GetName().compare(farmName))
        {
            // .....
        }
}


Peasant::~Peasant()
{
}
