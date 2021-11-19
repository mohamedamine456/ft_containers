#include "redBlackTree.hpp"

#include <iostream>
#include <memory>

int main() {
    RedBlackTree<int, int>  rbt;
    Node<int, int>          *nodes[25];
    std::allocator<Node<int , int> > alloc;
    for (int i = 0; i < 25; i ++) {
        nodes[i] = rbt.newNode((i + 1) * 13, (i + 1)* 37);
    }
    for (int i = 0; i < 25; i++) {
        rbt.insertNode(nodes[i]);
    }
    rbt.printRBT(rbt.getRoot(), "", true);
    rbt.deleteNode(nodes[7]);
    rbt.deleteNode(nodes[12]);
    rbt.deleteNode(nodes[17]);
    rbt.deleteNode(nodes[22]);
    rbt.printRBT(rbt.getRoot(), "", true);
    std::cout << "Finished.\n";
}