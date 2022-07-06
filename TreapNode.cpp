#include <iostream>
#include "TreapNode.h"

TreapNode *TreapNode::rightRotate(TreapNode *y) {
    TreapNode* x = y->left, * T2 = x->right;
    x->right = y;
    y->left = T2;

    return x;
}

TreapNode *TreapNode::leftRotate(TreapNode *x) {
    TreapNode* y = x->right, * T2 = y->left;
    y->left = x;
    x->right = T2;

    return y;
}

TreapNode *TreapNode::newNode(User *k) {
    TreapNode* temp = new TreapNode;

    temp->key = k;
    temp->priority = rand() % 100;
    temp->left = temp->right = NULL;
    return temp;
}

User* TreapNode::search(TreapNode *root, string un) {
   if(root==NULL)
       return NULL;

    if ( root->key->getUsername() == un)
        return (root->key);

    if (root->key->getUsername() < un)
        return search(root->right, un);

    else
        return search(root->left, un);
}

TreapNode *TreapNode::insert(TreapNode *root, User *key) {

    if (!root) {
        return newNode(key);
    }
    if(key->getUsername()==root->key->getUsername())
    {
        return root;
    }
    if (key->getUsername() < root->key->getUsername())
    {
        root->left = insert(root->left, key);

        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else
    {
        root->right = insert(root->right, key);

        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}


void  TreapNode::inorder(TreapNode *root) {

    if (root) {
        inorder(root->left);
        cout << *(root->key);
        cout << endl;
        inorder(root->right);
    }





}

void TreapNode::deleteNode(TreapNode *&root, User *key) {
    if (root == nullptr) {
        return;
    }

    if (key < root->key) {
        deleteNode(root->left, key);
    }

    else if (key > root->key) {
        deleteNode(root->right, key);
    }


    else {

        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }


        else if (root->left && root->right)
        {

            if (root->left->priority < root->right->priority)
            {

                leftRotate(root);
                deleteNode(root->left, key);
            }
            else {
                rightRotate(root);
                deleteNode(root->right, key);
            }
        }

        else {
            TreapNode* child = (root->left)? root->left: root->right;
            TreapNode* curr = root;

            root = child;

            delete curr;
        }
    }

}

