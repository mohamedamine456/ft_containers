#include "redBlackTree.hpp"

#include <iostream>
#include <memory>

int main() {
    RedBlackTree<int, int>  rbt;
    Node<int, int>          *nodes[15];
    std::allocator<Node<int , int> > alloc;
    for (int i = 0; i < 15; i ++) {
        nodes[i] = alloc.allocate(1);
        nodes[i]->data = ft::make_pair((i + 1) * 13, (i + 1) * 37);
        nodes[i]->red = true;
        nodes[i]->parent = nullptr;
        nodes[i]->leftChild = nullptr;
        nodes[i]->rightChild = nullptr;
    }
    for (int i = 0; i < 15; i++) {
        rbt.insertNode(nodes[i]);
    }
    rbt.printRBT();
    // std::cout << "data( " << rbt.getRoot()->leftChild->leftChild->leftChild->leftChild->leftChild->data.first << ", " << rbt.getRoot()->leftChild->leftChild->leftChild->leftChild->leftChild->data.second << "), color: " << (rbt.getRoot()->leftChild->leftChild->leftChild->leftChild->leftChild->red ? "red" : "black") << ", parent: " << rbt.getRoot()->leftChild->leftChild->leftChild->leftChild->leftChild << "\n";
    // Node<int, int>          *min;
    // min = rbt.minimum(rbt.getRoot());
    // std::cout << "Minimum: data( " << min->data.first << ", " << min->data.second << ")\n"; 
    // Node<int, int>          *max;
    // max = rbt.maximum(rbt.getRoot());
    // std::cout << "Maximum: data( " << max->data.first << ", " << max->data.second << ")\n"; 
    std::cout << "Finished.\n";
}