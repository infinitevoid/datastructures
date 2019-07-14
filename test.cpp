#include "datastructures/basic/Stack.cpp"
#include <iostream>
#include "datastructures/lists/LinkedList.cpp"
#include "datastructures/trees/SegmentTree.cpp"
using namespace std;


template<class T>
T Min(T a, T b)
{
    if(a <= b) return a;
    return b;
}


int main(){
    int arr[10] = {1,4,5,2,6,8,2,0,9,34};
    SegmentTree<int,Min<int>,1000> tree{arr,10};
    tree.Debug();
    cout << tree.RangeQuery(5,8) << endl;
    return 0;
}