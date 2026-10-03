#include <cstddef>
namespace mstd
{
    template <typename T>
    const T& max(const T& a, const T& b)
    {
        if(a < b)
        {
            return b;
        } else
        {
            return a;
        }

    }

    template <typename T>
    const T& min(const T& a, const T& b)
    {
        if(b < a)
        {
            return b;
        } else
        {
            return a;
        }

    }

    template <typename T, typename P>
    bool all_of(T first, T last, P pred)
    {
        for(; first != last; ++first)
        {
            if(!pred(*first))
            {
                return false;
            }
        }

        return true;
    }


    template <typename T, typename P>
    bool any_of(T first, T last, P pred)
    {
        for(; first != last; ++first)
        {
            if(pred(*first))
            {
                return true;
            }
        }

        return false;
    }



    template <typename T, typename P>
    bool none_of(T first, T last, P pred)
    {
        for(; first != last; ++first)
        {
            if(pred(*first))
            {
                return false;
            }
        }

        return true;
    }

    template <typename T, typename P>
    T find(T first, T last, const P& value)
    {
        for(; first != last; ++first)
        {
            if(*first == value)
            {
                return first;
            }
        }
        return last;
    }

    template <typename T, typename P>
    T find_if(T first, T last, P pred)
    {
        for(; first != last; ++first)
        {
            if(pred(*first))
            {
                return first;
            }
        }
        return last;
    }



    template <typename T, typename P>
    T find_if_not(T first, T last, P pred)
    {
        for(; first != last; ++first)
        {
            if(!pred(*first))
            {
                return first;
            }
        }
        return last;
    }

    template <typename T, typename U>
    size_t count(T first, T last, const U& value)
    {
        size_t count = 0;
        for(; first != last; ++first)
        {
            if(*first == value)
            {
                count++;
            }
        }
        return count;
    }

    
    template <typename T, typename U>
    void fill(T first, T last, const U& value)
    {
        for(; first != last; ++first)
        {
            *first = value;
        }
    }


    template <typename T, typename U>
    U copy(T first, T last, U cop)
    {
        for(; first != last; ++first, ++cop)
        {
            *cop = *first;
        }
        return cop;
    }



}