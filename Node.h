/**
 * @file Node.h
 * @author Tristan Riley
 * @date 2023-11-27
 * @brief 
 */

#include <string>
#include <iomanip>
#ifndef NODE_H
#define NODE_H

class Node {
private:
    Node *left, *right;
    std::string key;
    int data;
    
public:
    Node(std::string key);
    friend class BST;
};
#endif //NODE_H