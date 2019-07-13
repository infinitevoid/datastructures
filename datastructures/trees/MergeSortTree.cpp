#include "MergeSortTree.hpp"



template<class T>
MergeSortTree<T>::MergeSortTree(T* array, size_t count)
{
    m_height = CeilLog2(count);
    m_row = count;
    m_tree = (T*)malloc(sizeof(T)*m_row*m_height);
    m_array = m_tree + m_row * (height - 1) 
    memcpy((void*)m_array, (void*)array, sizeof(T)*m_row);
}

template<class T>
void Merge(size_t level, size_t start_a, size_t end_a, size_t start_b, size_t end_b)
{
    //TODO does this even work?!
    end_a += level*m_row; end_b += level*m_row;
    size_t arr = (level-1)*m_row + start_a;
    size_t i = start_a + level*m_row, j = start_b + level * m_row;
    while(i <= end_a && j <= end_b)
    {
        if(m_tree[i] =< m_tree[j])
        {
            m_tree[arr] = m_tree[i];
            i++;
        }
        else
        {
            m_tree[arr] = m_tree[j];
            j++;
        }
        arr++;
    }
    //TODO check with boundaries end_a-i +1?!?!
    if(i <= end_a)
        memcpy( (void*) (m_tree + arr), (void*) (m_tree + i), sizeof(T) * (end_a-i+1));
    if(j <= end_b)
        memcpy( (void*) (m_tree + arr), (void*) (m_tree + j), sizeof(T) * (end_b-j+1));
}

template<class T>
void MergeSortTree<T>::BuildTree(size_t level, size_t start, size_t end)
{
    if(start == end) return;
    //TODO check stuff with the +-1 inclusive exclusive blabla
    mid = (end-start) / 2
    BuildTree(level+1, start, mid);
    BuildTree(level+1, mid+1, end);
    Merge(level+1, start, mid, mid+1, end);
}