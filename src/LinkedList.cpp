#include <iostream>

class Node {
public:
    int data;
    Node* next{};
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int nodeCount;

    LinkedList() : head(nullptr), tail(nullptr), nodeCount(0) {}

    void pushNode(bool toHead, int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) { // new list
            head = newNode;
            tail = newNode;
        }
        else { // existing list
            if (toHead) { // insert at front
                newNode->next = head;
                head = newNode;
            }
            else { // insert at back
                tail->next = newNode;
                tail = newNode;
            }
        }

        nodeCount++;
    }

    void popTail() {
        if (head == nullptr) {
            return; // Empty list, nothing to pop
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            current->next = nullptr;
        }

        nodeCount--;
    }

    void popHead() {
        if (head == nullptr) {
            return; // Empty list, nothing to unset
        }

        Node* oldHead = head;
        head = head->next;
        delete oldHead;

        nodeCount--;
    }

    void display() {
        Node* current = head;

        std::cout << "(" << nodeCount << ") ";

        std::cout << "[ ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr)
                std::cout << ", ";
            current = current->next;
        }

        std::cout << " ] " << std::endl;
    }

}; // class LinkedList
