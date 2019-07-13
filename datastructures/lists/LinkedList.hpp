#include <cassert>
typedef unsigned int size_t;

template<class T>
class LinkedNode
{
    public:
        LinkedNode<T>* Prev = nullptr;
        LinkedNode<T>* Next = nullptr;
        T Cargo;
        LinkedNode(T cargo){Cargo = cargo;}
        void Remove();
}

template<class T>
class LinkedList
{
    private:
        size_t m_count = 0;
        LinkedNode<T>* start = nullptr;
        LinkedNode<T>* end = nullptr;
    public:
        LinkedList(){}
        size_t Count(){return m_count;}
        void Add(T elem);
        void Delete(size_t index);
        void DeleteNode(LinkedNode<T>* node);
        void Insert(size_t index, T elem);
        T operator[](size_t index);
}