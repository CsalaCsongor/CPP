//
// Created by Csala on 2024. 10. 07..
//
#include "Lista_lancolt.h"
#include <iostream>
List::List() {
    this->first = nullptr;
}
bool List::exists(int d) const{
    for(Node *p = first; p!= nullptr; p = p->next)
    {
        if(p->value == d)
            return true;
    }
    return false;
}

int List::size() const{
    return this->nodeCounter;
}

bool List::empty() const{
    return this->nodeCounter==0;
}

void List::insertFirst(int d){
    Node* newNode = new Node(d, this->first);
    this->first = newNode;
    this->nodeCounter++;
}

int List::removeFirst(){
    if(this->first == nullptr)
    {
        return 0;
    }

    Node* temp = this->first;
    int value = first->value;
this->first = this->first->next;
delete temp;
return value;
}

void List::remove(int d, DeleteFlag df) {
    if (this->first == nullptr) {
        return;
    }

    Node *p = nullptr, *c = first;


    while (c != nullptr) {
        // Check the condition based on the DeleteFlag
        if ((df == DeleteFlag::EQUAL && c->value == d) ||
            (df == DeleteFlag::LESS && c->value < d) ||
            (df == DeleteFlag::GREATER && c->value > d)) {


            if (p == nullptr) {
                this->first = c->next;
            } else {
                p->next = c->next;
            }
       delete c;
            return;
        }
        p = c;
        c = c->next;
    }
}

void List::print() const{
    Node *p = this->first;
    while(p != nullptr)
    {
        std::cout << p->value << " -> ";
        p = p->next;
    }
}



