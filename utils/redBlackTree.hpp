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
		Node<K, V>	*root;
		Node<K, V>	*nullNode;
		Compare		comp;

    public:
        RedBlackTree() {
			nullNode = __alloc.allocate(1);
			nullNode->parent = nullptr;
			nullNode->leftChild = nullptr;
			nullNode->rightChild = nullptr;
			nullNode->red = false;
			this->root = nullNode;
			size = 0;
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

		Node<K, V>	*newNode(K key, V value) {
			Node<K, V>	*node;
			node = __alloc.allocate(1);
			node->data = ft::make_pair(key, value);
			node->red = true;
			node->parent = nullptr;
			node->leftChild = this->nullNode;
			node->rightChild = this->nullNode;
			return (node);
		}

		void	fixInsert(Node<K, V> *node) {
			Node<K, V>	*tmp;

			if (node == this->root) {
				this->root->red = false;
				return;
			}
			while (node->parent != nullptr && node->parent->red == true) {
				if (node->parent == node->parent->parent->rightChild) {
					tmp = node->parent->parent->leftChild;
					if (tmp->red == true) {
						tmp->red = false;
						node->parent->red = false;
						node->parent->parent->red = true;
						node = node->parent->parent;
					} else {
						if (node == node->parent->leftChild) {
							node = node->parent;
							rightRotation(node);
						}
						node->parent->red = false;
						node->parent->parent->red = true;
						leftRotation(node->parent->parent);
					}
				} else {
					tmp = node->parent->parent->rightChild;
					if (tmp->red == true) {
						tmp->red = false;
						node->parent->red = false;
						node->parent->parent->red = true;
						node = node->parent->parent;
					} else {
						if (node == node->parent->rightChild) {
							node = node->parent;
							leftRotation(node);
						}
						node->parent->red = false;
						node->parent->parent->red = true;
						rightRotation(node->parent->parent);
					}
				}
			}
			this->root->red = false;
		}
		
        void    insertNode(Node<K, V> *node) {
			Node<K, V>	*tmpRoot = this->root;
			Node<K, V>	*tmp = nullptr;

			while (tmpRoot != nullNode) {
				tmp = tmpRoot;
				if (node->data.first < tmpRoot->data.first) {
					tmpRoot = tmpRoot->leftChild;
				} else {
					tmpRoot = tmpRoot->rightChild;
				}
			}

			node->parent = tmp;
			if (tmp == nullptr) {
				this->root = node;
			} else if (node->data.first < tmp->data.first) {
				tmp->leftChild = node;
			} else {
				tmp->rightChild = node;
			}

			if (node->parent == nullptr) {
				node->red = false;
				return ;
			}
			if (node->parent->parent == nullptr)
			return ;

			fixInsert(node);
		}

		void	deleteFix(Node<K, V> *node) {
			Node<K, V>	*tmpS;

			while (node != root && node->red == false) {
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
						tmpS->rightChild->red = false;
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
					if (tmpS->rightChild->red == false && tmpS->rightChild->red == false) {
						tmpS->red = true;
						node = node->parent;
					} else {
						if (tmpS->leftChild->red == false) {
							tmpS->rightChild->red = false;
							tmpS->red = true;
							leftRotation(tmpS);
							tmpS = node->parent->leftChild;
						}
						tmpS->red = node->parent->red;
						node->parent->red = false;
						tmpS->leftChild->red = false;
						rightRotation(node->parent);
						node = this->root;
					}
				}
			}
			node->red = false;
		}

		void	deleteHelper(Node<K, V> *a, Node<K, V> *b) {
			if (a->parent == nullptr) {
				this->root = b;
			} else if (a == a->parent->leftChild) {
				a->parent->leftChild = b;
			} else {
				a->parent->rightChild = b;
			}
			b->parent = a->parent;
		}

        void    deleteNode(Node<K, V> *node) {
			Node<K, V>	*tmpNode = this->root;
			Node<K, V>	*tmp1 = nullNode;
			Node<K, V>	*tmp2 = nullNode;
			Node<K, V>	*tmp3 = nullNode;

			while (tmpNode != nullNode) {
				if (tmpNode->data.first == node->data.first) {
					tmp1 = tmpNode;
				}
				if (tmpNode->data.first <= node->data.first) {
					tmpNode = tmpNode->rightChild;
				} else {
					tmpNode = tmpNode->leftChild;
				}
			}

			if (tmp1 == nullNode) {
				return;
			}
			tmp2 = tmp1;
			bool color = tmp2->red;

			if (tmp1->left == nullNode) {
				tmp3 = tmp1->rightChild;
				deleteHelper(tmp1, tmp1->rightChild);
			} else if (tmp1->rightChild == nullNode) {
				tmp3 = tmp1->leftChild;
				deleteHelper(tmp1, tmp1->leftChild);
			} else {
				tmp2 = minimum(tmp1->right);
				color = tmp2->red;
				tmp3 = tmp2->rightChild;
				if (tmp2->parent == tmp1) {
					tmp3->parent = tmp2;
				} else {
					deleteHelper(tmp2, tmp2->rightChild);
					tmp2->rightChild = tmp1->rightChild;
					tmp2->rightChild->parent = tmp2;
				}
				deleteHelper(tmp1, tmp2);
				tmp2->leftChild = tmp1->leftChild;
				tmp2->leftChild->parent = tmp2;
				tmp2->red = tmp1->red;
			}
			__alloc.destroy(tmp1);
			__alloc.deallocate(tmp1, 1);
			tmp1 = nullptr;
			if (color == false) {
				deleteFix(tmp3);
			}
        }

        void    deleteNode(K key) {
			BSTDelete(this->root, key);
        }

		void	rightRotation(Node<K, V> *node) {
			Node<K, V> *tmp = node->leftChild;

			node->leftChild = tmp->rightChild;
			if (node->leftChild != nullNode) {
				tmp->rightChild->parent = node;
			}
			tmp->parent = node->parent;
			if (node->parent == nullptr) {
				this->root = node;
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
			if (tmp->leftChild != nullNode) {
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
			if (tmp->rightChild != nullNode)
				return this->minimum(tmp->rightChild);
			tmp1 = tmp->parent;
			while (tmp1 != nullptr && tmp1 != nullNode && tmp == tmp1->rightChild)
			{
				tmp = tmp1;
				tmp1 = tmp1->parent;
			}
			return tmp1;
        }

        Node<K, V>	*predecessor(Node<K, V> *node) {
			Node<K, V>	*tmp = node;
			Node<K, V>	*tmp1;
			if (tmp->leftChild != nullNode)
				return this->maximum(tmp->leftChild);
			tmp1 = tmp->parent;
			while (tmp1 != nullptr && tmp1 != nullNode && tmp == tmp1->leftChild)
			{
				tmp = tmp1;
				tmp1 = tmp1->parent;
			}
			return tmp1;
        }

        Node<K, V>	*search(Node<K, V> *node, K key) {
			Node<K, V>	*tmp = node;
			while (tmp != nullNode)
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
			while (tmp->leftChild != nullNode)
				tmp = tmp->leftChild;
			return tmp;
        }

        Node<K, V>	*maximum(Node<K, V> *node) {
			Node<K, V>	*tmp = node;
			while (tmp->rightChild != nullNode)
				tmp = tmp->rightChild;
			return tmp;
        }

		void	printRBT(Node<K, V> *node, std::string pre, bool last) {
			if (node != this->nullNode) {
				std::cout << pre;
				if (last) {
					std::cout << "Right:----: ";
					pre += "\t";
				} else {
					std::cout << "Left:-----: ";
					pre += "|\t";
				}

				std::string color = node->red ? "RED" : "BLACK";
				std::cout << "[" << node->data.first << ", " << node->data.second << "], (" << color << ")\n";
				printRBT(node->leftChild, pre, false);
				printRBT(node->rightChild, pre, true);
	    	}
		}
};

#endif