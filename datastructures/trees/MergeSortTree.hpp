#include <cstring>
#include <iostream>

typedef unsigned int size_t;

template<class T>
class MergeSortTree
{
    private:
        struct Query
        {
            const T Cmp;
            const size_t RangeStart, RangeEnd;
            Query(T cmp, size_t start,size_t end): Cmp(cmp), RangeStart(start), RangeEnd(end){}
        };
        // pointer to memory are where the tree is stored; size: O(n*log(n)) [m_row*m_height to be exact]
        T* m_tree;
        // pointer to bottom level of the tree
        T* m_array;
        // size of each level in the tree
        size_t m_row;
        // height of the tree 
        size_t m_height;

        // returns ceil(log2(x))+1; is used to calculate the height of the tree
        size_t CeilLog2 (size_t x);
        // recursive function to build tree 
        void BuildTree(size_t level, size_t start, size_t end);
        //  similar to merge operation used by merge-sort
        void Merge(size_t level, size_t start_a, size_t end_a, size_t start_b, size_t end_b);
        // classic binary search; returns index where <cmp> would be inserted if it isn't in the sequence
        size_t BinarySearch(T cmp, size_t start, size_t end);
        // a segment-tree like recursive traversal function
        int RecRangeLessEqual(size_t level, size_t start, size_t end, Query query);     
    public:
        // creates a merge-sort-tree from an array with length <count>    
        MergeSortTree(T array[], size_t count);
        // height of the tree
        size_t Height(){return m_height;}
        // count of elements in original array
        size_t Count(){return m_row;}
        // returns the amount of elements in the range [start,end] which are <= cmp in O(log^2(n)) 
        int RangeLessEqual(T cmp, size_t start, size_t end);
        // returns the amount of elements in the range [start,end] which are > cmp in O(log^2(n))
        int RangeGreater(T cmp, size_t start, size_t end);
        // shorthands
        int RLEQ(T cmp, size_t start, size_t end){ return RangeLessEqual(cmp, start, end)};
        int RGQ(T cmp, size_t start, size_t end){ return RangeGreater(cmp, start, end)};
        // prints the Merge-Sort-Tree
        void Debug();
}; 