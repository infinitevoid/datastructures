#include "MergeSortTree.hpp"

template<class T>
size_t MergeSortTree<T>::CeilLog2(size_t x)
{
    size_t sig = 0;
    while(x >>= 1) sig++;
    if( x - (1 << sig) > 0)
        return sig+2;
    return sig+1;
}

template<class T>
MergeSortTree<T>::MergeSortTree(T array[], size_t count)
{
    m_height = CeilLog2(count);
    m_row = count;
    m_tree = (T*)malloc(sizeof(T)*m_row*m_height);
    m_array = m_tree + m_row * (m_height - 1);
    memcpy((void*)m_array, (void*)array, sizeof(T) * m_row);
    BuildTree(0,0,count);
}

template<class T>
void MergeSortTree<T>::Merge(size_t level, size_t start_a, size_t end_a, size_t start_b, size_t end_b)
{
    //TODO does this even work?!
    size_t i,j,target;
    end_a += level * m_row; end_b += level * m_row;
    target = (level-1)*m_row + start_a;
    i = start_a + level * m_row;
    j = start_b + level * m_row;
    while(i < end_a && j < end_b)
    {
        if(m_tree[i] <= m_tree[j])
        {
            m_tree[target] = m_tree[i];
            i++;
        }
        else
        {
            m_tree[target] = m_tree[j];
            j++;
        }
        target++;
    }
    if(i < end_a)
        memcpy( (void*) (m_tree + target), (void*) (m_tree + i), sizeof(T) * (end_a-i));
    if(j < end_b)
        memcpy( (void*) (m_tree + target), (void*) (m_tree + j), sizeof(T) * (end_b-j));
    //std::cout << "Merged: " << level << " " << start_a << " " << end_a << std::endl;
    //Debug();
}

template<class T>
void MergeSortTree<T>::BuildTree(size_t level, size_t start, size_t end)
{
    if(end == start || level == m_height) return; 
    else if(end-start == 1)
    {
        m_tree[level * m_row + start] = m_array[start];
        return;
    }
    //TODO check stuff with the +-1 inclusive exclusive blabla
    size_t mid = start + (end-start) / 2;
    BuildTree(level+1, start, mid);
    BuildTree(level+1, mid, end);
    Merge(level+1, start, mid, mid, end);
}

template<class T>
size_t MergeSortTree<T>::BinarySearch(T cmp, size_t start, size_t end)
{
    if(start == end) return 0;
    if(end-start == 1)
    {
        if(cmp >= m_tree[start]) return 1;
        return 0;
    }
    size_t index = start + (end - start) / 2;
    std::cout << m_tree[index] << std::endl;
    if(cmp < m_tree[index])
        return BinarySearch(cmp, start, index);
    else if(cmp > m_tree[index])
        return (end - start)/2 + BinarySearch(cmp, index, end);
    return (end-start)/2+1;
}

template<class T>
int MergeSortTree<T>::RangeLessEqual(T cmp, size_t start, size_t end)
{return RecRangeLessEqual(0, 0, m_row, Query(cmp, start, end + 1));}
template<class T>
int MergeSortTree<T>::RangeGreater(T cmp, size_t start, size_t end)
{return (end - start + 1) - RecRangeLessEqual(0, 0, m_row, Query(cmp, start, end+1));}


template<class T>
int MergeSortTree<T>::RecRangeLessEqual(size_t level, size_t start, size_t end, Query query)
{
    size_t mid = start + (end-start)/2;
    if(end <= query.RangeStart || query.RangeEnd <= start)
        return 0;
    else if(query.RangeStart <= start && end <= query.RangeEnd)
        return BinarySearch(query.Cmp, m_row*level + start, m_row*level + end);
    else
        return RecRangeLessEqual(level+1, start, mid, query) + RecRangeLessEqual(level+1, mid, end, query);
}


template<class T>
void MergeSortTree<T>::Debug()
{
    using namespace std;
    for(int i = 0; i<m_height; i++)
    {
        for(int j = 0; j<m_row; j++)
            cout << m_tree[i*m_row+j] << "|";
        cout << endl;
    }
}
