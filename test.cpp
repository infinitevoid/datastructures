#include <iostream>
#include "datastructures/trees/AVLTree.cpp"
using namespace std;

int main(){
    AVLTree<int> avl = AVLTree<int>();
    avl.Insert(12);
    avl.Insert(-123);
    avl.Insert(13);
    avl.Insert(-3);
    cout << avl.Min() << "|" << avl.Max() << endl;
    cout << avl.Contains(4) << "|" << avl.Contains(-3) << endl;
    avl.Remove(-3);
    cout << avl.Contains(-3) << endl;
    return 0;
}
