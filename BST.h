/**
 * @file BST.h
 * @author Tristan Riley
 * @date 2023-11-27
 * @brief 
 */

#include "Node.h"
#include <fstream>
#include <string>

#ifndef BST_H
#define BST_H

class BST {
private:
    Node *root;

    void destroyTree(Node *leaf);
    Node* insert(Node *leaf, std::string key, int data);
    Node* find(Node *leaf, std::string key);
    void printInOrder(Node *leaf);
    Node* findMin(Node *leaf);
    Node* findMax(Node *leaf);
    Node* deleteNode(Node *leaf, std::string key);
    void saveToFile(Node *leaf, std::ofstream &file);

public:
    BST();
    ~BST();

    void set(std::string key, int data, std::string filename);
    int find(std::string key, std::string filename);
    void print(std::string filename);
    void min(std::string filename);
    void max(std::string filename);
    void save_file(std::string filename);
    void deleteKey(std::string key);
};
#endif // BST_H