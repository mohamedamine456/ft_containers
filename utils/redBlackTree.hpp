#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "pair.hpp"

template < class K, class V >
struct Node
{
	bool			red;
	ft::pair<K, V>	data;
	Node<K, V>		*leftChild;
	Node<K, V>		*rightChild;
	Node<K, V>		*parent;
};

template < class K, class V, class Allocator = std::allocator<Node<K, V> > >
class RedBlackTree {
    private:
		Allocator	__alloc;
		Node<K, V> *root;

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
			this->root = rbt.root;
            return *this;
        }

		void	BSTInsertion(Node<K, V> *node) {
			Node<K, V>	*tmp;
			Node<K, V>	*tmp2;

			tmp2 = nullptr;
			tmp = this->root;
			while (tmp != nullptr) {
				tmp2 = tmp;
				if (node->data.first < tmp->data.first)
					tmp = tmp->leftChild;
				else
					tmp = tmp->rightChild;
			}
			node->parent = tmp2;
			if (tmp2 == nullptr)
				this->root = node;
			else if (node->data.first < tmp2->data.first)
				tmp2->leftChild = node;
			else
				tmp2->rightChild = node;
		}

        void    insertNode(Node<K, V> *node) {
			
        }

		void	BSTDelete(Node<K,V> *node, K key) {
			Node<K, V>	*tmp = node;
			Node<K, V>	*tmp1;

			if (tmp == nullptr)
				return ;
			else if (key < tmp->data.first)
				BSTDelete(tmp->leftChild, key);
			else if (key > tmp->data.first)
				BSTDelete(tmp->rightChild, key);
			else
			{
				if (tmp->leftChild == nullptr && tmp->rightChild == nullptr) {
					__alloc.destroy(tmp);
					__alloc.deallocate(tmp);
					tmp = nullptr;
				}
				else if (tmp->leftChild == nullptr) {
					tmp1 = tmp;
					tmp = tmp->leftChild;
					__alloc.destroy(tmp1);
					__alloc.deallocate(tmp1);
					tmp1 = nullptr
				}
				else if (tmp->rightChild == nullptr) {
					tmp1 = tmp;
					tmp = tmp->rightChild;
					__alloc.destroy(tmp1);
					__alloc.deallocate(tmp1);
					tmp1 = nullptr
				}
				else {
					tmp1 = minimum(tmp->rightChild);
					tmp->data = tmp1->data;
					tmp->rightChild = BSTDelete(tmp->rightChild, tmp1->data.key);
				}
			}

				
		}

        void    deleteNode(Node<K, V> *node) {

        }

        void    deleteNode(K key) {

        }

		void	rightRotation() {

		}

		void	leftRotation() {
				
		}

        Node<K, V>	*successor(Node<K, V> *node) {
			Node<K, V>	*tmp = node;
			Node<K, V>	*tmp1;
			if (tmp->rightChild != NULL)
				return this->minimum(tmp->rightChild);
			tmp1 = tmp->parent;
			while (tmp1 != NULL && tmp == tmp1->rightChild)
			{
				tmp = tmp1;
				tmp1 = tmp1->parent;
			}
			return tmp1;
        }

        Node<K, V>	*predecessor(Node<K, V> *node) {
			Node<K, V>	*tmp = node;
			Node<K, V>	*tmp1;
			if (tmp->leftChild != NULL)
				return this->minimum(tmp->leftChild);
			tmp1 = tmp->parent;
			while (tmp1 != NULL && tmp == tmp1->leftChild)
			{
				tmp = tmp1;
				tmp1 = tmp1->parent;
			}
			return tmp1;
        }

        Node<K, V>	*search(Node<K, V> *node, K key) {
			Node<K, V>	*tmp = node;
			while (tmp != NULL)
			{
				if (tmp->data.key == key)
					break ;
				else if (tmp->data.key > key)
					tmp = tmp->leftChild;
				else
					tmp = tmp->rightChild;
			}
			return tmp;
        }

        Node<K, V>	*minimum(Node<K, V> *node) {
			Node<K, V>	*tmp = node;
			while (tmp->leftChild != NULL)
				tmp = tmp->leftChild;
			return tmp;
        }

        Node<K, V>	*maximum(Node<K, V> *node) {
			Node<K, V>	*tmp = node;
			while (tmp->rightChild != NULL)
				tmp = tmp->rightChild;
			return tmp;
        }
};

#endif