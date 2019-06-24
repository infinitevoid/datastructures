#include "datastructures/basic/Stack.hpp"
#include <iostream>

using namespace std;

int main(){
    Stack<int> st{2};
    st.Push(12);
    st.Push(0);
    st.Push(-12);
    st.Push(-12);
    st.Push(-12);
    st.Push(-12);
    st.Push(-12);
    st.Push(-12);
    st.Push(-12);
    st.Push(-12);
    st.Push(1234);
    st.Push(-2345);
    st.Push(1232);
    st.Push(1);

    st.Push(132);

    cout << st.Pop() << " " << st.Count() <<" "<< st.Capacity()<< " " << st.Pop() << endl;
}