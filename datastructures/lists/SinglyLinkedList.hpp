#include <cassert>
typedef unsigned int size_t;

// helper class
template<class T>
class SinglyLinkedNode 
{
    public:
        SinglyLinkedNode(T cargo, SinglyLinkedNode<T>* next){ Cargo = cargo;Next = next;}
        // next node in the singly linked chain
        SinglyLinkedNode<T>* Next;
        // cargo of the node
        T Cargo;
};


// generic singly linked list
template<class T>
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
        // length of the list
        int Count(){ return m_count; }
        // returns last element in the list
        T First(){ assert(m_count > 0); return m_start->Cargo; }
        // returns first element in the list
        T Last(){ assert(m_count > 0); return m_end->Cargo; }
        // appends element in O(1)
        void Add(T element);
        // inserts elemen   t in O(n) (for indices 0 and Count() in O(1))
        void Insert(size_t index, T element);
        // deletes element in O(n) (for first and last element in O(1))
        void Delete(size_t index);
        // returns element at a given index in O(n) (for first and last element in O(1))
        T operator [](size_t index);
};