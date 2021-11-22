#include "redBlackTree.hpp"

#include <iostream>
#include <memory>

int main() {
    RedBlackTree<int, int>  rbt;
    Node<int, int>          *nodes[25];
    Node<int, int>          *tmpNode;
    std::allocator<Node<int , int> > alloc;
    for (int i = 0; i < 25; i ++) {
        nodes[i] = rbt.newNode((i + 1) * 13, (i + 1)* 37);
    }
    for (int i = 0; i < 25; i++) {
        if (rbt.insertNode(nodes[i]) == false) {
            std::cout << "Key:" << nodes[i]->data.first << " already exists.\n";
            break;
        }
    }
    tmpNode = rbt.newNode(13, 75);
    if (rbt.insertNode(tmpNode) == false) {
        std::cout << "Key:" << tmpNode->data.first << " already exists.\n";
    }
    for (Node<int ,int> *min = rbt.minimum(rbt.getRoot()); min != rbt.maximum(rbt.getRoot()); min = rbt.successor(min)) {
        std::cout << "[" << min->data.first << ", " << min->data.second << "], (" << (min->red ? "RED" : "BLACK") << ")\n";
    }
    // rbt.printRBT(rbt.getRoot(), "", true);
    rbt.deleteNode(nodes[7]);
    rbt.deleteNode(nodes[12]);
    rbt.deleteNode(nodes[17]);
    rbt.deleteNode(nodes[22]);
    // rbt.printRBT(rbt.getRoot(), "", true);
    std::cout << "---------------------------\n\n";
    for (Node<int ,int> *min = rbt.minimum(rbt.getRoot()); min != rbt.maximum(rbt.getRoot()); min = rbt.successor(min)) {
        std::cout << "[" << min->data.first << ", " << min->data.second << "], (" << (min->red ? "RED" : "BLACK") << ")\n";
    }
    std::cout << "Finished.\n";
}