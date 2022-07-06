#ifndef DS_PROJECT_USER_H
#define DS_PROJECT_USER_H
#include <string>
#include "TreapNode.h"
using namespace std;
class TreapNode;
class User {

private:
    string name, username, email;
    TreapNode* root=NULL;

public:
    explicit User();
    User(string username, string name, string email);
    User(const User& u);
    void AddFriend(User* u);
    void DeleteFriend(User *u);
    string getUsername();
    friend ostream& operator<<(ostream& os, const User& u);
    User& operator=(User& u);
    TreapNode * getRoot();
    string getEmail();
    void allf();

};

#endif //DS_PROJECT_USER_H
