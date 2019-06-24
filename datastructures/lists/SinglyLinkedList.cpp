#include "SinglyLinkedList.hpp"

// methods
template<class T>
void SinglyLinkedList<T>::Add(T element){
    if (m_start == nullptr){
        m_start = new SinglyLinkedNode<T>(element, nullptr);
        m_end = m_start;
    }
    else{
        SinglyLinkedNode<T>* temp = m_end;
        m_end = new SinglyLinkedNode<T>(element, nullptr);
        temp->Next = m_end;
    }
    m_count++;
}
template<class T>
void SinglyLinkedList<T>::Insert(size_t index, T element)
{
    assert(index <= m_count);
    if(index == 0)
    {
        SinglyLinkedNode<T>* temp = m_start;
        m_start = new SinglyLinkedNode<T>(element, temp);
    }
    else if (index == m_count){
        m_end->Next = new SinglyLinkedNode<T>(element, nullptr);
        m_end = m_end->Next;
    }
    else
    {
        SinglyLinkedNode<T>* prev = m_start;
        SinglyLinkedNode<T>* next = m_start->Next;
        for(int i = 1; i < index; i++)
        {
            prev = next;
            next = prev->Next;
        }
        prev->Next = new SinglyLinkedNode<T>(element, next);
    }
    m_count++;
}
template<class T>
void SinglyLinkedList<T>::Delete(size_t index)
{
    assert(index < m_count);
    if(index == 0)
    {
        SinglyLinkedNode<T>* temp = m_start;
        m_start = temp->Next;
        delete temp;
    }
    else
    {
        SinglyLinkedNode<T>* prev = m_start;
        SinglyLinkedNode<T>* next = m_start->Next;
        for(int i = 1; i < index; i++)
        {
            prev = next;
            next = prev->Next;
        }
        prev->Next = next->Next;
    }
    m_count--;
}
template<class T>
T SinglyLinkedList<T>::operator [](size_t index){
    assert(index < m_count);
    if(index == 0) return m_start->Cargo;
    else if(index == m_count-1) return m_end->Cargo;
    else
    {
        SinglyLinkedNode<T>* curr = m_start;
        for(int i = 0; i < index; i++) curr = curr->Next;
        return curr->Next->Cargo;
    }
}
