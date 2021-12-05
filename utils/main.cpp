#include "redBlackTree.hpp"

#include <iostream>
#include <memory>

int main() {
    RedBlackTree<int, int>         rbt;
    Node<const int, int>          *nodes[25];
    Node<const int, int>          *tmpNode;
    std::allocator<Node<int , int> > alloc;
    // for (int i = 0; i < 25; i ++) {
    //     nodes[i] = rbt.newNode((i + 1) * 13, (i + 1)* 37);
    // }
    // for (int i = 0; i < 25; i++) {
    //     // if (rbt.insertNode(nodes[i]) == false) {
    //         // std::cout << "Key:" << nodes[i]->data->first << " already exists.\n";
    //         // break;
    //     // }
    //     std::cout << "[" << nodes[i]->data->first << ", " << nodes[i]->data->second << "], (" << (nodes[i]->red ? "RED" : "BLACK") << ")\n";
    // }
    // tmpNode = rbt.newNode(13, 75);
    // if (rbt.insertNode(tmpNode) == false) {
    //     std::cout << "Key:" << tmpNode->data->first << " already exists.\n";
    // }
    // // for (Node<int ,int> *min = rbt.minimum(rbt.getRoot()); min != rbt.maximum(rbt.getRoot()); min = rbt.successor(min)) {
    // //     std::cout << "[" << min->data.first << ", " << min->data.second << "], (" << (min->red ? "RED" : "BLACK") << ")\n";
    // // }
    // rbt.printRBT(rbt.getRoot(), "", true);
    // rbt.deleteNode(nodes[7]);
    // rbt.deleteNode(nodes[12]);
    // rbt.deleteNode(nodes[17]);
    // rbt.deleteNode(nodes[22]);
    // rbt.printRBT(rbt.getRoot(), "", true);
    // std::cout << "---------------------------\n\n";
    // for (Node<int ,int> *min = rbt.minimum(rbt.getRoot()); min != rbt.maximum(rbt.getRoot()); min = rbt.successor(min)) {
    //     std::cout << "[" << min->data.first << ", " << min->data.second << "], (" << (min->red ? "RED" : "BLACK") << ")\n";
    // }

    Node<const int, int> *n1 = rbt.newNode(55, 10);
    Node<const int, int> *n2 = rbt.newNode(40, 10);
    Node<const int, int> *n3 = rbt.newNode(65, 10);
    Node<const int, int> *n4 = rbt.newNode(60, 10);
    Node<const int, int> *n5 = rbt.newNode(75, 10);
    Node<const int, int> *n6 = rbt.newNode(57, 10);
    Node<const int, int> *n7 = rbt.newNode(58, 10);

    rbt.insertNode(n1);
    rbt.insertNode(n2);
    rbt.insertNode(n3);
    rbt.insertNode(n4);
    rbt.insertNode(n5);
    rbt.insertNode(n6);
    rbt.insertNode(n7);
    rbt.printRBT(rbt.getRoot(), "", true);

    std::cout << "---------------------------\n\n";
    rbt.deleteNode(n7);
    rbt.printRBT(rbt.getRoot(), "", true);

    std::cout << "---------------------------\n\n";
    rbt.deleteNode(n3);
    rbt.printRBT(rbt.getRoot(), "", true);

    std::cout << "Finished.\n";
    // system("leaks a.out");
}