#pragma once
#include <cstddef>
#include <stdexcept>

namespace mstd
{
    template <typename T, size_t S>
    class array
    {




    public:
        T data_[S];
    
        T& at(size_t pos)
        {
            if(pos >= S)
            {
                throw std::out_of_range("Index is out of valid range");
            }
            return data_[pos];
        }

        const T& at(size_t pos) const
        {
            if(pos >= S)
            {
                throw std::out_of_range("Index is out of valid range");
            }
            return data_[pos];
        } 

        T& operator[](size_t pos)
        {
            return data_[pos];
        }

        const T& operator[](size_t pos) const
        {
            return data_[pos];
        }

        T& front()
        {
            return data_[0];
        }

        const T& front() const
        {
            return data_[0];
        }

        T& back() 
        {
            return data_[S - 1];
        }


        const T& back() const
        {
            return data_[S - 1];
        }

        T* data()
        {
            return &front();
        }

        const T* data() const
        {
            return &front();
        }

        T* begin()
        {
            return &data_[0];
        }

        const T* begin() const
        {
            return &data_[0];
        }

        T* end()
        {
            return &data_[S];
        }


        const T* end() const
        {
            return &data_[S];
        }

        size_t size()
        {
            return S;
        }



        bool empty() const
        {
            if(S == 0)
            {
                return true;
            }
            return false;
        }




    };
}