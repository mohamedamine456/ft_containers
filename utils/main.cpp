#include "redBlackTree.hpp"

#include <iostream>
#include <memory>

int main() {
    RedBlackTree<int, int>  rbt;
    Node<int, int>          *node;
    Node<int, int>          *node2;
    std::allocator<Node<int , int> > alloc;
    node = alloc.allocate(1);
    node2 = alloc.allocate(1);
    node->data = ft::make_pair(5, 3);
    node->red = true;
    node->parent = nullptr;
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    node2->data = ft::make_pair(9, 45);
    node2->red = true;
    node2->parent = nullptr;
    node2->leftChild = nullptr;
    node2->rightChild = nullptr;
    rbt.insertNode(node);
    rbt.insertNode(node2);
    rbt.deleteNode(node2);
}