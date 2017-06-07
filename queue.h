#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdlib.h>
#include "podatnik.h"

struct Queue {
    private:
        struct Node {
            Podatnik p;
            Node* next;

            Node(Podatnik _p, Node* _next=NULL) {
                p=_p;
                next=_next;
            }
        };

        Node* head;
        Node* tail;
        unsigned int size;
    public:
        Queue();
        void insert(Podatnik p);
        void print() const;
        Podatnik pop();
        bool isEmpty() const;
};

#endif // QUEUE_H_INCLUDED
