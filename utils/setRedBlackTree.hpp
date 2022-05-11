#ifndef SETREDBLACKTREE_HPP
#define SETREDBLACKTREE_HPP

#include "../namespace.hpp"

template < class T >
struct SetNode
{
	bool					empty;
	bool					red;
	T						*data;
	SetNode<T>				*leftChild;
	SetNode<T>				*rightChild;
	SetNode<T>				*parent;
};

template < class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class SetRedBlackTree {
	private:
		typedef typename Allocator::template rebind<SetNode<T> >::other	Node_Allocator;
		Allocator			__data_alloc;
		Node_Allocator		__alloc;
		size_t				__size;
		Compare				__comp;
		SetNode<T>			*root;
		SetNode<T>			*nullNode;

		// fix violation if node is right child node (insert)
		void	rightChildFixInsert(SetNode<T>	**node, SetNode<T> **tmp) {
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
		void	leftChildFixInsert(SetNode<T>	**node, SetNode<T> **tmp) {
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
		void	fixInsert(SetNode<T> *node) {
			SetNode<T>	*tmp;

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
		void	leftChildFixDelete(SetNode<T> **node, SetNode<T> **tmpS){
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
		void	rightChildFixDelete(SetNode<T>	**node, SetNode<T> **tmpS) {
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
		void	deleteFix(SetNode<T> *node) {
			SetNode<T>	*tmpS;

			while (node != root && node->red == false) {
				if (node == node->parent->leftChild) {
					leftChildFixDelete(&node, &tmpS);
				} else {
					rightChildFixDelete(&node, &tmpS);
				}
			}
			node->red = false;
		}

		void	deleteHelper(SetNode<T> *a, SetNode<T> *b) {
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
		void	rightRotation(SetNode<T> *node) {
			SetNode<T> *tmp = node->leftChild;

			node->leftChild = tmp->rightChild;
			if (node->leftChild != nullNode) {
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

		// bst left rotation on a node
		void	leftRotation(SetNode<T> *node) {
			SetNode<T> *tmp = node->rightChild;

			node->rightChild = tmp->leftChild;
			if (tmp->rightChild != nullNode) {
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
		SetRedBlackTree() {
			nullNode = __alloc.allocate(1);
			nullNode->empty = true;
			nullNode->parent = nullptr;
			nullNode->leftChild = nullptr;
			nullNode->rightChild = nullptr;
			nullNode->red = false;
			nullNode->data = __data_alloc.allocate(1);
			this->root = nullNode;
			__size = 0;
		}

		SetRedBlackTree(const SetRedBlackTree &rbt) {
			*this = rbt;
		}

		~SetRedBlackTree() {}

		SetRedBlackTree &operator= (SetRedBlackTree const &rbt) {
			this->root = rbt.root;
			this->__size = rbt.__size;
			this->nullNode = rbt.nullNode;
			this->__alloc = rbt.__alloc;
			this->__data_alloc = rbt.__data_alloc;
			this->__comp = rbt.__comp;
			return *this;
		}

		SetNode<T> *getRoot() const {
			return this->root;
		}

		SetNode<T> *getNullNode() const {
			return this->nullNode;
		}

		SetNode<T>	*newNode(const T key) {
			SetNode<T>	*node;
			node = __alloc.allocate(1);
			node->data = __data_alloc.allocate(1);
			const T	__data(key);
			__data_alloc.construct(node->data, __data);
			node->empty = false;
			node->red = true;
			node->parent = nullptr;
			node->leftChild = this->nullNode;
			node->rightChild = this->nullNode;
			return (node);
		}
		
		bool	insertNode(SetNode<T> *node) {
			SetNode<T>	*tmpRoot = this->root;
			SetNode<T>	*tmp = nullptr;

			// where to insert
			while (tmpRoot != nullNode) {
				tmp = tmpRoot;
				if (*(node->data) == *(tmpRoot->data))
					return false;
				else if (__comp(*(node->data), *(tmpRoot->data))) {
					tmpRoot = tmpRoot->leftChild;
				} else {
					tmpRoot = tmpRoot->rightChild;
				}
			}

			// insert
			node->parent = tmp;
			if (tmp == nullptr) {
				this->root = node;
			} else if (__comp(*(node->data), *(tmp->data))) {
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

		void    deleteNode(SetNode<T> *node) {
			SetNode<T>	*tmpNode = this->root;
			SetNode<T>	*tmp1 = nullNode;
			SetNode<T>	*tmp2 = nullNode;
			SetNode<T>	*tmp3 = nullNode;

			while (tmpNode != nullNode) {
				if (*(tmpNode->data) == *(node->data)) {
					tmp1 = tmpNode;
				}
				if (__comp(*(tmpNode->data), *(node->data))) {
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
			__data_alloc.destroy(tmp1->data);
			__data_alloc.deallocate(tmp1->data, 1);
			__alloc.destroy(tmp1);
			__alloc.deallocate(tmp1, 1);
			tmp1 = nullNode;
			if (color == false) {
				deleteFix(tmp3);
				__size--;
			}
		}

		void    deleteNode(const T key) {
			SetNode<T>	*node = searchNode(this->root, key);
			deleteNode(node);
		}

		SetNode<T>	*successor(SetNode<T> *node) const {
			SetNode<T>	*tmp = node;
			SetNode<T>	*tmp1;
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

		SetNode<T>	*predecessor(SetNode<T> *node) const {
			SetNode<T>	*tmp = node;
			SetNode<T>	*tmp1;
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

		SetNode<T>	*searchNode(SetNode<T> *node, const T key) const {
			SetNode<T>	*tmp = node;
			while (tmp != nullNode)
			{
				if (*(tmp->data) == key)
					break ;
				else if (__comp(key, *(tmp->data)))
					tmp = tmp->leftChild;
				else
					tmp = tmp->rightChild;
			}
			return tmp;
		}

		SetNode<T>	*minimum(SetNode<T> *node) const {
			SetNode<T>	*tmp = node;
			while (tmp->leftChild != nullptr && tmp->leftChild != nullNode)
				tmp = tmp->leftChild;
			return tmp;
		}

		SetNode<T>	*maximum(SetNode<T> *node) const {
			SetNode<T>	*tmp = node;
			while (tmp->rightChild != nullptr && tmp->rightChild != nullNode)
				tmp = tmp->rightChild;
			return tmp;
		}

		void				deallocate(SetNode<T> *node) {
			__data_alloc.deallocate(node->data, 1);
		}

		void	printRBT(SetNode<T > *node, std::string pre, bool last) const {
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
				std::cout << "[" << *(node->data) << ", " << *(node->data) << "], (" << color << "), " /*<< (node->empty ? "EMPTY" : "FULL")*/ << "\n";
				printRBT(node->leftChild, pre, false);
				printRBT(node->rightChild, pre, true);
			}
		}
};

#endif