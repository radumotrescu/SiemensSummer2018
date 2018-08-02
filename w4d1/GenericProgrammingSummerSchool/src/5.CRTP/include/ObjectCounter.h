#pragma once

template <typename CountedType>
class ObjectCounter
{
    private:   
        static size_t count;
    
    protected:    
        ObjectCounter() { ++count;}
        
        ObjectCounter(const ObjectCounter<CountedType> &) { ++count;}
        
        ~ObjectCounter() { --count;}
        
    public:
        static size_t GetCount() { return count;}
};

template<typename CountedType>
size_t ObjectCounter<CountedType>::count = 0;