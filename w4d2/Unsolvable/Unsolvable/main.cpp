#include <iostream>

#include "Peasant.h"
#include "Farm.h"

int main()
{
    Farm *f1 = new Farm("f1");
    {
        Peasant *p1 = new Peasant("p1");
        Peasant *p2 = new Peasant("p2");

        f1->Hire(p1);
    }
    f1->Fire("p1");

}