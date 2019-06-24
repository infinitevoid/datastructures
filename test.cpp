#include "datastructures/lists/LinkedList.hpp"
#include <iostream>

using namespace std;

int main(){
    SinglyLinkedList<int> ll;
    ll.Add(50);
    ll.Add(13);
    cout << ll.First() << " " << ll[1] << endl;
    cout << "Hello" << endl;
    //ll.Insert(0,10); ll.Insert(3, 10);
    ll.Insert(0,1);ll.Insert(3,10);
    cout << ll.First() << " " << ll.Count() << endl;
    cout << ll.Last() << " " << ll.First() << endl;
    ll.Delete(0);ll.Delete(1);
    cout << ll[0] << " " << ll[1] << endl;

}