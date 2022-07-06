#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "User.h"
#include "myList.h"
using namespace std;

void menu()
{
    myList L;
    TreapNode *n;
    ifstream inFile;
    inFile.open ("../all-users.in");
    //file1
    if (!inFile)
    {
        cout << "Unable to Open File 1";
        exit (1);	// terminate with error
    }

    if (inFile.is_open ())
    {
        string line;
        while (getline (inFile, line))
        {
            stringstream ss (line);
            string userName, name, email;
            getline (ss, userName, ',');
            getline (ss, name, ',');
            getline (ss, email, ',');
            L.insert (L.begin (), User (userName, name, email));
        }
    }
    inFile.close ();


    //file2
    inFile.open ("../all-users-relations.in");
    if (!inFile)
    {
        cout << "Unable to Open File 2";
        exit (1);
    }

    while (inFile)
    {
        string line;
        getline (inFile, line);

        if (line == "")
        {
            continue;
        }
        int pos = line.find (',');

        string t = line.substr (0, pos);
        pos += 2;
        string friends = line.substr (pos);

        User *u1 = NULL, *u2 = NULL;

        for (myList::iterator i = L.begin (); i != L.End (); ++i)
        {
            if ((*i).getUsername () == t)
            {
                u1 = &(*i);
            }
            else if ((*i).getUsername () == friends)
            {
                u2 = &(*i);
            }
        }

        if (u1 != NULL && u2 != NULL)
        {
            u1->AddFriend (u2);
            u2->AddFriend (u1);
        }
    }
    inFile.close ();

    cout<<"Welcome to Our Social Networking System "<<endl;
    cout<<"------------------------------------------"<<endl;

    while (true)
    {
        cout << "1) Login" << endl;
        cout << "2) Exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            string username;
            cout << "Enter the Username: " << endl;
            cin >> username;
            int count = 0;
            for (myList::iterator i = L.begin(); i != L.End(); ++i) {

                if (username == (*i).getUsername()) {
                    cout << "- Login Successful - " << endl;

                    count = 1;
                    while (true) {
                        int list;
                        TreapNode* t;
                        cout << " 1) List all Friends" << endl;
                        cout << " 2) Search by Username" << endl;
                        cout << " 3) Add Friend" << endl;
                        cout << " 4) Remove Friend" << endl;
                        cout << " 5) People yo may know" << endl;
                        cout << " 6) Logout" << endl;
                        cin >> list;
                        if (list == 1)
                        {
                            cout << "Your Friends: " << endl;
                            cout << "*************************" << endl;
                            (*i).allf();
                            cout << "*************************" << endl;
                        }
                        else if (list == 2)
                        {
                            string s;
                            cout<<"Enter Username to Search: "<<endl;
                            cin>>s;
                            User *res =t-> search((*i).getRoot(), s);

                            if(res==NULL)
                            {
                                cout<<"User Not Found !"<<endl;
                            }
                            else{
                                cout<<*(t->search((*i).getRoot(),s))<<((t->search((*i).getRoot(),s)))->getEmail()<<endl;
                            }
                        }
                        else if (list == 3)
                        {
                            cout<<"Enter Username to Add: "<<endl;
                            string newF;
                            bool found=false;
                            cin>>newF;
                            for (myList::iterator j = L.begin(); j != L.End(); ++j) {

                                if (newF == (*j).getUsername())
                                {
                                    found=true;
                                    User *u2 =t-> search((*i).getRoot(), newF);
                                    if(u2== nullptr)
                                    {
                                        (*i).AddFriend(&(*j));
                                        (*j).AddFriend(&(*i));
                                        cout<<"You are now Friends :)"<<endl;
                                    }
                                    else
                                        cout<<"You are already Friends"<<endl;
                                }
                            }
                            if(!found)
                            {
                                cout<<"Wrong Username"<<endl;
                            }

                        }
                        else if (list == 4) {
                            cout << "Enter Username to Remove: " << endl;
                            string oldF;
                            cin >> oldF;
                            for (myList::iterator k = L.begin(); k != L.End(); ++k) {

                                if (oldF == (*k).getUsername()) {
                                    User *u3 = t->search((*i).getRoot(), oldF);
                                    if (u3 != nullptr) {
                                        (*i).DeleteFriend(u3);
                                        (*k).DeleteFriend(&(*i));
                                        cout << "User Removed" << endl;
                                    } else
                                        continue;
                                }
                            }
                        }
                        else if (list == 5)
                        {
                            int count=0;
                            string s;
                            s=(*i).getUsername(); //log in
                            for (myList::iterator j = L.begin(); j != L.End(); ++j) {
                                User *res = t->search((*i).getRoot(), (*j).getUsername());
                                if (res == NULL && (*j).getUsername() != s) {
                                    cout << (*j) << endl;
                                    count++;
                                }
                                if(count==5)
                                {
                                    break;
                                }
                            }
                        }
                        else if (list == 6) {
                            break;
                        }
                        else{
                            cout<<"Wrong Choice please Try again.."<< endl;
                            continue;
                        }
                    }
                    continue;
                }
            }

            if (count == 0)
            {
                cout << "Login Failed"<<endl;

                continue;
            }
        }
        if (choice == 2)
        {
            break;
        }

    }
}


int main ()
{
    menu();
    return 0;
}