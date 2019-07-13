#include "datastructures/basic/Stack.cpp"
#include <iostream>
#include "datastructures/lists/LinkedList.cpp"
#include "datastructures/trees/MergeSortTree.cpp"
using namespace std;

int main(){
    LinkedList<int> list{};
    list.Add(123);
    list.Insert(0,12234);
    list.Insert(0,334);
    list.Delete(0);
    //cout << list.First() << endl;
    //cout << list.Last() << endl;
    cout << log2(2*2*2*2*2+1) << endl;
    return 0;
}