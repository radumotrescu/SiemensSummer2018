#include <iostream>
#include <list>

#include <Amount.h>
#include <Complex.h>

template<typename T>
class Vector
{
public:
    Vector(uint16_t defaultVectorSize = 10) :m_size(0), m_array(new T[defaultVectorSize]), m_capacity(defaultVectorSize) {}
    void push_back(T elem)
    {
        if (m_size == m_capacity)
            resize(2 * m_size);
        m_array[m_size] = elem;
        ++m_size;
    }

    T& operator[](const uint16_t index)
    {
        if (index < 0)
            std::cout << "bad programmer";
        else if (index >= m_size)
            std::cout << "oops, better luck next time";
        return m_array[index];
    }

    void print()
    {
        for (uint16_t i = 0; i < m_size; i++)
            std::cout << m_array[i] << " ";
    }

    void clear()
    {
        m_size = 0;
    }

    void pop_back()
    {
        --m_size;
    }

    T& at(const uint16_t index)
    {
        return m_array[index];
    }

private:
    void resize(const uint16_t size_)
    {
        if (size_ > m_capacity)
        {
            T* temp = new T[size_];
            memcpy(temp, m_array, m_size * sizeof(T));
            std::swap(temp, m_array);
            delete[] temp;
            m_capacity = size_;
        }
    }
    T* m_array;
    uint16_t m_size;
    uint16_t m_capacity;
};


int main()
{

    Vector<int> vec(2);
    vec.push_back(1);
    vec.clear();
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);
    std::cout << vec.at(0);
    std::cout << " ";
    std::cout << vec.at(1);
    std::cout << " ";
    std::cout << vec.at(2);
    std::cout << " ";
    std::cout << vec[3];
    std::cout << " ";

    Vector<double> vec1(3);
    vec1.push_back(3.2);
    vec1.push_back(3.2);
    vec1.push_back(3.2);
    vec1.print();

    return 0;
}