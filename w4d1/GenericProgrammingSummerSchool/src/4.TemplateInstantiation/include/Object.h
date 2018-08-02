#pragma once
class Object
{
public:
    template<typename T>
    void foo(const T& t);
    Object();
    ~Object();
};