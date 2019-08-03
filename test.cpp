#include <iostream>
#include "datastructures/trees/AVLTree.cpp"
using namespace std;



int main(){
    AVLTree<int> avl{};
    avl.Insert(12);
    avl.Insert(23);
    avl.Insert(-12);
    cout << avl.Max() << "|" << avl.Min() << endl;
    return 0;
}