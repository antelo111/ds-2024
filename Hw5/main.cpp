#include <iostream>
#include "BST.h"

int main()
{
     BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    bst.remove(18);
     bst.printTree();//测试删除叶子节点
    std::cout<<std::endl<<"--------------------------------"<<std::endl;
    bst.insert(18);
    bst.remove(15);
    bst.printTree();//测试删除孩子为叶子节点的中间节点
    std::cout<<std::endl<<"--------------------------------"<<std::endl;
    bst.insert(15);
    bst.remove(10);
    bst.printTree();//测试删除根节点
    return 0;
}