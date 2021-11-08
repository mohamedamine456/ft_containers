#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

template < class T, class U >
class RedBlackTree {
    private:
        bool red;
        T   key;
        U   value;
        RedBlackTree *leftChild;
        RedBlackTree *rightChild;
        RedBlackTree *parent;

    public:
        RedBlackTree() {

        }
        RedBlackTree(RedBlackTree &rbt) {
            *this = rbt;
        }
        
}

#endif