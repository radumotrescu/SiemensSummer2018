#include "ObjectCounter.h"
#include <iostream>

namespace
{
    class Baluba : public ObjectCounter<Baluba>{};
    class XXX : public ObjectCounter<XXX> {};
    class D : public XXX, public ObjectCounter<D> {};
}

int main()
{
    Baluba b[10];
    XXX x[12];
    D d[13];

    std::cout << "Number of objects Baluba: " << Baluba::GetCount() << std::endl;
    std::cout << "Number of objects XXX: " << XXX::GetCount() << std::endl;
    //std::cout << "Number of objects D: " << D::GetCount() << std::endl; 

    system("pause");
    return 0;
}