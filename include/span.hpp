#include <cstddef>
#include <stdexcept>

namespace mstd
{
    template<typename T>
    class span
    {
        private:
            T* data_;
            size_t size_;

        public:
            span()
            : data_(nullptr), size_(0)
            {}
            
            template <typename It>
            span(It first, It last)
            : data_(first), size_(last - first)
            {}

            span(T* data, size_t size)
            : data_(data), size_(size)
            {}

            template<typename Container>
            span(Container& container)
            : data_(container.data()), size_(container.size())
            {}

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
                return &data_[size_];
            }

            const T* end() const
            {
                return &data_[size_];
            }

            size_t size() const
            {
                return size_;
            }

            bool empty() const
            {
                if(size_ == 0)
                {
                    return true;
                }
                return false;
            }

            T& front()
            {
                return data_[0]; 
            }

            const T& front() const
            {
                return data_[0]; 
            }

            const T& back() const
            {
                return data_[size_ - 1];
            }

            T& back()
            {
                return data_[size_ - 1];
            }

            T& operator[](size_t pos)
            {
                return data_[pos];
            }


            const T& operator[](size_t pos) const
            {
                return data_[pos];
            }

            T& at(size_t pos)
            {
                if(pos >= size_)
                {
                    throw std::out_of_range("Out of range");
                }
                return data_[pos];
            }

            const T& at(size_t pos) const
            {
                if(pos >= size_)
                {
                    throw std::out_of_range("Out of range");
                }
                return data_[pos];
            }



        };
}