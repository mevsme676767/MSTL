#pragma once
#include <utility>
#include "../include/allocator.hpp"

//made to avoid copypasting

namespace mstd::misc
{
    template <typename T>
    void copy_array(T* data, T* src, mstd::allocator<T> al, size_t range)
    {
        for(size_t i = 0; i < range; i++)
        {
            al.construct(data + i, src[i]);
        }
    }

    template <typename T>
    void move_array(T* data, T* src, mstd::allocator<T> al, size_t range)
    {
        for (size_t i = 0; i < range; i++)
        {
            al.construct(data + i, std::move(src[i]));
        }
    }

    template <typename T>
    void clear_array(T* data, mstd::allocator<T> al, size_t range)
    {
        for(size_t i = 0; i < range; i++)
        {
            al.destroy(data + i);
        }
    }
}