#include <cassert>
typedef unsigned int size_t;

// generic singly linked list
template<class T>
class SinglyLinkedList
{
    public:
        // length of the list
        size_t Count();
        // appends element in O(1)
        void Add(T element);
        // inserts element in O(n) (for indices 0 and Count() in O(1))
        void Insert(size_t index, T element);
        // deletes element in O(n) (for first and last element in O(1))
        void Delete(size_t index);
        // returns element at a given index in O(n) (for first and last element in O(1))
        T operator [](size_t index);
};