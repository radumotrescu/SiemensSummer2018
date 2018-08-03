#include "TypeTraits.h"
#include <iostream>

namespace Dummy
{
    class C {};
    using P = C*;
    using R = C&;
}

int main()
{   
    std::cout << std::boolalpha;
    std::cout << "Pointer type or not ? \n";
    std::cout << typeid(Dummy::C).name() << ":" 
              << TypeTraits<Dummy::C>::isPointer <<"\n";
    std::cout << typeid(Dummy::P).name() << ":" 
              << TypeTraits<Dummy::P>::isPointer <<"\n";
    std::cout <<  typeid(Dummy::R).name() << ":"
              << TypeTraits<Dummy::R>::isPointer <<"\n";

    system("pause");
	return 0;
}
