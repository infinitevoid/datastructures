

template<class T>
class AVLNode
{
    public:
        // key stored in the node
        T Key;
        // height of this subtree
        int Height;
        // left and right children
        AVLNode<T>* Left  = nullptr;
        AVLNode<T>* Right = nullptr;

        AVLNode(T key): Key(key){}
        // insert and remove <node>
        AVLNode<T>* Insert(AVLNode<T>* node);
        AVLNode<T>* Remove(T key);
        // min and max
        T Min();
        T Max();
        bool Contains(T key);
        // Balance = Right->Height - Left->Height
        int Balance();
        // updates height
        void Update();
        // detaches subtree with <node> as root
        AVLNode<T>* Detach(AVLNode<T>* node);
        // ensures that Balance is between -1 and 1
        AVLNode<T>* Rebalance();
        // rotates subtree right
        AVLNode<T>* RotRight();
        // rotates subtree left
        AVLNode<T>* RotLeft();
};

// a wrapper class
template<class T>
class AVLTree
{
    private:
        AVLNode<T>* root = nullptr;
    public:
        AVLTree(){}
        T Min(); T Max();
        void Insert(T key);
        void Remove(T key);
        bool Contains(T key);
};