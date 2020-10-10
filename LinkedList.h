#include <iostream>
#pragma once
using namespace std;

template <typename T>
class LinkedList {

    struct Node {
        //variables
        T value;
        Node* next, prev = nullptr;

        //constructor
        Node(T d) {value = d;}

        //accessors and mutators
        T getValue() {return value;}
        void setValue(T d) {value = d;}

        Node* getNext() {return next;}
        void setNext(Node* n) {next = n;}

        Node* getPrev() {return prev;}
        void setPrev(Node* p) {prev = p;}
    };

    //LinkedList variables
    Node* head, tail = nullptr;
    unsigned int nodeCount = 0;

    //Default Constructor
    LinkedList() {

    }

    //Constructor
    LinkedList(/*PUT SOME PARAMETERS HERE*/) {

    }

//-----------------BIG THREE-------------------//

    //Copy Constructor
    LinkedList(const LinkedList<T>& l) {

    }

    //Copy Assignment Operator
    LinkedList<T>& operator=(const LinkedList<T>& l) {

    }

    //Destructor
    ~LinkedList() {

    }

//---------------------------------------------//

public:

    //This was done in Tyler's lab
    void AddTail(const T& data) {
        Node* newNode = new Node;
        newNode->value = data;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void AddNodesTail(const T* data, unsigned int count) {

    }






};
