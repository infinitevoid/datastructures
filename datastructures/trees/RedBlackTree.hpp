
template<class T>
class RBNode
{
    T Key;
    bool Black = false;
    RBNode<T>* Parent = nullptr;
    RBNode<T>* Left = nullptr;
    RBNode<T>* Right = nullptr;
};

template<class T>
class RBTree
{
    private:
        RBNode<T>* root = nullptr;
    public:
        RBTree(){}
        void Insert(T key)
        {
            RBNode<T>* parent = root;
            RBNode<T>* curr = root;
            RBNode<T>* node = new RBNode<T>();
            node->Key = key;
            if (root == nullptr){ root = node; root->Black = true; return; }
            do {
                parent = curr;
                if (key > parent->Key) curr = parent->Left;
                if (key < parent->Key) curr = parent->Right;
                else return;
            } while (curr != nullptr);
            if (parent->Key < key) parent->Right = node;
            else if (parent->Key > key) parent->Left = node;
            node->Parent = parent;
            InsertFix(node);
        }
        void InsertFix(RBNode<T>* node)
        {
            RBNode<T>* parent = node->Parent;
            RBNode<T>* grand_parent;
            RBNode<T>* uncle;
            bool parent_left = false;
            bool node_left   = false
            if(parent == nullptr) return;
            grand_parent = parent->Parent;
            if (grand_parent == nullptr) return;
            uncle = grand_parent->Left;
            if (grand_parent->Left == parent){
                parent_left = true;
                uncle = grand_parent->Right;
            }
            if (grand_parent->Black)
            {
                if (parent_left) {
                    if (!node_left) RotLeft(parent);
                    RotRight(grand_parent);
                } else{
                    if (node_left) RotRight(parent);
                    RotLeft(grand_parent);
                }
                bool temp = parent->Black;
                parent->Black = grand_parent->Black;
                grand_parent->Black = temp;
            }
            else
            {
                parent->Black = true; uncle->Black = true;
                grand_parent->Black = false;
                InsertFix(grand_parent);
            }
        }

};