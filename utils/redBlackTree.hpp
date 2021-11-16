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

template < class K, class V, class Allocator = std::allocator<Node<K, V> >, class Compare = std::less<K> >
class RedBlackTree {
    private:
		Allocator	__alloc;
		size_t		size;
		Node<K, V> *root;
		Compare comp;

    public:
        RedBlackTree() {
			this->root = nullptr;
			size = 0;
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

		Node<K, V> *getRoot() const {
			return this->root;
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

		void	rotate(Node<K, V>	*node) {
			if (node == node->parent->leftChild) {
				if (node->parent == node->parent->parent->leftChild) {
					rightRotation(node->parent->parent);
					node->red = true;
					node->parent->red = false;
					if (node->parent->rightChild)
						node->parent->rightChild->red = true;
					return ;
				}
				leftRotation(node->parent->parent);
				node->red = false;
				node->rightChild->red = true;
				node->leftChild->red = true;
			}
			else {
				if (node->parent == node->parent->parent->rightChild) {
					leftRotation(node->parent->parent);
					node->red = true;
					node->parent->red = false;
					if (node->parent->leftChild)
						node->parent->leftChild->red = true;
					return ;
				}
				leftRotation(node->parent->parent);
				rightRotation(node->parent->parent);
				node->red = false;
				node->rightChild->red = true;
				node->leftChild->red = true;
			}
		}
		
        void    insertNode(Node<K, V> *node) {

			BSTInsertion(node);
			Node<K, V>	*tmp = this->root;
			Node<K, V>	*tmpU;

			if (node == this->root)
				return;
			while (node->parent && node->parent->red == true)
			{
				if (node->parent == node->parent->parent->rightChild)
				{
					tmpU = node->parent->parent->leftChild;
					if (tmpU == nullptr || tmpU->red == false) {
						rotate(node);	 
					} else if (tmpU != nullptr) {
						tmpU->red = false;
						node->parent->parent->red = true;
						node->parent->red = false;
						node = node->parent->parent;
					}
				}
				else {
					tmpU = node->parent->parent->rightChild;
					if (tmpU == nullptr || tmpU->red == false) {
						rotate(node);
					} else if (tmpU != nullptr) {
						tmpU->red = false;
						node->parent->parent->red = true;
						node->parent->red = false;
						node = node->parent->parent;
					}
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
			Node<K, V> *tmp = node->leftChild;

			node->leftChild = tmp->rightChild;
			if (node->leftChild != nullptr) {
				node->leftChild->parent = node;
			}
			if (node->parent == nullptr) {
				this->root = tmp;
				tmp->parent = nullptr;
			}
			else {
				tmp->parent = node->parent;
				if (node == node->parent->rightChild) {
					tmp->parent->rightChild = tmp;
				}
				else {
					tmp->parent->leftChild = tmp;
				}
				tmp->rightChild = node;
				node->parent = tmp;
			}
		}

		void	leftRotation(Node<K, V> *node) {
			Node<K, V> *tmp = node->rightChild;

			node->rightChild = tmp->leftChild;
			if (node->rightChild != nullptr) {
				node->rightChild->parent = node;
			}
			if (node->parent == nullptr) {
				this->root = tmp;
				tmp->parent = nullptr;
			}
			else {
				tmp->parent = node->parent;
				if (node == node->parent->leftChild) {
					tmp->parent->leftChild = tmp;
				}
				else {
					tmp->parent->rightChild = tmp;
				}
				tmp->leftChild = node;
				node->parent = tmp;
			}
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
				return this->maximum(tmp->leftChild);
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
		void	printRBT() {
			Node<K, V>	*min = minimum(this->root);
			while (min != nullptr) {
				std::cout << "data( " << min->data.first << ", " << min->data.second << "), color: " << (min->red ? "red" : "black") << ", parent: " << min->parent << "\n";
				min = successor(min);
			}
			std::cout << "\n";
			min = maximum(this->root);
			while (min != nullptr) {
				std::cout << "data( " << min->data.first << ", " << min->data.second << "), color: " << (min->red ? "red" : "black") << ", parent: " << min->parent << "\n";
				min = predecessor(min);
			}
		}



		////////////////////////////////////////////////

		void	correctViolation(Node<K, V> *node) {
			if (node == node->parent->leftChild) {
				if (node->parent->parent->rightChild == nullptr || node->parent->parent->rightChild->red == false) {

				}
			}
		}

		void	checkColor(Node<K, V> *node) {
			if (node == this->root)
				return;
			if (node->red == true && node->parent->red == true) {
				correctViolation(node);
			}
			checkColor(node->parent);
		}

		void	insertNewNode(Node<K, V> *parent, Node<K, V> *node) {
			if (comp(parent->data.first, node->data.first) > 0) {
				if (parent->rightChild == nullptr) {
					parent->rightChild = node;
					node->parent = parent;
				}
				return insertNewNode(parent->rightChild, node);
			}
			if (parent->leftChild == nullptr) {
				parent->leftChild = node;
				node->parent = parent;
			}
			return insertNewNode(parent->leftChild, node);
			checkColor(node);
		}

		void	insertNODE(Node<K, V> *node) {
			if (this->root == nullptr) {
				this->root = node;
				this->root->red = false;
			}
			else {
				insertNewNode(this->root, node);
			}
		}
};

#endif