
typedef unsigned int size_t;

template<class T>
class Queue
{
    public:
        // returns current length of the queue
        size_t Count();
        // returns oldest element in the queue
        T Front();
        // returns youngest element in the queue
        T Back();
        // adds element to queue
        void Enqueue(T element);
        void Push(T element);
        // removes oldest element from the queue
        T Dequeue();
        T Pop();

};