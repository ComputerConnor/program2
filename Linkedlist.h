#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "DataClass.h"

using namespace std;

template <typename T>
class ListNode;

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;
    ListNode* previous;
    ListNode(const T& dataItem) : data(dataItem), next(nullptr), previous(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int listSize;

public:
    LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    void append(const T& item) {
        ListNode<T>* newNode = new ListNode<T>(item);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        listSize++;
    }

    void popFront() {
        if (head) {
            ListNode<T>* temp = head;
            head = head->next;
            if (head) head->previous = nullptr;
            delete temp;
            listSize--;
        }
    }

    void removeAt(int index) {
        if (index < 1 || index > listSize) {
            cout << "Index out of bounds." << endl;
            return;
        }

        ListNode<T>* current = head;

        // Traverse to the node at the specified index
        for (int i = 1; i < index; ++i) {
            current = current->next;
        }

        if (current->previous) {
            current->previous->next = current->next;  // Link previous node to next node
        } else {
            head = current->next;  // If it's the head, update head
        }

        if (current->next) {
            current->next->previous = current->previous;  // Link next node to previous node
        } else {
            tail = current->previous;  // If it's the tail, update tail
        }

        delete current;
        listSize--;
    }

    void displayItems() const {
        ListNode<T>* current = head;
        int index = 1;
        while (current) {
            cout << index << ". " << current->data.getDetails() << endl;
            current = current->next;
            index++;
        }
    }

    // Returns the current size of the linked list
    int size() const {
        return listSize; // Return the renamed variable
    }

    // Sort function (placeholder for quicksort or mergesort)
    void sort(bool ascending = true);
};

#endif
