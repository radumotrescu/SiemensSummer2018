#pragma once
#include <ctime>
namespace Ex
{
    // returns the time [seconds] consumed by a function that runs for numRuns times
    template < size_t numRuns, typename Func, typename... Args>
    double MeasureTime(Func f, Args... args)
    {        
        clock_t begin = clock();

        for (size_t i = 0; i < numRuns; ++i)
            f(args...);

        clock_t end = clock();

        return double(end - begin) / CLOCKS_PER_SEC;
    }
}