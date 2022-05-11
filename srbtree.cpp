#include "utils/setRedBlackTree.hpp"

#include <iostream>
#include <memory>

int main() {
    SetRedBlackTree<int>    rbt;
    SetNode<const int>      *nodes[25];
    SetNode<const int>      *tmpNode;
    std::allocator<SetNode< const int> > alloc;
    for (int i = 0; i < 25; i ++) {
        nodes[i] = rbt.newNode((i + 1) * 13);
    }
    for (int i = 0; i < 25; i++) {
        if (rbt.insertNode(nodes[i]) == false) {
            std::cout << "Key:" << nodes[i]->data << " already exists.\n";
            break;
        }
    }
    tmpNode = rbt.newNode(13);
    if (rbt.insertNode(tmpNode) == false) {
        std::cout << "Key:" << tmpNode->data << " already exists.\n";
    }
    // std::cout << "---------------------------\n\n";
    // for (SetNode<const int> *min = rbt.minimum(rbt.getRoot()); min != rbt.maximum(rbt.getRoot()); min = rbt.successor(min)) {
    //     std::cout << "[" << *(min->data) << "], (" << (min->red ? "RED" : "BLACK") << ")\n";
    // }
    // std::cout << "[" << *(rbt.maximum(rbt.getRoot())->data) << "], (" << (rbt.maximum(rbt.getRoot())->red ? "RED" : "BLACK") << ")\n";
    rbt.printRBT(rbt.getRoot(), "", true);
    rbt.deleteNode(nodes[7]);
    rbt.deleteNode(nodes[12]);
    rbt.deleteNode(nodes[17]);
    rbt.deleteNode(nodes[22]);
    rbt.printRBT(rbt.getRoot(), "", true);
    // std::cout << "---------------------------\n\n";
    // for (SetNode<const int> *min = rbt.minimum(rbt.getRoot()); min != rbt.maximum(rbt.getRoot()); min = rbt.successor(min)) {
    //     std::cout << "[" << *(min->data) << "], (" << (min->red ? "RED" : "BLACK") << ")\n";
    // }
    // std::cout << "[" << *(rbt.maximum(rbt.getRoot())->data) << "], (" << (rbt.maximum(rbt.getRoot())->red ? "RED" : "BLACK") << ")\n";
    std::cout << "Finished.\n";
}