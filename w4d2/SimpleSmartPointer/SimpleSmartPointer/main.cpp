#include "SmartPointer.h"

class Foo
{
public:
    Foo(int start):x(start){}
    int get() { return x; }
    void add() { x++; }

private:
    int x = 0;
};

int main()
{
    SmartPointer<Foo> a(new Foo(2));
    a->add();
    std::cout << "a" <<  a->get() << std::endl;
    
    SmartPointer<Foo> b(a);
    a->add();
    std::cout << "b" << b->get() << std::endl;

    return 0;
}