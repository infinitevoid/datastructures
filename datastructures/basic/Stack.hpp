#include <cassert>
#include <cstring>
typedef unsigned int size_t;


// generic and dynamic Stack
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
        // initializes stack with a given capacity 
        Stack(size_t capacity = 16);
        // return top element on the stack
        T Top()             {assert(0 < m_count); return m_array[m_count-1];}
        // returns count of elements on the stack
        size_t Count()      {return m_count;}
        // returns (current) capacity of the stack 
        size_t Capacity()   {return m_capacity;}
        // resizes stack to a certain capacity
        void Resize(size_t capacity);
        // pushes element on stack; resizes automatically if full
        void Push(T elem);
        // pops element on top 
        T Pop();
};