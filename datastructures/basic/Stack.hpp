#include <cassert>
#include <cstring>
typedef unsigned int size_t;


// generic and dynamic Stack
template<class T>
class Stack
{
    public:
        // initializes stack with a given capacity 
        Stack(size_t capacity = 16);
        // return top element on the stack
        T Top();
        // returns count of elements on the stack
        size_t Count();
        // returns (current) capacity of the stack 
        size_t Capacity();
        // resizes stack to a certain capacity
        void Resize(size_t capacity);
        // pushes element on stack; resizes automatically if full
        void Push(T elem);
        // pops element on top 
        T Pop();
};