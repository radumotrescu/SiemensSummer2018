#include "Object.h"
#include <string>

int main()
{
    Object obj;
    obj.foo<int>(3);
    obj.foo<std::string>("aids");
    //obj.foo<double>(3.2);
    return 0;
}