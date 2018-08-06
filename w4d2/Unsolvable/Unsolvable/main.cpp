#include <iostream>

#include "Peasant.h"
#include "Farm.h"

int main()
{
    Farm *f1 = new Farm("f1");

	// peasant hiring function
    {
        Peasant *p1 = new Peasant("p1");
        Peasant *p2 = new Peasant("p2");

        f1->Hire(p1);
        f1->Hire(p2);

		p1->Enroll(f1);

		delete p1;
		//p1->Enroll(f1);
		p1->GetName();
    }

	// some preprocessing
	{
		f1->Fire("p1");
		f1->Hire(new Peasant("p3"));
	}

	// more preprocessing
	{
		Farm *f2 = new Farm("f2");

		Peasant *p4 = new Peasant("p4");

		f2->Hire(p4);

		// function written by bad programmer
		{
			f2->Fire("p4");

			delete f2; //
		}

		p4->GetName();

		f2->Hire(new Peasant("p5"));
	}



	return 0;
}