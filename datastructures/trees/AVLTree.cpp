
#include "AVLTree.hpp"

template<class T>
int AVLNode<T>::Balance()
{ 
    if(Right == nullptr && Left == nullptr) return 0;
    else if (Right == nullptr) return -Left->Height;
    else if (Left == nullptr) return Right->Height;
    else return Right->Height - Left->Height;
}

template<class T>
AVLNode<T>* AVLNode<T>::Insert(AVLNode<T>* node)
{
    if(node->Key > Key)
    {
        if (Right != nullptr) Right = Right->Insert(node);
        else Right = node;
    }
    else if(node->Key < Key)
    { 
        if (Left != nullptr) Left = Left->Insert(node);
        else Left = node;
    }
    return Rebalance();
}

template<class T>
AVLNode<T>* AVLNode<T>::Remove(T key)
{
    if(key > Key && Right != nullptr)
        Right = Right->Remove(key);
    else if(key < Key && Left != nullptr)
        Left = Left->Remove(key);
    else 
    {
        AVLNode<T>* ptr;
        if(Left == nullptr && Right == nullptr) ptr = nullptr;
        else if (Left == nullptr && Right != nullptr) ptr = Right->Rebalance();
        else if (Left != nullptr && Right == nullptr) ptr = Left->Rebalance();
        else 
        {
            ptr = Right->Min();
            Right = Right->Detach(ptr);
            ptr->Right = Right;
            ptr->Left = Left;
            ptr = ptr->Rebalance();
        }
        delete this;
        return ptr;
    }
    return Rebalance();
}

template<class T>
AVLNode<T>* AVLNode<T>::Min()
{
    if(Left != nullptr) return Left->Min();
    return this;
}

template<class T>
AVLNode<T>* AVLNode<T>::Max()
{
    if(Right != nullptr) return Right->Max();
    return this;
}

template<class T>
bool AVLNode<T>::Contains(T key)
{
    if(Key < key && Right != nullptr) return Right->Contains(key);
    else if (Key > key && Left != nullptr) return Left->Contains(key);
    else if (Key == key) return true;
    return false;
}

template<class T>
AVLNode<T>* AVLNode<T>::Detach(AVLNode<T>* node)
{
    if(node->Key > Key && Right != nullptr)
        Right = Right->Detach(node);
    else if(node->Key < Key && Left != nullptr)
        Left = Left->Detach(node);
    else 
    {
        delete this;
        return nullptr;
    }
    return Rebalance();
}

template<class T>
AVLNode<T>* AVLNode<T>::Rebalance()
{
    int factor = Balance();
    if(factor > 1)
    {
        int rb = Right->Balance();
        if(rb == -1) Right = Right->RotRight();
        return RotLeft();
    } else if (factor < -1)
    {
        int lb = Left->Balance();
        if(lb == 1) Left = Left->RotLeft();
        return RotRight();
    }
    Update();
    return this;
}

template<class T>
AVLNode<T>* AVLNode<T>::RotRight()
{
    AVLNode<T>* left = Left;
    Left = Left->Right;
    Update();
    left->Right = this;
    left->Update();
    return left;
}

template<class T>
AVLNode<T>* AVLNode<T>::RotLeft()
{
    AVLNode<T>* right = Right;
    Right = Right->Left;
    Update();
    right->Left = this;
    right->Update();
    return right;
}

template<class T>
void AVLNode<T>::Update()
{
    if(Right == nullptr && Left == nullptr) Height = 1;
    else if(Right == nullptr) Height = Left->Height+1;
    else if(Left  == nullptr) Height = Right->Height+1;
    else if(Right->Height > Left->Height) Height = Right->Height + 1;
    else Height = Left->Height + 1;
}


template<class T>
void AVLTree<T>::Insert(T key)
{
    AVLNode<T>* node = new AVLNode<T>(key);
    if(root == nullptr) root = node;
    else root = root->Insert(node);
}

template<class T>
void AVLTree<T>::Remove(T key)
{
    if(root == nullptr) return;
    else root = root->Remove(key);
}

template<class T>
bool AVLTree<T>::Contains(T key)
{
    if(root == nullptr) return false;
    return root->Contains(key);
}

template<class T>
T AVLTree<T>::Min()
{ return root->Min()->Key; }
template<class T>
T AVLTree<T>::Max()
{ return root->Max()->Key; }