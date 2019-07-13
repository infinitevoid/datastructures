#include <cstring>

typedef unsigned int size_t;




template<class T>
class MergeSortTree
{
    private:
        T* m_tree;
        T* m_array;
        size_t m_row;
        size_t m_height;

        size_t CeilLog2 (size_t x) 
        {
            size_t sig = 0;
            while(x >>= 1) sig++;
            if( x - (1 << sig) > 0)
                return sig+1;
            return sig;
        }
        void BuildTree(size_t level, size_t start, size_t end);
        void Merge(size_t level, size_t start_a, size_t end_a, size_t start_b, size_t end_b);
    public:
    
        MergeSortTree(T* array, size_t count);
        //int Less(T cmp, size_t range_start, size_t range_end);
        //int Greater(T cmp, size_t range_start, size_t range_end);        
};