/**
 * @file BST.cpp
 * @author Tristan Riley
 * @date 2023-11-27
 * @brief 
 */

#include "BST.h"
#include <iostream>
#include <fstream>

// Constructor
BST::BST() {
    root = nullptr;
}

// Destructor
BST::~BST() {
    destroyTree(root);
}

// Helper method to recursively destroy the tree
void BST::destroyTree(Node *leaf) {
    if (leaf != nullptr) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

// Method to set a data point in the BST
void BST::set(std::string key, int data, std::string filename) {
    std::ofstream outFile(filename, std::ios::app);
    if (outFile.is_open()) {
        root = insert(root, key, data);
        saveToFile(root, outFile);
        outFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

// Method to find a data point in the BST
int BST::find(std::string key, std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Node *foundNode = find(root, key);
        if (foundNode != nullptr) {
            inFile.close();
            return foundNode->data;
        } else {
            inFile.close();
            return -1; // Or any suitable value indicating data not found
        }
    } else {
        std::cout << "Unable to open file." << std::endl;
        return -1; // Or any suitable value indicating data not found
    }
}

// Method to print the contents of the BST in order
void BST::print(std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        printInOrder(root);
        inFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

// Method to find the minimum data point in the BST
void BST::min(std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Node *minNode = findMin(root);
        std::cout << "Minimum data point: (" << minNode->key << ", " << minNode->data << ")" << std::endl;
        inFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

// Method to find the maximum data point in the BST
void BST::max(std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Node *maxNode = findMax(root);
        std::cout << "Maximum data point: (" << maxNode->key << ", " << maxNode->data << ")" << std::endl;
        inFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

// Method to save the contents of the BST in order to a file
void BST::save_file(std::string filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        saveToFile(root, outFile);
        outFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

// Method to delete a data point from the BST
void BST::deleteKey(std::string key) {
    root = deleteNode(root, key);
}

// Private method to insert a node into the BST
Node* BST::insert(Node *leaf, std::string key, int data) {
    if (leaf == nullptr) {
        leaf = new Node(key);
        leaf->data = data;
    } else if (key < leaf->key) {
        leaf->left = insert(leaf->left, key, data);
    } else if (key > leaf->key) {
        leaf->right = insert(leaf->right, key, data);
    } else {
        leaf->data = data; // Overwrite data if key already exists
    }
    return leaf;
}

// Private method to find a node with a specific key in the BST
Node* BST::find(Node *leaf, std::string key) {
    if (leaf == nullptr) {
        return nullptr;
    }
    if (key == leaf->key) {
        return leaf;
    } else if (key < leaf->key) {
        return find(leaf->left, key);
    } else {
        return find(leaf->right, key);
    }
}

// Private method to perform an in-order traversal and print the BST
void BST::printInOrder(Node *leaf) {
    if (leaf != nullptr) {
        printInOrder(leaf->left);
        std::cout << "(" << leaf->key << ", " << leaf->data << ")" << std::endl;
        printInOrder(leaf->right);
    }
}

// Private method to find the node with the minimum key in the BST
Node* BST::findMin(Node *leaf) {
    if (leaf == nullptr) {
        return nullptr; // Or handle as needed
    }
    while (leaf->left != nullptr) {
        leaf = leaf->left;
    }
    return leaf;
}

// Private method to find the node with the maximum key in the BST
Node* BST::findMax(Node *leaf) {
    if (leaf == nullptr) {
        return nullptr; // Or handle as needed
    }
    while (leaf->right != nullptr) {
        leaf = leaf->right;
    }
    return leaf;
}

// Private method to delete a node with a specific key from the BST
Node* BST::deleteNode(Node* leaf, std::string key) {
    if (leaf == nullptr) {
        return leaf;
    }

    if (key < leaf->key) {
        leaf->left = deleteNode(leaf->left, key);
    } else if (key > leaf->key) {
        leaf->right = deleteNode(leaf->right, key);
    } else {
        // Node with only one child or no child
        if (leaf->left == nullptr) {
            Node* temp = leaf->right;
            delete leaf;
            return temp;
        } else if (leaf->right == nullptr) {
            Node* temp = leaf->left;
            delete leaf;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(leaf->right);

        // Copy the inorder successor's content to this node
        leaf->key = temp->key;
        leaf->data = temp->data;

        // Delete the inorder successor
        leaf->right = deleteNode(leaf->right, temp->key);
    }
    return leaf;
}


// Private method to save the contents of the BST in order to a file
void BST::saveToFile(Node *leaf, std::ofstream &file) {
    if (leaf != nullptr) {
        saveToFile(leaf->left, file);
        file << leaf->key << " " << leaf->data << std::endl;
        saveToFile(leaf->right, file);
    }
}
