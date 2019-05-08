//
// Created by guilherme on 24/04/19.
//

#ifndef UNTITLED1_AVLTREE_H
#define UNTITLED1_AVLTREE_H

#include <iostream>
#include "Node.h"

using namespace std;

struct AVL{
    Node* root;
    AVL(){
        this->root = nullptr;
    }


    int getHeight(Node* rt){
        if(rt == nullptr){
            return -1;
        }
        return rt->height;
    }

    int getBalance(Node* rt){
        if(rt == nullptr){
            return 0;
        }
        return getHeight(rt->left) - getHeight(rt->right);
    }



    Node* rightRotate(Node* rt){
        Node* l = rt->left;
        Node* lr = l->right;
        l->right = rt;
        rt->left = lr;
        rt->height = max(getHeight(rt->left),getHeight(rt->right))+1;
        l->height = max(getHeight(l->left),getHeight(l->right))+1;
        return l;
    }

    Node* leftRotate(Node* rt){
        Node* r = rt->right;
        Node* rl = r->left;
        r->left = rt;
        rt->right = rl;
        rt->height = max(getHeight(rt->left),getHeight(rt->right))+1;
        r->height = max(getHeight(r->left),getHeight(r->right))+1;
        return r;
    }

    Node* insertHelp(Node* rt, int e){
        if(rt == nullptr){
            Node* newNode = new Node(e);
            return newNode;
        }
        if(rt->element > e){
            rt->left = insertHelp(rt->left, e);
        }else{
            rt->right = insertHelp(rt->right, e);
        }
        rt->height = 1 + max(getHeight(rt->left), getHeight(rt->right));
        int balance = getBalance(rt);
        if(balance > 1 && e < rt->left->element){
            return rightRotate(rt);
        }
        if(balance < -1 && e >= rt->right->element){
            return leftRotate(rt);
        }
        if(balance > 1 && e >= rt->left->element){
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if(balance < -1 && e < rt->right->element){
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
    }


    void insert(int e){
        this->root = insertHelp(this->root, e);
    }

    static int findHelp(Node* rt, int e){
        if(rt == nullptr){
            return -1;
        }
        if(rt->element == e){
            return rt->element;
        }else if(rt->element > e){
            return findHelp(rt->left, e);
        }else{
            return findHelp(rt->right, e);
        }
    }

    int find(int e){
        return findHelp(this->root, e);
    }

    Node* getMin(Node* rt){
        if(rt->left == nullptr){
            return rt;
        }
        return getMin(rt->left);
    }

    Node* deleteMin(Node* rt){
        if(rt->left == nullptr){
            return rt->right;
        }
        rt->left = deleteMin(rt->left);
        return rt;
    }

    Node* removeHelp(Node* rt, int e){
        if(rt == nullptr){
            return nullptr;
        }
        if(rt->element > e){
            rt->left = removeHelp(rt->left, e);
        }else if(rt->element < e){
            rt->right = removeHelp(rt->right, e);
        }else{
            if(rt->left == nullptr){
                return rt->right;
            }else if(rt->right == nullptr){
                return rt->left;
            }else{
                Node* aux = getMin(rt->right);
                rt->element = aux->element;
                rt->right = deleteMin(rt->right);
            }
            rt->height = 1 + max(getHeight(rt->left), getHeight(rt->right));
            int balance = getBalance(rt);
            if(balance > 1 && e < rt->left->element){
                return rightRotate(rt);
            }
            if(balance < -1 && e >= rt->right->element){
                return leftRotate(rt);
            }
            if(balance > 1 && e >= rt->left->element){
                rt->left = leftRotate(rt->left);
                return rightRotate(rt);
            }
            if(balance < -1 && e < rt->right->element){
                rt->right = rightRotate(rt->right);
                return leftRotate(rt);
            }
        }
        return rt;
    }

    int remove(int e){
        int temp = findHelp(this->root, e);
        if(temp != -1){
            this->root = removeHelp(this->root, e);
            return temp;
        }else{
            return -1;
        }
    }

    void helpClean(Node* rt){
        if(rt == nullptr){
            return;
        }
        helpClean(rt->left);
        helpClean(rt->right);
        delete rt;
    }

    void clean(){
        helpClean(this->root);
    }
};

#endif //UNTITLED1_AVLTREE_H
