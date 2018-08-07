#pragma once
#include <iostream>

template<typename T>
class SmartPointer
{
public:
    SmartPointer(T* data) :m_data(data),m_referenceCounter( new int )
    {
        *m_referenceCounter = 0;
        (*m_referenceCounter)++;
        std::cout << "Created smart_ptr! Reference counter is " << *m_referenceCounter << std::endl;
    }

    SmartPointer(const SmartPointer<T>& other):m_data(other.m_data),m_referenceCounter(other.m_referenceCounter)
    {
        (*m_referenceCounter)++;
        std::cout << "Copied smart_ptr! Reference counter is " << *m_referenceCounter << std::endl;
    }

    SmartPointer<T>& operator= (const SmartPointer<T>& other)
    {
        if (this != &other)
        {
            if (m_referenceCounter && *m_referenceCounter-- == 0)
            {
                delete m_referenceCounter;
                delete m_data;
            }
            m_data = other.m_data;
            m_referenceCounter = other.m_referenceCounter;
            *m_referenceCounter++;
        }
        std::cout << "Assigning smart_ptr! Reference counter is " << *m_referenceCounter++ << std::endl;
    }

    T& operator* ()
    {
        return *m_data;
    }

    T* operator-> ()
    {
        return m_data;
    }

    ~SmartPointer()
    {
        if (m_referenceCounter != nullptr)
        {
            (*m_referenceCounter)--;
            std::cout << "Destroyed smart_ptr! Reference counter is " << *m_referenceCounter << std::endl;

            if (*m_referenceCounter <= 0)
            {
                delete m_data;
                delete m_referenceCounter;

                m_referenceCounter = nullptr;
                m_data = nullptr;
            }
        }
    }


private:
    T* m_data{ nullptr };
    int* m_referenceCounter{ nullptr; };
};

