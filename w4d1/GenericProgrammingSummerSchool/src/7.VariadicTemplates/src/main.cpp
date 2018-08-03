#include "MeasureTime.h"
#include <iostream>
#include <cstdio>
namespace
{
    void Hello1()
    {
        printf("Hello\n");
    }

    void Hello2()
    {
        std::cout << "Hello\n";
    }

    const size_t numRuns = 10000;
}

int main()
{
    double timeHello1 = Ex::MeasureTime<numRuns>(Hello1);
    double timeHello2 = Ex::MeasureTime<numRuns>(Hello2);

    std::cout << "Times run:" << numRuns << " .\n";
    std::cout << "Hello1: " << timeHello1 << " . Hello2: " << timeHello2 << " .\n";

    system("pause");
	return 0;
}