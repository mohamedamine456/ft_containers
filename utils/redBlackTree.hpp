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

        RedBlackTree(T key, U value) {
            
        }

        RedBlackTree(RedBlackTree &rbt) {
            *this = rbt;
        }

        ~RedBlackTree();

        RedBlackTree &operator= (RedBlackTree &rbt) {
            return *this;
        }

        void    insert(RedBlackTree *node) {

        }

        void    delete(RedBlackTree *node) {

        }

        void    delete(T key) {

        }

        RedBlackTree    *successor() {

        }

        RedBlackTree    *predecessor() {

        }

        RedBlackTree    *search(T key) {

        }

        RedBlackTree    *minimum() {

        }

        RedBlackTree    *maximum() {

        }
};

#endif