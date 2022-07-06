
#ifndef DS_PROJECT_TREAPNODE_H
#define DS_PROJECT_TREAPNODE_H
#include "User.h"
using namespace std;

class User;
class TreapNode {
private:
    User* key;
    int priority;
    TreapNode* left, * right;

public:
    TreapNode* rightRotate(TreapNode* y);
    TreapNode* leftRotate(TreapNode* x);
    TreapNode* newNode(User* k);
    User* search(TreapNode* root, string un);
    TreapNode* insert(TreapNode* root, User* key);
    void inorder(TreapNode* root);
    void deleteNode(TreapNode* &root, User *key);
};

#endif //DS_PROJECT_TREAPNODE_H
