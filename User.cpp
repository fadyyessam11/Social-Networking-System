#include "User.h"
#include <iostream>

void  User::AddFriend(User *u) {
   root=root->insert(root, u);
}

void User::allf()
{
    root->inorder(root);
}

string User::getUsername() {
    return username;
}

ostream &operator<<(ostream &os, const User &u) {
    os << u.username;
    os << u.name;
    return os;
}

User::User() {
    username="";
    name="";
    email="";
}

User::User(string username, string name, string email) {
    this->name = name;
    this->email = email;
    this->username = username;
}

User::User(const User &u) {
    username=u.username;
    name=u.name;
    email=u.email;
}

User &User::operator=(User &u) {
    username=u.username;
    name=u.name;
    email=u.email;
    return *this;
}

TreapNode *User::getRoot() {
    return root;
}

string User::getEmail() {
    return email;
}

void  User::DeleteFriend(User *u) {

    root->deleteNode(root,u);
}
