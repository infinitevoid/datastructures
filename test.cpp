#include "datastructures/basic/Stack.cpp"
#include <iostream>
#include "datastructures/lists/LinkedList.cpp"
#include "datastructures/trees/MergeSortTree.cpp"
using namespace std;

int main(){
    int arr[17] = {1,2,1,2,2,234,123,5,2,234,1234,5,1234,3,2,9,10};
    MergeSortTree<int> tree{arr,17};
    tree.Debug();
    cout << tree.RangeLessEqual(10,0,16) << endl;
    return 0;
}