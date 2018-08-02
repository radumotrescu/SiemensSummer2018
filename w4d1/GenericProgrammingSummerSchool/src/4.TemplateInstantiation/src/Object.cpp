#include "Object.h"
#include <string>
#include <iostream>

template<typename T>
void Object::foo(const T& t)
{
    std::cout << t << '\n';
}

template void Object::foo<int>(const int&);
template void Object::foo<std::string>(const std::string&);

Object::Object()
{
}


Object::~Object()
{
}
