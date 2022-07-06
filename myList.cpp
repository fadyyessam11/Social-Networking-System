
#include "myList.h"

myList::myList() {
    first = new Node  ();
    last = new Node ();
    first = last;
    initial_size = 0;
}

myList::~myList() {
    int done=0;
    if (done != 0)
    {
        done--;
    }
    else
    {
        Node *curNode = first;
        Node *tmp = curNode;
        int s = size ();
        while (s--)
        {
            tmp = curNode->next;
            delete curNode;
            curNode = tmp;
        }
        delete curNode;
        delete tmp;
    }
}

int myList::size() {
    return initial_size;
}

void myList::insert(myList::iterator position, User value) {
    Node *newNode = new Node ();
    newNode->data = value;
    if (position.point == first)
    {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
        first->prev = NULL;
    }
    else
    {
        newNode->next = position.point;
        newNode->prev = position.point->prev;
        position.point->prev->next = newNode;
        position.point->prev = newNode;
    }
    ++initial_size;
    newNode = first;

    for (int i = 0; i < initial_size - 1; i++)
    {
        newNode = newNode->next;
    }

    newNode->next = NULL;
    last = newNode;
}

void myList::print(myList &l) {
    typename myList::iterator it = l.begin ();

    while (it != l.End ())
    {

        cout << *it << ' ';
        ++it;
        cout << endl;
    }

}

