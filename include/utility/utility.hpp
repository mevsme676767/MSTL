#pragma once

#include <type_traits> 

namespace mstd
{



    template <typename T>
    void swap(T& a, T& b)
    {
        T temp = move(a);
        a = move(b);
        b = move(temp);
    }

    template <typename T, typename U>
    T exchange(T& obj, U&& value)
    {
        T old = obj;
        obj = value;
        return old;
    }

    template <typename T>
    T&& forward(std::remove_reference<T>& t) noexcept
    {
        return static_cast<T&&>(t);
    }

    template <typename T>
    T&& forward(std::remove_reference<T>&& t) noexcept
    {
        return static_cast<T&&>(t);
    }


    template <typename T>
    std::remove_reference_t<T>&& move(T&& obj)
    {
        return static_cast<std::remove_reference_t<T>&&>(obj);
    };
    

}