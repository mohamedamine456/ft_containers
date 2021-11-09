#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "pair.hpp"

template < class K, class V, class Compare = std::less<K> >
class RedBlackTree {
    private:
        bool			red;
		ft::pair<K, V>	key_value;
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
			RedBlackTree	tmp1, tmp2;
		}

		void	leftRotation() {
				
		}

        RedBlackTree	successor() {
			RedBlackTree	tmp1 = *this;
			RedBlackTree	tmp;
			if (tmp1.rightChild != NULL)
				return tmp1.rightChild->minimum();
			tmp = tmp1.parent;
			while (tmp != NULL && *this == tmp.rightChild)
			{
				tmp1 = tmp;
				tmp = tmp.parent;
			}
			return tmp;
        }

        RedBlackTree	predecessor() {
			RedBlackTree	tmp1 = *this;
			RedBlackTree	tmp;
			if (tmp1.leftChild != NULL)
				return tmp1.leftChild->minimum();
			tmp = tmp1.parent;
			while (tmp != NULL && *this == tmp.leftChild)
			{
				tmp1 = tmp;
				tmp = tmp.parent;
			}
			return tmp;
        }

        RedBlackTree	search(K key) {
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

        RedBlackTree	minimum() {
			RedBlackTree	tmp = *this;
			while (tmp->leftChild != NULL)
				tmp = tmp->leftChild;
			return tmp;
        }

        RedBlackTree	maximum() {
			RedBlackTree	tmp = *this;
			while (tmp->rightChild != NULL)
				tmp = tmp->rightChild;
			return tmp;
        }
};

#endif