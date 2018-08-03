#pragma once

class NullType {}; // a null marker for types

template <typename T>
class TypeTraits
{
private:
    template <class U> struct PointerTraits
    {
        enum { result = false };
        using PointeeType = NullType;
    };
    template <class U> struct PointerTraits<U*>
    {
        enum { result = true };
        typedef U PointeeType;
    };
public:
    enum { isPointer = PointerTraits<T>::result };
    using PointeeType = typename PointerTraits<T>::PointeeType ;
};