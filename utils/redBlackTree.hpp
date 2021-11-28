#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "pair.hpp"

template < class K, class V >
struct Node
{
	bool					empty;
	bool					red;
	ft::pair<K, V>			*data;
	Node<const K, V>		*leftChild;
	Node<const K, V>		*rightChild;
	Node<const K, V>		*parent;
};

template < class K, class V, class Compare = std::less<K>, class Allocator = std::allocator<ft::pair <const K, V> > >
class RedBlackTree {
    private:
		typedef typename Allocator::template rebind<Node<const K, V> >::other	Node_Allocator;
		Allocator			__pair_alloc;
		Node_Allocator		__alloc;
		size_t				__size;
		Compare				comp;
		Node<const K, V>	*root;
		Node<const K, V>	*nullNode;

		// fix violation if node is right child node (insert)
		void	rightChildFixInsert(Node<const K, V>	**node, Node<const K, V> **tmp) {
			*tmp = (*node)->parent->parent->leftChild;
			if ((*tmp)->red == true) {
				(*tmp)->red = false;
				(*node)->parent->red = false;
				(*node)->parent->parent->red = true;
				(*node) = (*node)->parent->parent;
			} else {
				// node is left child (line)
				if ((*node) == (*node)->parent->leftChild) {
					(*node) = (*node)->parent;
					rightRotation((*node));
				}
				(*node)->parent->red = false;
				(*node)->parent->parent->red = true;
				leftRotation((*node)->parent->parent);
			}
		}

		// fix violation if node is left child node (insert)
		void	leftChildFixInsert(Node<const K, V>	**node, Node<const K, V> **tmp) {
			(*tmp) = (*node)->parent->parent->rightChild;
			if ((*tmp)->red == true) {
				(*tmp)->red = false;
				(*node)->parent->red = false;
				(*node)->parent->parent->red = true;
				(*node) = (*node)->parent->parent;
			} else {
				// node is right child (line)
				if ((*node) == (*node)->parent->rightChild) {
					(*node) = (*node)->parent;
					leftRotation((*node));
				}
				(*node)->parent->red = false;
				(*node)->parent->parent->red = true;
				rightRotation((*node)->parent->parent);
			}
		}
		// private function to fix rbt properties violation in the insert of new node
		void	fixInsert(Node<const K, V> *node) {
			Node<const K, V>	*tmp;

			if (node == this->root) {
				this->root->red = false;
				return;
			}
			while (node->parent != nullptr && node->parent->red == true) {
				// parent is right child
				if (node->parent == node->parent->parent->rightChild) {
					rightChildFixInsert(&node, &tmp);
				}
				// parent is left child 
				else {
					leftChildFixInsert(&node, &tmp);
				}
			}
			this->root->red = false;
		}

		// fix violation if node is left child node (delete)
		void	leftChildFixDelete(Node<const K, V>	**node, Node<const K, V> **tmpS){
			(*tmpS) = (*node)->parent->rightChild;
			if ((*tmpS)->red == true) {
				(*tmpS)->red = false;
				(*node)->parent->red = true;
				leftRotation((*node)->parent);
				(*tmpS) = (*node)->parent->rightChild;
			}
			if ((*tmpS)->leftChild->red == false && (*tmpS)->rightChild->red == false) {
				(*tmpS)->red = true;
				(*node) = (*node)->parent;
			} else {
				if ((*tmpS)->rightChild->red == false) {
					(*tmpS)->leftChild->red = false;
					(*tmpS)->red = true;
					rightRotation((*tmpS));
					(*tmpS) = (*node)->parent->rightChild;
				}

				(*tmpS)->red = (*node)->parent->red;
				(*node)->parent->red = false;
				(*tmpS)->rightChild->red = false;
				leftRotation((*node)->parent);
				(*node) = this->root;
			}
		}

		// fix violation if node is right child node (delete)
		void	rightChildFixDelete(Node<const K, V>	**node, Node<const K, V> **tmpS) {
			(*tmpS) = (*node)->parent->leftChild;
			if ((*tmpS)->red == true) {
				(*tmpS)->red = false;
				(*node)->parent->red = true;
				rightRotation((*node)->parent);
				(*tmpS) = (*node)->parent->leftChild;
			}
			if ((*tmpS)->rightChild->red == false && (*tmpS)->rightChild->red == false) {
				(*tmpS)->red = true;
				(*node) = (*node)->parent;
			} else {
				if ((*tmpS)->leftChild->red == false) {
					(*tmpS)->rightChild->red = false;
					(*tmpS)->red = true;
					leftRotation((*tmpS));
					(*tmpS) = (*node)->parent->leftChild;
				}
				(*tmpS)->red = (*node)->parent->red;
				(*node)->parent->red = false;
				(*tmpS)->leftChild->red = false;
				rightRotation((*node)->parent);
				(*node) = this->root;
			}
		}

		// private function to fix rbt properties violation in the delete of a node
		void	deleteFix(Node<const K, V> *node) {
			Node<const K, V>	*tmpS;

			while (node != root && node->red == false) {
				if (node == node->parent->leftChild) {
					leftChildFixDelete(&node, &tmpS);
				} else {
					rightChildFixDelete(&node, &tmpS);
				}
			}
			node->red = false;
		}

		void	deleteHelper(Node<const K, V> *a, Node<const K, V> *b) {
			if (a->parent == nullptr) {
				this->root = b;
			} else if (a == a->parent->leftChild) {
				a->parent->leftChild = b;
			} else {
				a->parent->rightChild = b;
			}
			b->parent = a->parent;
		}

		// bst right rotation on a node
		void	rightRotation(Node<const K, V> *node) {
			Node<const K, V> *tmp = node->leftChild;

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

		// bst left rotation on a node
		void	leftRotation(Node<const K, V> *node) {
			Node<const K, V> *tmp = node->rightChild;

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
	
	public:
        RedBlackTree() {
			nullNode = __alloc.allocate(1);
			nullNode->empty = true;
			nullNode->parent = nullptr;
			nullNode->leftChild = nullptr;
			nullNode->rightChild = nullptr;
			nullNode->red = false;
			nullNode->data = nullptr;
			this->root = nullNode;
			__size = 0;
        }

        RedBlackTree(RedBlackTree &rbt) {
            *this = rbt;
        }

        ~RedBlackTree() {}

        RedBlackTree &operator= (RedBlackTree const &rbt) {
			this->root = rbt.root;
			this->__size = rbt.__size;
			this->nullNode = rbt.nullNode;
			this->__alloc = rbt.__alloc;
            return *this;
        }

		Node<const K, V> *getRoot() const {
			return this->root;
		}

		Node<const K, V> *getNullNode() const {
			return this->nullNode;
		}

		Node<const K, V>	*newNode(const K key, V value) {
			Node<const K, V>	*node;
			node = __alloc.allocate(1);
			node->data = __pair_alloc.allocate(1);
			ft::pair<const K, V>	__data(key, value);
			__pair_alloc.construct(node->data, __data);
			node->empty = false;
			node->red = true;
			node->parent = nullptr;
			node->leftChild = this->nullNode;
			node->rightChild = this->nullNode;
			return (node);
		}
		
        bool	insertNode(Node<const K, V> *node) {
			Node<const K, V>	*tmpRoot = this->root;
			Node<const K, V>	*tmp = nullptr;

			// where to insert
			while (tmpRoot != nullNode) {
				tmp = tmpRoot;
				if (node->data->first == tmpRoot->data->first)
					return false;
				else if (comp(node->data->first, tmpRoot->data->first)) {
					tmpRoot = tmpRoot->leftChild;
				} else {
					tmpRoot = tmpRoot->rightChild;
				}
			}

			// insert
			node->parent = tmp;
			if (tmp == nullptr) {
				this->root = node;
			} else if (comp(node->data->first, tmp->data->first)) {
				tmp->leftChild = node;
			} else {
				tmp->rightChild = node;
			}

			__size++;
			// fix properties for simple
			if (node->parent == nullptr) {
				node->red = false;
				return true;
			}
			if (node->parent->parent == nullptr)
				return true;

			// fix properties for complex
			fixInsert(node);
			return true;
		}

        void    deleteNode(Node<const K, V> *node) {
			Node<const K, V>	*tmpNode = this->root;
			Node<const K, V>	*tmp1 = nullNode;
			Node<const K, V>	*tmp2 = nullNode;
			Node<const K, V>	*tmp3 = nullNode;

			while (tmpNode != nullNode) {
				if (tmpNode->data->first == node->data->first) {
					tmp1 = tmpNode;
				}
				if (comp(tmpNode->data->first, node->data->first)) {
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

			if (tmp1->leftChild == nullNode) {
				tmp3 = tmp1->rightChild;
				deleteHelper(tmp1, tmp1->rightChild);
			} else if (tmp1->rightChild == nullNode) {
				tmp3 = tmp1->leftChild;
				deleteHelper(tmp1, tmp1->leftChild);
			} else {
				tmp2 = minimum(tmp1->rightChild);
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
			tmp1 = nullNode;
			if (color == false) {
				deleteFix(tmp3);
				__size--;
			}
        }

        void    deleteNode(const K key) {
			Node<const K, V>	*node = searchNode(this->root, key);
			deleteNode(node);
        }

        Node<const K, V>	*successor(Node<K, V> *node) const {
			Node<const K, V>	*tmp = node;
			Node<const K, V>	*tmp1;
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

        Node<const K, V>	*predecessor(Node<const K, V> *node) const {
			Node<const K, V>	*tmp = node;
			Node<const K, V>	*tmp1;
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

		template<class T, class U>
        Node<const T, U>	*searchNode(Node<const T, U> *node, const K key) const {
			Node<const T, U>	*tmp = node;
			while (tmp != nullNode)
			{
				if (tmp->data->first == key)
					break ;
				else if (tmp->data->first > key)
					tmp = tmp->leftChild;
				else
					tmp = tmp->rightChild;
			}
			return tmp;
        }

        Node<const K, V>	*minimum(Node<const K, V> *node) const {
			Node<const K, V>	*tmp = node;
			while (tmp->leftChild != nullptr && tmp->leftChild != nullNode)
				tmp = tmp->leftChild;
			return tmp;
        }

        Node<const K, V>	*maximum(Node<const K, V> *node) const {
			Node<const K, V>	*tmp = node;
			while (tmp->rightChild != nullptr && tmp->rightChild != nullNode)
				tmp = tmp->rightChild;
			return tmp;
        }

		void	printRBT(Node<const K, V> *node, std::string pre, bool last) const {
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
				std::cout << "[" << node->data->first << ", " << node->data->second << "], (" << color << "), " /*<< (node->empty ? "EMPTY" : "FULL")*/ << "\n";
				printRBT(node->leftChild, pre, false);
				printRBT(node->rightChild, pre, true);
	    	}
		}
};

#endif