#include <iostream>

class Node {
public:
    int data;
    Node* next{};
    Node* prev{};
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
public:
    Node* head;
    Node* tail;
    int nodeCount;

    DoubleLinkedList() : head(nullptr), tail(nullptr), nodeCount(0) {}

    void pushNode(bool toHead, int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) { // new list
            head = newNode;
            tail = newNode;
        }
        else { // existing list
            if (toHead) { // insert at front
                newNode->next = head;
                newNode->next->prev = newNode;
                head = newNode;
            }
            else { // insert at back
                tail->next = newNode;
                newNode->prev = tail;
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
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }

        nodeCount--;
    }

    void popHead() {
        if (head == nullptr) {
            return; // Empty list, nothing to unset
        }

        Node* oldHead = head;
        head = head->next;
        head->prev = nullptr;
        delete oldHead;

        nodeCount--;
    }

    void display(bool fwd) {
        if (fwd) {
            std::cout << "- First to Last -" << std::endl;
            std::cout << "(" << nodeCount << ") [ ";
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->data;
                if (current->next != nullptr)
                    std::cout << ", ";
                current = current->next;
            }
        }
        else {
            std::cout << "- Last to First -" << std::endl;
            std::cout << "(" << nodeCount << ") [ ";
            Node* current = tail;
            while (current != nullptr) {
                std::cout << current->data;
                if (current->prev != nullptr)
                    std::cout << ", ";
                current = current->prev;
            }
        }

        std::cout << " ] " << std::endl;
    }

}; // class DoubleLinkedList
