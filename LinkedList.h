#include <iostream>
#pragma once
using namespace std;

template <typename T>
class LinkedList {

    struct Node {
        //variables
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;

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

public:

    //LinkedList variables
    Node* head = nullptr;
    Node* tail = nullptr;
    unsigned int nCount = 0;


    //Default Constructor
    LinkedList() {
        nCount = 0;
        head = nullptr;
        tail = nullptr;
    }

//-----------Behaviors-------------//
    void PrintForward() const {
        Node* curr = head;
        for (int i = 0; i < nCount; i++) {
            cout << curr->value << endl;
            curr = curr->next;
        }
    }

    void PrintReverse() const {
        Node* curr = tail;
        for (int i = nCount-1; i >= 0; i++) {
            cout << curr->value << endl;
            curr = curr->next;
        }
    }

    void PrintForwardRecursive(const Node* node) const {

    }

    void PrintReverseRecursive(const Node* node) const {

    }

//------------Accessors--------------//

    unsigned int NodeCount() const {
        return nCount;
    }

    void FindAll(vector<Node*>& outData, const T& value) const {
        Node* curr = head;
        for (int i = 0; i < nCount; i++) {
            if (curr->value == value) {
                Node* match = curr;
                outData.push_back(match);
            }
        }
    }

    const Node* Find(const T& data) {
        Node* curr = head;
        for (int i = 0; i < nCount; i++) {
            if (curr->value == data) {
                return curr;
            }
        }
        return nullptr;
    }

    const Node* GetNode(unsigned int index) const {
        Node* curr = head;
        if (index < 0 || index >= nCount) {
            throw out_of_range("Out of range");
        }
        for (int i = 0; i <= index; i++) {
            if (i == index) {
                break;
            }
            curr = curr->next;
        }
        return curr;
    }

    Node* GetNode(unsigned int index) {
        Node* curr = head;
        if (index < 0 || index >= nCount) {
            throw out_of_range("Out of range");
        }
        for (int i = 0; i <= index; i++) {
            if (i == index) {
                break;
            }
            curr = curr->next;
        }
        return curr;
    }

    Node* Head() {
        return head;
    }

    const Node* Head() const {
        return head;
    }

    Node* Tail() {
        return tail;
    }

    const Node* Tail() const {
        return tail;
    }

//-------------Insertion-------------//

    void AddHead(const T& data) {
        Node newNode = new Node;
        newNode->value = data;
        newNode->next = head;
        //head->next = newNode;
        head = newNode;
        nCount++;
    }

    //This was done in Tyler's lab
    void AddTail(const T& data) {
        Node* newNode = new Node;
        newNode->value = data;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        nCount++;
    }

    void AddNodesHead(const T* data, unsigned int count) {
        Node* last = head;
        for (int i = 0; i < count; i++) {
            if (i != count-1) {

            }
        }
    }

    void AddNodesTail(const T* data, unsigned int count) {

    }

    void InsertAfter(Node* node, const T& data) {

    }

    void InsertBefore(Node* node, const T& data) {

    }

    void InsertAt(const T& data, unsigned int index) {

    }

//-------------Removal--------------//

    bool RemoveHead() {

    }

    bool RemoveTail() {

    }

    unsigned int Remove(const T& data) {

    }

    bool RemoveAt(unsigned int index) {

    }

    void Clear() {

    }

//-------------Operators-------------//

    const T& operator[](unsigned int index) const {
        if (index < 0 || index >= nCount) {
            throw out_of_range("Out of Range");
        } else {
            Node* curr = head;
            for (int i = 0; i <= index; i++) {
                curr = curr->next;
            }
            return curr->value;
        }
    }

    T& operator[](unsigned int index) {
        if (index < 0 || index >= nCount) {
            throw out_of_range("Out of Range");
        } else {
            Node* curr = head;
            for (int i = 0; i <= index; i++) {
                curr = curr->next;
            }
            return curr->value;
        }
    }

    bool operator==(const LinkedList<T>& rhs) const {
        Node* curr = head;
        Node* rhsCurr = rhs.head;
        for (int i = 0; i < nCount; i++) {
            if (curr->value != rhsCurr->value) {
                return false;
            }
            curr = curr->next;
            rhsCurr = rhsCurr->next;
        }
        return true;
    }



//-----------------BIG THREE-------------------//

    //Copy Assignment Operator
    LinkedList<T>& operator=(const LinkedList<T>& rhs) {

    }

    //Copy Constructor
    LinkedList(const LinkedList<T>& l) {

    }

    //Destructor
    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nex = curr->next;
            delete curr;
            curr = nex;
        }
        head = nullptr;
    }

};
