#include "datastructures/basic/Stack.cpp"
#include <iostream>
#include "datastructures/lists/LinkedList.cpp"
using namespace std;

int main(){
    LinkedList<int> list{};
    list.Add(123);
    list.Insert(0,12234);
    list.Insert(0,334);
    list.Delete(0);
    cout << list.First() << endl;
    cout << list.Last() << endl;
    return 0;
}