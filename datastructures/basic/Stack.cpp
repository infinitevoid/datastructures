#include "Stack.hpp"

template<class T>
Stack<T>::Stack(size_t capacity)
{ 
    assert(capacity > 0);
    m_capacity = capacity;
    m_array = (T*)malloc(sizeof(T)*m_capacity);
}
// methods
template<class T>
void Stack<T>::Resize(size_t capacity)
{
    assert(capacity >= m_count);
    T* new_array = (T*)malloc(sizeof(T)*capacity);
    memcpy((void*)new_array,(void*)m_array, sizeof(T)*m_count);
    delete m_array;
    m_array = new_array;
    m_capacity = capacity;
}
template<class T>
void Stack<T>::Push(T elem)
{
    if(m_count == m_capacity)
        Resize(2*m_capacity);
    m_array[m_count] = elem;
    m_count++;
}
template<class T>
T Stack<T>::Pop()
{
    assert(0 < m_count);
    T temp = m_array[m_count-1];
    m_count--;
    return temp;
}
