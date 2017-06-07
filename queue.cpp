#include <iostream>
#include "queue.h"

/**
* Non-parameter constructor. Set head to NULL and size of structure to 0
*/
Queue::Queue() {
    head=NULL;
    tail=NULL;
    size=0;
}

/**
* Add new Podatnik to queue. Increment size of structure
*/
void Queue::insert(Podatnik podatnik) {
    Node* p=new Node(podatnik);

    if(tail!=NULL)
        tail->next=p;
    else
        head=p;

    tail=p;

    size++;
}

/**
* print queue content
*/
void Queue::print() const {
    if(size==0) {
        std::cout<<"Kolejka jest pusta."<<std::endl;
        return;
    }

    Node* walker=head;

    while(walker!=NULL) {
        std::cout<<walker->p.getNazwaPodatnika()<<std::endl;
        walker=walker->next;
    }
    std::cout<<std::endl;
}

/**
* returns true when queue is empty
*/
bool Queue::isEmpty() const {
    if(size==0)
        return true;
    return false;
}

/**
* take first node from queue
*/
Podatnik Queue::pop() {
    Node* killer=head;
    Podatnik p=head->p;
    head=head->next;
    delete killer;
    size--;

    return p;
}

