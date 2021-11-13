#include "redBlackTree.hpp"

#include <iostream>
#include <memory>

int main() {
    RedBlackTree<int, int>  rbt;
    Node<int, int>          *node;
    std::allocator<Node<int , int> > alloc;
    node = alloc.allocate(1);
    node->data = ft::make_pair(5, 3);
    node->red = true;
    node->parent = nullptr;
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    rbt.insertNode(node);
}