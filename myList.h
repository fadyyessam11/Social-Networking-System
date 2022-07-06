#ifndef DS_PROJECT_MYLIST_H
#define DS_PROJECT_MYLIST_H
#include"User.h"
#include<iostream>

struct Node
{
    User data;
    Node *next;
    Node  *prev;

    Node ()
    {
        prev = next = NULL;
    }
};

class myList {
    Node *first;
    Node *last;
    int initial_size;

public:
    myList ();
    ~myList ();
    int size ();

    class iterator
    {
        Node  *point;
        friend class myList;

    public:

        iterator () { point = NULL; }

        iterator (Node *ptr) { point = ptr; }

        void operator-- () { point = point->prev; }

        User & operator* () { return reinterpret_cast < User & >(point->data); }

        void operator++ () { point = point->next; }

        bool operator== (const iterator & obj) { return point == obj.point; }

        bool operator!= (const iterator & obj) { return point != obj.point; }
    };

    iterator begin () { return iterator (first); }
    iterator End () { return iterator (last->next); }


    void insert (iterator position, User value);
    void print (myList & l);

};

#endif //DS_PROJECT_MYLIST_H
