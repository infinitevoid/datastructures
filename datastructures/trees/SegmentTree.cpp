#include "SegmentTree.hpp"

template<class T, auto Func, T Default>
size_t SegmentTree<T, Func, Default>::NextPower(size_t n)
{
    size_t p = 1;
    while(p < n ) p = p << 1;
    return p;
}

template<class T, auto Func, T Default>
SegmentTree<T, Func, Default>::SegmentTree(T* array, size_t count)
{
    m_count = count;
    m_real_count = NextPower(m_count);
    m_tree = (T*)malloc(sizeof(T)*(2*m_real_count-1));
    m_array = m_tree + (m_real_count-1);
    memcpy((void*)m_array,(void*)array,sizeof(T)*m_count);
    Debug();
    Fill(0);
}

template<class T, auto Func, T Default>
T SegmentTree<T, Func, Default>::Fill(size_t index)
{
    if(index >= m_real_count - 1 + m_count) m_tree[index] = Default;
    if(index >= m_real_count-1) return m_tree[index];

    T temp = Func(Fill(Left(index)), Fill(Right(index)));
    m_tree[index] = temp;
    return temp;
}

template<class T, auto Func, T Default>
T SegmentTree<T, Func, Default>::RangeQuery(size_t start, size_t end)
{
    assert(end >= start && end < m_count);
    return RecRangeQuery(0,0,m_real_count,Query(start,end+1));
}

template<class T, auto Func, T Default>
T SegmentTree<T, Func, Default>::RecRangeQuery(size_t index, size_t left, size_t right, const Query query)
{
    if(right <= query.RangeStart || left >= query.RangeEnd)
        return Default;
    else if(query.RangeStart <= left && right <= query.RangeEnd)
        return m_tree[index];
    else
        return Func(RecRangeQuery(Left(index), left, (left+right)/2, query), RecRangeQuery(Right(index), (left+right)/2, right, query));
}

template<class T, auto Func, T Default>
void SegmentTree<T, Func, Default>::Debug()
{
    int count = 1;
    int last = 1;
    for(int i = 0; i<m_real_count*2-1; i++)
    {
        count--;
        std::cout << m_tree[i] << " ";
        if(count == 0){std::cout << std::endl;last = 2*last; count = last;}
    }
    std::cout << std::endl;
}