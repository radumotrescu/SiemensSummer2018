#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <cstring>

template<typename T>
class SortClass
{
public:
    SortClass() {}
    static void sort(std::vector<T>& m_elements)
    {
        for (int i = 0; i < m_elements.size() - 1; i++)
        {
            for (int j = i + 1; j < m_elements.size(); j++)
            {
                if (m_elements[i] < m_elements[j])
                {
                    std::swap(m_elements[i], m_elements[j]);
                }
            }
        }
    }
};

template <>
class SortClass <std::vector<int>>
{
public:
    SortClass() {}
    static void sort(std::vector<std::vector<int>>& m_elements)
    {
        for (int i = 0; i < m_elements.size() - 1; i++)
        {
            for (int j = i + 1; j < m_elements.size(); j++)
            {
                if (vectorSum(m_elements[i]) < vectorSum(m_elements[j]))
                {
                    std::swap(m_elements[i], m_elements[j]);
                }
            }
        }
    }
private:
    static int vectorSum(const std::vector<int>& vector)
    {
        int sum = 0;
        for (const auto& elem : vector)
            sum += elem;

        return sum;
    }
};

template <>
class SortClass <std::string>
{
public:
    SortClass() {}
    static void sort(std::vector<std::string>& m_elements)
    {
        for (int i = 0; i < m_elements.size() - 1; i++)
        {
            for (int j = i + 1; j < m_elements.size(); j++)
            {
                if (m_elements[i].compare(m_elements[j]))
                {
                    std::swap(m_elements[i], m_elements[j]);
                }
            }
        }
    }
};

int main()
{

    std::vector<std::string> strVector = { "aaaa", "abc","aaa" };
    SortClass<std::string>::sort(strVector);

    for (const auto& elem : strVector)
        std::cout << elem << "\n";
    std::cout << "\n";

    std::vector<std::vector<int>> vecVector = { {1,2},{2,3},{1,1} };
    SortClass<std::vector<int>>::sort(vecVector);

    for (const auto& elem : vecVector)
    {
        for (const auto& elem_v : elem)
            std::cout << elem_v << " ";
        std::cout << "\n";
    }
    std::cout << "\n";

    std::vector<double> doubleVector = { 2.1,0.23,100 };
    SortClass<double>::sort(doubleVector);

    for (const auto& elem : doubleVector)
        std::cout << elem << "\n";

    return 0;
}
