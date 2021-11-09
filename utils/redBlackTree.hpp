#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>

template < class K, class V, class Compare = std::less<K> >
class RedBlackTree {
    private:
        bool			red;
        K				key;
        V				value;
        RedBlackTree	*leftChild;
        RedBlackTree	*rightChild;
        RedBlackTree	*parent;

    public:
        RedBlackTree() {

        }

        RedBlackTree(K key, V value) {
            
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

		void	rightRotation() {

		}

		void	leftRotation() {
				
		}

        RedBlackTree    *successor(K key) {

        }

        RedBlackTree    *predecessor(K key) {

        }

        RedBlackTree    *search(K key) {
			RedBlackTree tmp = *this;
			while (tmp != NULL)
			{
				if (tmp.key == key)
					break ;
				else if (tmp.key > key)
					tmp = tmp.leftChild;
				else
					tmp = tmp.rightChild;
			}
			return tmp;
        }

        RedBlackTree    *minimum() {
			RedBlackTree	tmp = *this;
			while (tmp->leftChild != NULL)
				tmp = tmp->leftChild;
			return tmp;
        }

        RedBlackTree    *maximum() {
			RedBlackTree	tmp = *this;
			while (tmp->rightChild != NULL)
				tmp = tmp->rightChild;
			return tmp;
        }
};

#endif