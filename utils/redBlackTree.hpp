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
			this->root = nullptr;
        }

        RedBlackTree(K key, V value) {
            
        }

        RedBlackTree(RedBlackTree &rbt) {
            *this = rbt;
        }

        ~RedBlackTree() {}

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
			BSTInsertion(node);
			Node<K, V>	*tmp = this->root;
			Node<K, V>	*tmpU;

			while (node->parent && node->parent->red == true)
			{
				if (node->parent == node->parent->parent->rightChild)
				{
					tmpU = node->parent->parent->leftChild;
					if (tmpU->red == true) {
						tmpU->red = false;
						node->parent->red = false;
						node->parent->parent->red = true;
						node = node->parent->parent;
					}
					else if (node == node->parent->leftChild) {
						node = node->parent;
						rightRotation(node);
					}
					node->parent->red = false;
					node->parent->parent->red = true;
					leftRotation(node->parent->parent);
				}
				else {
					tmpU = node->parent->parent->rightChild;
					if (tmpU->red == true) {
						tmpU->red = false;
						node->parent->red = false;
						node->parent->parent->red = true;
						node = node->parent->parent;
					}
					else if (node == node->parent->rightChild) {
						node = node->parent;
						leftRotation(node);
					}
					node->parent->red = false;
					node->parent->parent->red = true;
					rightRotation(node->parent->parent);
				}
			}
			this->root->red = false;
        }

		Node<K,V>	*BSTDelete(Node<K,V> *node, K key) {
			Node<K, V>	*tmp = node;
			Node<K, V>	*tmp1;

			if (tmp == nullptr)
				return node;
			else if (key < tmp->data.first)
				BSTDelete(tmp->leftChild, key);
			else if (key > tmp->data.first)
				BSTDelete(tmp->rightChild, key);
			else
			{
				if (tmp->leftChild == nullptr && tmp->rightChild == nullptr) {
					__alloc.destroy(tmp);
					__alloc.deallocate(tmp, 1);
					tmp = nullptr;
				}
				else if (tmp->leftChild == nullptr) {
					tmp1 = tmp;
					tmp = tmp->leftChild;
					__alloc.destroy(tmp1);
					__alloc.deallocate(tmp1, 1);
					tmp1 = nullptr;
				}
				else if (tmp->rightChild == nullptr) {
					tmp1 = tmp;
					tmp = tmp->rightChild;
					__alloc.destroy(tmp1);
					__alloc.deallocate(tmp1, 1);
					tmp1 = nullptr;
				}
				else {
					tmp1 = minimum(tmp->rightChild);
					tmp->data = tmp1->data;
					tmp->rightChild = BSTDelete(tmp->rightChild, tmp1->data.first);
				}
			}
			return node;
		}

        void    deleteNode(Node<K, V> *node) {
			Node<K, V> *tmpS;
			BSTDelete(this->root, node->data.first);
			while (node != this->root && node->red == false) {
				if (node == node->parent->leftChild) {
					tmpS = node->parent->rightChild;
					if (tmpS->red == true) {
						tmpS->red = false;
						node->parent->red = true;
						leftRotation(node->parent);
						tmpS = node->parent->rightChild;
					}
					if (tmpS->leftChild->red == false && tmpS->rightChild->red == false) {
						tmpS->red = true;
						node = node->parent;
					} else { 
						if (tmpS->rightChild->red == false) {
							tmpS->leftChild->red = false;
							tmpS->red = true;
							rightRotation(tmpS);
							tmpS = node->parent->rightChild;
						}
						tmpS->red = node->parent->red;
						node->parent->red = false;
						node->rightChild->red = false;
						leftRotation(node->parent);
						node = this->root;
					}
				} else {
					tmpS = node->parent->leftChild;
					if (tmpS->red == true) {
						tmpS->red = false;
						node->parent->red = true;
						rightRotation(node->parent);
						tmpS = node->parent->leftChild;
					}
					if (tmpS->rightChild->red == false && tmpS->leftChild->red == false) {
						tmpS->red = true;
						node = node->parent;
					}
					else {
						if (tmpS->leftChild->red == false) {
							tmpS->rightChild->red = false;
							tmpS->red = true;
							leftRotation(node->parent);
							tmpS = node->parent->leftChild;
						}
						tmpS->red = node->parent->red;
						node->parent->red = false;
						node->leftChild->red = false;
						rightRotation(node->parent);
						node = this->root;
					}
				}
			}
			node->red = false;
        }

        void    deleteNode(K key) {
			BSTDelete(this->root, key);
        }

		void	rightRotation(Node<K, V> *node) {
			Node<K, V>	*tmp = node->leftChild;

			node->leftChild = tmp->rightChild;
			if (tmp->rightChild != nullptr) {
				tmp->rightChild->parent = node;
			}
			tmp->parent = node->parent;
			if (node->parent == nullptr) {
				this->root = tmp;
			} else if (node == node->parent->rightChild) {
				node->parent->rightChild = tmp;
			} else {
				node->parent->leftChild = tmp;
			}
			tmp->rightChild = node;
			node->parent = tmp;
		}

		void	leftRotation(Node<K, V> *node) {
			Node<K, V> *tmp = node->rightChild;

			node->rightChild = tmp->leftChild;
			if (tmp->leftChild != nullptr) {
				tmp->leftChild->parent = node;
			}
			tmp->parent = node->parent;
			if (node->parent == nullptr) {
				this->root = tmp;
			} else if (node == node->parent->leftChild) {
				node->parent->leftChild = tmp;
			} else {
				node->parent->rightChild = tmp;
			}
			tmp->leftChild = node;
			node->parent = tmp;
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