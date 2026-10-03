#pragma once

#include "../include/misc.hpp"
#include <stdexcept>
#include <utility>
#include <cstddef>
#include <initializer_list>
#include "../include/utility.hpp"




namespace mstd
{
    template <typename T>
    class vector
    {
    private:
        mstd::allocator<T> alloc;
        T* v_data;
        size_t v_size;
        size_t v_capacity;

    public:
        vector()
        : v_data(nullptr), alloc(), v_size(0), v_capacity(0)
        {}

        ~vector()
        {
            clear();
            alloc.deallocate(v_data, v_capacity);
        }

        vector(std::initializer_list<T> list)
        : v_data(nullptr), alloc(), v_size(0), v_capacity(list.size() * 2)
        {
            v_data = alloc.allocate(v_capacity);
            for(auto it = list.begin(); it != list.end(); ++it, ++v_size)
            {
                alloc.construct(v_data + v_size, *it);
            }
            
            

        }

        vector(const vector& other)
        {
            
            v_size = other.v_size;
            v_capacity = other.v_capacity;

            v_data = alloc.allocate(v_capacity);
            mstd::misc::copy_array(v_data, other.v_data, alloc, v_size);

        }

        vector(vector&& other)
        {
            v_size = other.v_size;
            v_capacity = other.v_capacity;
            v_data = other.v_data;

            other.v_data = nullptr;
            other.v_size = 0;
            other.v_capacity = 0;
        }

        vector& operator=(const vector& other)
        {
            if(this == &other)
            {
                return *this;
            }
            clear();
            alloc.deallocate(v_data, v_capacity);
           
            v_size = other.v_size;
            v_capacity = other.v_capacity;

            v_data = alloc.allocate(v_capacity);
            mstd::misc::copy_array(v_data, other.v_data, alloc, v_size);

            return *this;
        
        }

        vector& operator=(vector && other)
        {
            if(this == &other)
            {
                return *this;
            }
            clear();
            alloc.deallocate(v_data, v_capacity);
            v_size = other.v_size;
            v_capacity = other.v_capacity;
            v_data = other.v_data;
            

            other.v_data = nullptr;
            other.v_size = 0;
            other.v_capacity = 0;

            return *this;
        }


        T& operator[](const size_t pos)
        {
            return v_data[pos];
        }

        const T& operator[](const size_t pos) const
        {
            return v_data[pos];
        }


        T* begin()
        {
            return v_data;
        }


        const T* begin() const
        {
            return v_data;
        }

        T* end()
        {
            return v_data + v_size;
        }

        const T* end() const
        {
            v_data + v_size;
        }



        
        void push_back(const T& value)
        {
            bool v = true;
            if(v_size == v_capacity)
            {
                size_t oldCap = v_capacity;
                if(v_capacity == 0)
                {
                    v_capacity = 1;
                } else
                {
                    v_capacity *= 2;
                }
                T* newData = alloc.allocate(v_capacity);

                mstd::misc::copy_array(newData, v_data, alloc, v_size);
                alloc.construct(newData + v_size, value);
                v = false;

                mstd::misc::clear_array(v_data, alloc, v_size);

                alloc.deallocate(v_data, oldCap);
                

                v_data = newData;

            }
            if(v)
            {
                alloc.construct(v_data + v_size, value);
            }
            
            v_size++;
        };

        void pop_back()
        {
            v_size--;
            alloc.destroy(v_data + v_size);
            
        }

        
        T* insert(const T* pos, const T& value)
        {

            size_t index = pos - v_data;
            if(index > v_size)
            {
                return nullptr;
            }

            if(v_capacity == v_size)
            {
                size_t oldCapacity = v_capacity;
                if(v_capacity == 0)
                {
                    v_capacity = 1;
                } else {
                    v_capacity *= 2;
                }

                T* newData = alloc.allocate(v_capacity);
                mstd::misc::move_array(newData, v_data, alloc, index);
                alloc.construct(newData + index, value);
                for(size_t i = index; i < v_size; i++)
                {
                    alloc.construct(newData + i + 1, mstd::move(v_data[i]));
                }

                mstd::misc::clear_array(v_data, alloc, v_size);
                alloc.deallocate(v_data, oldCapacity);

                v_data = newData;
                
            } else {
                if(v_size == 0)
                {
                    alloc.construct(v_data, value);
                } else {
                    alloc.construct(v_data + v_size, mstd::move(v_data[v_size - 1]));
                    for(size_t i = v_size - 1; i > index; i--)
                    {   
                        v_data[i] = mstd::move(v_data[i - 1]);
                    }
                    v_data[index] = value;
                }
            }

            v_size++;
            return v_data + index;

            
        }

        void erase(const size_t pos)
        {
            alloc.destroy(v_data + pos);
            for(size_t i = pos; i < v_size - 1; i++)
            {
                v_data[i] = std::move(v_data[i + 1]);
            }


            v_size--;
        }




        T& at(const size_t pos)
        {
            if(pos >= v_size)
            {
                throw std::out_of_range("Index is out of valid range");
            }

            return v_data[pos];
        }

        const T& at(const size_t pos) const
        {
            if(pos >= v_size)
            {
                throw std::out_of_range("Index is out of valid range");
            }

            return v_data[pos];
        }

        T& front() 
        {
            return v_data[0];
        }

        const T& front() const
        {
            return v_data[0];
        }


        T& back()
        {
            return v_data[v_size - 1];
        }
        
        const T& back() const
        {
            return v_data[v_size - 1];
        }

        T* data()
        {
            return &front();
        }

        const T* data() const
        {
            return &front();
        }



        bool empty() const
        {
            if (v_size == 0)
            {
                return true;
            }
            return false;
        }

        size_t size() const
        {
            return v_size;
        }

        size_t capacity() const
        {
            return v_capacity;
        }

        void clear()
        {
            mstd::misc::clear_array(v_data, alloc, v_size);

            v_size = 0;
        }

    };
}