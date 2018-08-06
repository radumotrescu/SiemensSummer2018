#include "Farm.h"

Farm::Farm()
{
}

Farm::Farm(const std::string & name) :m_name(name)
{
}

void Farm::Hire(Peasant * peasant)
{
    m_peasants.push_back(peasant);
}

void Farm::Fire(const std::string & peasantName)
{
    for (const auto& peasant : m_peasants)
        if (peasant->GetName().compare(peasantName))
        {
            // .....
        }
}

Farm::~Farm()
{
}
