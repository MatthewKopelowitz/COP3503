#include <iostream>
#pragma once
using namespace std;
#include <vector>

template <typename T>
class LinkedList {

public:

    struct Node {
        //variables
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;

        //default constructor
        Node() {value = {};}

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
        for (unsigned int i = 0; i < nCount; i++) {
            cout << curr->value << endl;
            curr = curr->next;
        }
    }

    void PrintReverse() const {
        Node* curr = tail;
        for (unsigned int i = nCount-1; i >= 0; i--) {
            cout << curr->value << endl;
            curr = curr->prev;
        }
    }

    void PrintForwardRecursive(const Node* node) const {
        if (node == nullptr) {
            return;
        }
        cout << node->value << endl;
        PrintForwardRecursive(node->next);
    }

    void PrintReverseRecursive(const Node* node) const {
        if (node == nullptr) {
            return;
        }
        cout << node->value << endl;
        PrintReverseRecursive(node->prev);
    }

//------------Accessors--------------//

    unsigned int NodeCount() const {
        return nCount;
    }

    void FindAll(vector<Node*>& outData, const T& value) const {
        Node* curr = head;
        for (unsigned int i = 0; i < nCount; i++) {
            if (curr->value == value) {
                Node* match = curr;
                outData.push_back(match);
            }
            curr = curr->next;
        }
    }

    const Node* Find(const T& data) const {
        Node* curr = head;
        for (unsigned int i = 0; i < nCount; i++) {
            if (curr->value == data) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    Node* Find(const T& data) {
        Node* curr = head;
        for (unsigned int i = 0; i < nCount; i++) {
            if (curr->value == data) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    const Node* GetNode(unsigned int index) const {
        Node* curr = head;
        if (index < 0 || index >= nCount) {
            throw out_of_range("Out of range");
        }
        for (unsigned int i = 0; i <= index; i++) {
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
        for (unsigned int i = 0; i <= index; i++) {
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
        Node* newNode = new Node;
        newNode->value = data;

        if (nCount == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        nCount++;
    }

    void AddTail(const T& data) {
        Node* newNode = new Node;
        newNode->value = data;

        if (nCount == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        nCount++;
    }

    void AddNodesHead(const T* data, unsigned int count) {
        for (int i = (int)count-1; i >= 0; i--) {
            AddHead(data[i]);
        }
    }

    void AddNodesTail(const T* data, unsigned int count) {
        for (unsigned int i = 0; i < count; i++) {
            AddTail(data[i]);
        }
    }

    void InsertAfter(Node* node, const T& data) {
        Node* newNode = new Node(data);
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode; //
        node->next = newNode;
        nCount++;
    }

    void InsertBefore(Node* node, const T& data) {
        Node* newNode = new Node(data);
        newNode->prev = node->prev;
        newNode->next = node;
        node->prev->next = newNode; //
        node->prev = newNode;
        nCount++;
    }

    void InsertAt(const T& data, unsigned int index) {
        if (index > nCount || index < 0) {
            throw out_of_range("Out of range");
        } else {
            if (index == 0) {
                AddHead(data);
            } else if (index == nCount) {
                AddTail(data);
            } else {
                InsertBefore(GetNode(index), data);
            }
        }
    }

//-------------Removal--------------//

    bool RemoveHead() {
        if (nCount == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            nCount--;
            return true;
        } else if (nCount == 0) {
            return false;
        } else {
            Node* nHead = head->next;
            nHead->prev = nullptr;
            head->prev = nullptr;
            head->next = nullptr;
            delete head;
            head = nHead;
            nCount--;
        }
        return true;
    }

    bool RemoveTail() {
        if (nCount == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            nCount--;
            return true;
        } else if (nCount == 0) {
            return false;
        } else {
            Node* nTail = tail->prev;
            nTail->next = nullptr;
            tail->next = nullptr;
            tail->prev = nullptr;
            delete tail;
            tail = nTail;
            nCount--;
        }
        return true;
    }

    unsigned int Remove(const T& data) {
        unsigned int count = 0;
        bool rmd = false;
        do {
            Node* curr = head;
            rmd = false;
            for (unsigned int i = 0; i < nCount; i++) {
                if (curr->value == data && curr != nullptr) {
                    curr = curr->next;
                    RemoveAt(i);
                    rmd = true;
                    count++;
                    break;
                } else {
                    curr = curr->next;
                }
            }
        } while (rmd);
        return count;
    }

    bool RemoveAt(unsigned int index) {
        if (index < 0 || index > nCount-1) {
            return false;
        } else if (index == 0) {
            RemoveHead();
        } else if (index == nCount-1) {
            RemoveTail();
        } else {
            Node* curr = head;
            for (unsigned int i = 0; i < index; i++) {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            nCount--;
        }
        return true;
    }

    void Clear() {
        while (RemoveTail()) {}
    }

//-------------Operators-------------//

    const T& operator[](unsigned int index) const {
        if (index < 0 || index >= nCount) {
            throw out_of_range("Out of Range");
        } else {
            Node* curr = head;
            for (int i = 1; i <= index; i++) {
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
            for (int i = 1; i <= index; i++) {
                curr = curr->next;
            }
            return curr->value;
        }
    }

    bool operator==(const LinkedList<T>& rhs) const {
        Node* curr = head;
        Node* rhsCurr = rhs.head;
        if (nCount != rhs.nCount) {
            return false;
        }
        for (unsigned int i = 0; i < nCount; i++) {
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
        Clear();

        Node* curr = rhs.head;
        head = curr;
        for (unsigned int i = 0; i < rhs.nCount-1; i++) {
            AddTail(curr->value);
            curr = curr->next;
        }
        AddTail(curr->value);
        return *this;
    }

    //Copy Constructor
    LinkedList(const LinkedList<T>& l) {
        Clear();

        //head = l.head;
        Node* curr = l.head;
        for (unsigned int i = 0; i < l.nCount-1; i++) {
            AddTail(curr->value);
            curr = curr->next;
        }
        AddTail(curr->value);
    }

    //Destructor
    ~LinkedList() {
        //Clear();
        Node* curr = head;
        while (curr != nullptr) {
            Node* nex = curr->next;
            delete curr;
            curr = nex;
        }
        head = nullptr;
    }

};