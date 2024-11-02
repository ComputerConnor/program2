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

        for (int i = 1; i < index; i++) {
            current = current->next;
        }

        if (current->previous) {
            current->previous->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->previous = current->previous;
        } else {
            tail = current->previous;
        }

        delete current;
        listSize--;
    }

    friend ostream& operator << (ostream& os, const LinkedList<T>& list)
    {
        ListNode<T>* current = list.head;
        int index = 1;
        while (current) {
            os << index << ". " << current->data.getDetails() << endl;
            current = current->next;
            index++;
        }
        return os;
    }

    // Returns the current size of the linked list
    int size() const {
        return listSize;
    }


    // Sort function (Quick sort)
    ListNode<T>* sort(bool ascending)
    {
        sortHelper (head, tail, ascending);

        if (ascending != true)
        {
            head = reverseList (head);
            head = reverseList (head);
        }
        return head;
    }

    ListNode<T>* partition (ListNode<T>* head, ListNode<T>* tail, bool ascending)
    {
        ListNode<T>* pivot = head;
        ListNode<T>* previous = head;
        ListNode<T>* current = head->next;

        while (current != tail->next)
        {
            if ((ascending && (current->data < pivot->data)) || (!ascending && (current->data > pivot->data)))
            {
                swap (current->data, previous->next->data);

                previous = previous->next;
            }
            current = current->next;
        }
        swap (pivot->data, previous->data);

        return previous;
    }

    void sortHelper (ListNode<T>* head, ListNode<T>* tail, bool ascending)
    {
        if (head == NULL || head == tail)
        {
            return;
        }   
            ListNode<T>* pivot = partition (head, tail, ascending);

            sortHelper (head, pivot, ascending);

            sortHelper (pivot->next, tail, ascending);
    }

    ListNode<T>* reverseList (ListNode<T>*& head)
    {
        ListNode<T>* previous = NULL;
        ListNode<T>* current = head;
        ListNode<T>* next;

        while (current)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }

};

#endif
