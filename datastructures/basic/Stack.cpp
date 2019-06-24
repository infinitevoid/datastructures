#include "Stack.hpp"

template<class T>
class Stack
{
    private:
        // current capactiy
        size_t m_capacity = 0;
        // current count 
        size_t m_count = 0;
        // allocated memory 
        T* m_array = nullptr;
    public:
        Stack(size_t capacity = 16)
        { 
            assert(capacity > 0);
            m_capacity = capacity;
            m_array = (T*)malloc(sizeof(T)*m_capacity);
        }
        // properties
        size_t Count(){ return m_count;}
        size_t Capacity(){ return m_capacity;}
        T Top(){return m_array[m_count-1];}
        // methods
        void Resize(size_t capacity)
        {
            assert(capacity >= m_count);
            T* new_array = (T*)malloc(sizeof(T)*capacity);
            memcpy((void*)new_array,(void*)m_array, sizeof(T)*m_count);
            delete m_array;
            m_array = new_array;
            m_capacity = capacity;
        }
        void Push(T elem)
        {
            if(m_count == m_capacity)
                Resize(2*m_capacity);
            m_array[m_count] = elem;
            m_count++;
        }
        T Pop()
        {
            assert(0 < m_count);
            T temp = m_array[m_count-1];
            m_count--;
            return temp;
        }
};