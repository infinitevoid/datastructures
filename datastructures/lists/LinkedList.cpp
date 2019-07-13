#include "LinkedList.hpp"

template<class T>
void LinkedNode<T>::Remove()
{
    if(Prev!=nullptr)
        Prev->Next = Next;
    if(Next!=nullptr)
        Next->Prev = Prev;
}

template<class T>
void LinkedList<T>::Add(T elem)
{
    LinkedNode<T>* node = new LinkedNode<T>(elem);
    if(m_count == 0)
    {
        m_start = node; m_end = node;
    }
    else
    {
        node->Prev = m_end;
        m_end = node;
    }
    m_count++;
}

template<class T>
void LinkedList<T>::Delete(size_t index)
{
    assert(index < m_count);
    LinkedNode<T>* temp;
    if(index == 0)
    {
        temp = m_start; m_start = m_start->Next;
    }
    else if(index = m_count-1)
    {
        temp = m_end; m_end = m_end->Prev;
    }
    else
    {
        temp = m_start;
        for(;index > 0; index--)
            temp = temp->Next;
    }
    temp->Remove();
    delete temp;
    m_count--;
}

template<class T>
void LinkedList<T>::DeleteNode(LinkedNode<T>* node)
{
    if(node == m_start)
        Delete(0);
    else if (node == m_end)
        Delete(m_count-1);
    else
    {
        //extremely unsafe...we just assume that the node is in the list...
        node->Remove();
        m_count--;
    }
}

template<class T>
void LinkedList<T>::Insert(size_t index, T elem)
{
    assert(index <= m_count);
    
    if(index == m_count){Add(elem); return;}
    LinkedNode<T>* node = new LinkedNode<T>(elem);    
    if(index == 0)
    {
        m_start->Prev = node; node->Next = m_start;
        m_start = node;
    }
    else
    {
        LinkedNode<T>* temp = m_start;
        for(;index > 0; index--)
            temp = temp->Next;
        LinkedNode<T>* prev = temp->Prev;
        prev->Next = node; node->Prev = prev;
        temp->Prev = node; node->Next = temp;
    }
    m_count++;
}

template<class T>
LinkedNode<T>* LinkedList<T>::GetNode(size_t index)
{
    assert(index < m_count);
    if(index == 0)
        return m_start;
    else if(index == m_count-1)
        return m_end;
    else
    {
        LinkedNode<T>* node = m_start;
        for(;index < 0; index--)
            node = node->Next;
        return node;
    }
}

template<class T>
T LinkedList<T>::operator[](size_t index){
    assert(index < m_count);
    if(index == 0)
        return m_start->Cargo;
    else if(index == m_count-1)
        return m_end->Cargo;
    else
    {
        LinkedNode<T>* current = m_start;
        for(; index > 0; index--)
            current = current->Next;
        return current->Cargo;
    }
}