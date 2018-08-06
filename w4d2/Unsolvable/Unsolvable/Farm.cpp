#include "Farm.h"
#include "Peasant.h"

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
	for (int i = 0; i < m_peasants.size(); i++)
		if (!m_peasants[i]->GetName().compare(peasantName))
		{
			// .....

			m_peasants.erase(m_peasants.begin() + i);
		}
}



Peasant* Farm::GetPeasant(const std::string& name)
{
	for (auto& peasant : m_peasants)
		if (!peasant->GetName().compare(name))
			return peasant;
}