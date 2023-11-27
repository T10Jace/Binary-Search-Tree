/**
 * @file Node.cpp
 * @author Tristan Riley
 * @date 2023-11-27
 * @brief 
 */

#include <iostream>
#include <string>
#include "Node.h"

Node::Node(std::string key){
    this->key   =  key;
    left  = NULL;
    right = NULL;
    data  =    0;
}