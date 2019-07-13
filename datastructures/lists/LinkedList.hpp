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
};

template<class T>
class LinkedList
{
    private:
        size_t m_count = 0;
        LinkedNode<T>* m_start = nullptr;
        LinkedNode<T>* m_end = nullptr;
    public:
        LinkedList(){}
        size_t Count(){return m_count;}
        T First(){assert(m_count > 0); return m_start->Cargo;}
        T Last(){assert(m_count > 0); return m_end->Cargo;}
        void Add(T elem);
        void Delete(size_t index);
        //unsafe operation... assumes node is in list
        void DeleteNode(LinkedNode<T>* node);
        void Insert(size_t index, T elem);
        LinkedNode<T>* GetNode(size_t index);
        T operator[](size_t index);
};