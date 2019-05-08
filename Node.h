//
// Created by guilherme on 24/04/19.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H

struct Node{
    Node* left;
    Node* right;
    int element, height;
    Node(int e){
        this->height = 0;
        this->element = e;
        this->left = nullptr;
        this->right = nullptr;
    }
};

#endif //UNTITLED1_NODE_H
