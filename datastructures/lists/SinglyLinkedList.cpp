#include "SinglyLinkedList.hpp"

// helper class
template<typename T>
class SinglyLinkedNode {
    public:
        // next node in the singly linked chain
        SinglyLinkedNode<T>* Next;
        // cargo of the node
        T Cargo;
        SinglyLinkedNode(T cargo, SinglyLinkedNode<T>* next)
        {
            Cargo = cargo;
            Next = next;
        }
};

template<typename T>
class SinglyLinkedList
{
private:
    // pointer to first node
    SinglyLinkedNode<T>* m_start = nullptr;
    // pointer to last node
    SinglyLinkedNode<T>* m_end = nullptr;
    // current count of nodes
    size_t m_count = 0; 
public:
    // properties
    int Count(){ return m_count; }
    T First(){ assert(m_count > 0); return m_start->Cargo; }
    T Last(){ assert(m_count > 0); return m_end->Cargo; }

    // methods
    void Add(T element){
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
    void Insert(size_t index, T element)
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
    void Delete(size_t index)
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
    T operator [](size_t index){
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
};