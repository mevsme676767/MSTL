#pragma once
#include "../include/allocator.hpp"
#include <stdexcept>
#include "../include/misc.hpp"
#include "../include/utility.hpp"
#include <initializer_list>
#include <cstddef>
#include <iostream>





namespace mstd
{
    class string
    {
    private:
        char* buffer;
        size_t v_length;
        size_t v_capacity;
        mstd::allocator<char> alloc;

    public:
        string()
        : buffer(nullptr), alloc(), v_length(0), v_capacity(0)
        {}
        
        string(const char* str)
        : buffer(nullptr), alloc(), v_length(0), v_capacity(0)
        {
            while(str[v_length] != '\0')
            {
                v_length++;
            }
            v_capacity = v_length * 2;

            buffer = alloc.allocate(v_capacity);
            for(int i = 0; i < v_length; i++)
            {
                alloc.construct(buffer + i, mstd::move(str[i]));
            }
            alloc.construct(buffer + v_length, '\0');

        }

        string(const string& str)
        {
            v_length = str.v_length;
            v_capacity = str.v_capacity;

            buffer = alloc.allocate(v_capacity);
            mstd::misc::copy_array(buffer, str.buffer, alloc, v_length);
            alloc.construct(buffer + v_length, '\0');
        }

        string(string&& str)
        {
            v_length = str.v_length;
            v_capacity = str.v_capacity;
            buffer = str.buffer;

            str.buffer = nullptr;
            str.v_length = 0;
            str.v_capacity = 0;
        }

        ~string()
        {
            clear();
            alloc.deallocate(buffer, v_capacity);
        }


        string& operator=(string& str)
        {
            clear();
            alloc.deallocate(buffer, v_capacity);
            
            v_length = str.v_length;
            v_capacity = str.v_capacity;
            buffer = alloc.allocate(v_capacity);

            mstd::misc::copy_array(buffer, str.buffer, alloc, v_length);
            alloc.construct(buffer + v_length, '\0');

            return *this;
        }

        string& operator=(string&& str)
        {
            clear();
            alloc.deallocate(buffer, v_capacity);

            v_length = str.v_length;
            v_capacity = str.v_capacity;
            buffer = str.buffer;

            str.buffer = nullptr;
            str.v_length = 0;
            str.v_capacity = 0;

            return *this;
        }




        char& operator[](size_t pos)
        {
            return buffer[pos];
        }

        const char& operator[](size_t pos) const
        {
            return buffer[pos];
        }

        char& at(size_t pos)
        {
            if(pos >= v_length)
            {
                throw std::out_of_range("Out of range");
            }
            return buffer[pos];
        }

        const char& at(size_t pos) const
        {
            if(pos >= v_length)
            {
                throw std::out_of_range("Out of range");
            }
            return buffer[pos];
        }

        char& front()
        {
            return buffer[0];
        }

        const char& front() const
        {
            return buffer[0];
        }

        char& back()
        {
            return buffer[v_length - 1];
        }

        const char& back() const
        {
            return buffer[v_length - 1];
        }

        char* data()
        {
            return &front();
        }



        bool empty() const
        {
            if(v_length == 0)
            {
                return true;
            }
            return false;
        }

        size_t capacity()
        {
            return v_capacity;
        }

        size_t length()
        {
            return v_length;
        }
        
        size_t size()
        {
            return v_length;
        }

        void clear()
        {
            mstd::misc::clear_array(buffer, alloc, v_length);
            v_length = 0;
            if(buffer != nullptr)
            {
                buffer[0] = '\0';
            }
        }

        char* begin()
        {
            if(empty())
            {
                return end();
            }
            return &buffer[0];
        }

        const char* begin() const
        {
            if(empty())
            {
                return end();
            }
            return &buffer[0];
        }
        
        char* end()
        {
            return &buffer[v_length];
        }

        const char* end() const
        {
            return &buffer[v_length];
        }


        void push_back(char ch)
        {
            bool v = true;
            if(v_length + 1 >= v_capacity)
            {
                size_t oldCap = v_capacity;
                if(v_capacity == 0)
                {
                    v_capacity = 2;
                } else
                {
                    v_capacity *= 2;
                }

                char* newStr = alloc.allocate(v_capacity);
                mstd::misc::copy_array(newStr, buffer, alloc, v_length);
                alloc.construct(newStr + v_length, ch);
                
                
                mstd::misc::clear_array(buffer, alloc, v_length);
                alloc.deallocate(buffer, oldCap);
                             
                
                buffer = newStr;
                

            }

            if(v)
            {
                alloc.construct(buffer + v_length, ch);
            }
            v_length++;
            alloc.construct(buffer + v_length, '\0');
            

            
        }

        void pop_back()
        {
            v_length--;
            alloc.construct(buffer + v_length, '\0');
            
        }

        char* insert(const size_t pos, char ch )
        {

            if(v_length == v_capacity)
            {
                size_t oldCap = v_capacity;
                if(v_capacity == 0)
                {
                    v_capacity = 2;
                } else
                {
                    v_capacity *= 2;
                }

                char* newBuffer = alloc.allocate(v_capacity);
                mstd::misc::copy_array(newBuffer, buffer, alloc, pos);
                alloc.construct(newBuffer + pos, ch);
                for(size_t i = pos; i < v_length; i++)
                {
                    alloc.construct(newBuffer + i + 1, buffer[i]);
                }



                alloc.construct(newBuffer + v_length + 1, '\0');

                mstd::misc::clear_array(buffer, alloc, v_length);
                alloc.deallocate(buffer, oldCap);
                buffer = newBuffer;

            } else {
                {
                    if(v_length == 0)
                    {
                        alloc.construct(buffer, ch);
                        alloc.construct(buffer + 1, '\0');
                    } else {
                        alloc.construct(buffer + v_length, buffer[v_length - 1]);
                        for(size_t i = v_length; i > pos; i--)
                        {
                            buffer[i] = buffer[i - 1];
                        }
                        
                        buffer[pos] = ch;
                    }
                    
                }
            }
            

            v_length++;

            return buffer + pos;
        }

        string erase(size_t pos)
        {
            alloc.destroy(buffer + pos);
            for(size_t i = pos; i < v_length; i++)
            {
                buffer[i] = mstd::move(buffer[i + 1]);
            }

            

            v_length--;
            return *this;
        }


        //todo
        /*
        size_t find(const string& str, size_t pos)
        {
            return 0;
        }
        */
        size_t find(const string& str)
        {
            
            for(size_t i = 0; i <= v_length - str.v_length; i++)
            {
                if(buffer[i] != str.buffer[0])
                {
                    continue;
                }
                bool found = true;



                for(size_t j = 0; j < str.v_length; j++)
                {
                    if(buffer[i + j] != str.buffer[j])
                    {
                        found = false;
                        break;
                    }
                }

                if(found)
                {
                    return i;
                }
            }
            return -1;
        }



        string substr(size_t pos, size_t len)
        {
            string str = "";

            for(size_t i = pos; i < len + pos; i++)
            {
                str.push_back(buffer[i]);
            }

            return str;
        }


        bool starts_with(const char ch) const
        {
            if(buffer[0] == ch)
            {
                return true;
            }
            return false;
        }

        bool ends_with(const char ch) const
        {
            if(buffer[v_length - 1] == ch)
            {
                return true;
            }
            return false;
        }


        bool contains(char ch) const
        {
            for(size_t i = 0; i < v_length; i++)
            {
                if(buffer[i] == ch)
                {
                    return true;
                }
            }            
            return false;
        }

        bool contains(string str) const
        {


            for(size_t i = 0; i <= v_length; i++)
            {
                if(buffer[i] != str.buffer[0])
                {
                    continue;
                }

                bool found = true;
                for(size_t j = 0; j < v_length; j++)
                {
                    if(buffer[i + j] != str.buffer[j])
                    {
                        found = false;
                        break;
                    }
                    
                }
                if(found)
                {
                    return true;
                }
                
            }

            return false;
        }

        string append(size_t count, char ch)
        {



            for(size_t i = 0; i < count; i++)
            {
                push_back(ch);
            }

            return *this;
        }

        string append(std::initializer_list<char> list)
        {
            

            for(auto it = list.begin(); it < list.end(); ++it)
            {
                push_back(*it);
            }

            
            return *this;
        }





        friend std::ostream& operator<<(std::ostream& os, const string& p);
    };

    std::ostream& operator<<(std::ostream& os, const string& p)
    {
    
        os << static_cast<const char*>(p.buffer); 
        return os;
    }
}