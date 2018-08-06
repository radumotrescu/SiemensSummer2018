#pragma once

#include <string>
#include <vector>

class Peasant;

class Farm
{
public:
    Farm();
    Farm(const std::string& name);
    void Hire(Peasant* peasant);
    void Fire(const std::string& peasantName);
    std::string GetName() const { return m_name; };
	Peasant* GetPeasant(const std::string& name);
	~Farm() = default;

private:
    std::vector<Peasant*> m_peasants;
    std::string m_name;
};

