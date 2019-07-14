
//NOTE: this implementation requires C++ 17 !!!
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
typedef unsigned int size_t;

/*
== example ==

template<class T>
T Min(T a, T b)
{
    if(a <= b) return a;
    return b;
}

int arr[10] = {1,4,5,2,6,8,2,0,9,34};
SegmentTree<int,Min<int>,1000> tree{arr,10};
tree.Debug();
std::cout << tree.RangeQuery(5,8) << std::endl;

== template paramters==
The SegmentTree class has three template parameters:
T       - type of elements in input array f.e. int
Func    - a "aggregate" function like min or max; signature: T Func(T a, T b)
Default - Func(x, Default) should always equal x (f.e. for Func = min and T = int Default should be INT_MAX)
*/
// there is an auto in front of Func because function types aren't supported as template parameters types in C++17
template<class T, auto Func, T Default>
class SegmentTree 
{
    private:
        struct Query 
        {
            const size_t RangeStart,RangeEnd;
            Query(size_t start, size_t end): RangeStart(start), RangeEnd(end){}
        };

        T* m_tree;
        T* m_array;
        size_t m_count;
        size_t m_real_count;
        // calculates next power of 2 after n
        size_t NextPower(size_t n);
        // fills the m_tree[index] with the result of Func(left child, right child)
        T Fill(size_t index);
        // recursice traversal function that resolves a query
        T RecRangeQuery(size_t index, size_t left, size_t right, Query query);
        // utility methods
        size_t Left(size_t node){return 2*node+1;}
        size_t Right(size_t node){return 2*node+2;}
    public:
        SegmentTree(T* array, size_t count);
        // returns aggregate (f.e. the min or max) of the range [start, end] in O(log n)
        T RangeQuery(size_t start, size_t end);
        void Debug();
};

