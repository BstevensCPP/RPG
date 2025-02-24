#pragma once
#include <iostream>
#include "item.h"
using namespace std;

// Node class to represent an element in the linked list
template <class T>
class Node {
public:
    T* data;       
    Node<T>* nextnode; 

    Node(T num) {
        data = num;
        nextnode = nullptr; 
    }
};

// Singly Linked List (SLL) class to manage the linked list
template <typename T>
class SLL {
public:
    Node<T>* head;  // Pointer to the first node in the list
    Node<T>* index; // Pointer to the current node in the list

    // Constructor to initialize an empty list
    SLL() {
        head = nullptr;
        index = nullptr;
    }

    // Destructor to clean up all dynamically allocated nodes
    ~SLL() {
        Node<T>* current = head;
        Node<T>* nextnode;
        while (current != nullptr) {
            nextnode = current->nextnode;
            delete current;
            current = nextnode;
        }
    }

    // Method to get the current node pointed by "index"
    Node<T>* getcurrent() {
        return index;
    }

    // Method to get the last node in the list
    Node<T>* getlast() {
        if (head == nullptr)  // Check if the list is empty
            return nullptr;

        Node<T>* current = head;
        while (current->nextnode != nullptr) {
            current = current->nextnode;
        }

        return current;  // Return the last node
    }

    // Method to get the first node in the list
    Node<T>* getfirst() {
        return head;
    }

    // Method to add a node to the end of the list
    void pushback(Node<T>* newNode) {
        if (head == nullptr) {
            head = newNode;
            index = head;  // Reset "index" to point to the head
        }
        else {
            Node<T>* last = getlast();
            last->nextnode = newNode;
            index = head;  // Reset "index" to point to the head
        }
    }

    // Method to insert a node immediately after a given node
    void insertafter(Node<T>* prevnode, Node<T>* newNode) {
        if (prevnode == nullptr) {
            return;
        }
        newNode->nextnode = prevnode->nextnode;
        prevnode->nextnode = newNode;
        index = newNode;
    }

    // Method to add a node to the front of the list
    void pushfront(Node<T>* newNode) {
        newNode->nextnode = head;
        head = newNode;
        index = head;
    }

    // Method to delete the node pointed to by "index"
    void deletecurrent() {
        if (index == nullptr) return;

        Node<T>* temp = index;
        if (index == head) {
            head = index->nextnode;
            index = head;
        }
        else {
            Node<T>* prev = head;
            while (prev->nextnode != index) {
                prev = prev->nextnode;
            }
            prev->nextnode = index->nextnode;
            index = prev->nextnode;
        }
        delete temp;
    }

    // Method to remove the last node in the list
    Node<T>* popback() {
        if (head == nullptr) return nullptr;

        if (head->nextnode == nullptr) {
            Node<T>* temp = head;
            head = nullptr;
            index = nullptr;
            return temp;
        }
        else {
            Node<T>* temp = head;
            while (temp->nextnode != nullptr) {
                temp = temp->nextnode;
            }
            Node<T>* last = temp;
            temp = head;
            while (temp->nextnode != last) {
                temp = temp->nextnode;
            }
            temp->nextnode = nullptr;
            index = temp;
            return last;
        }
    }

    // Method to remove the first node in the list
    Node<T>* popfront() {
        if (head == nullptr) {
            return nullptr;
        }
        Node<T>* temp = head;
        head = head->nextnode;
        index = head;
        return temp;
    }

    // Method to display the list
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->nextnode;
        }
        cout << endl;
    }
};
