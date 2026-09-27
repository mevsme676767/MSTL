#pragma once
#include <cstddef>

namespace mstd
{
    template <typename T>
    class allocator
    {
        public:

        allocator() noexcept = default;



        T* allocate(size_t n)
        {
            T* al = static_cast<T*>(::operator new(n * sizeof(T)));           
            return al;
        }


        void construct(T* n, const T& value)
        {
            ::new(n) T(value); 
        }

        void destroy(T* p)
        {
            p->~T();
        }

        void deallocate(T* n, size_t s)
        {
            ::operator delete(n, s * sizeof(T));
        }


    };


}