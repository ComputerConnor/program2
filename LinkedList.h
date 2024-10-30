#define LINKEDLIST_H
#ifdef LINKEDLIST_H
#include <iostream>
using namespace std;


class LinkedList
{
    private: 
        ListNode<Cart> *head;
        ListNode<Cart> *tail;

    public:
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }
};

class Cart
{
    private:
    string itemName;
    int serialNum;

    public:
        void setItem(string itemName)
        {
            this->itemName = itemName;
        }

        void setSerialNum(int serialNum)
        {
            this->serialNum = serialNum;
        }

        string getItem()
        {
            return itemName;
        }

        int getSerialNum()
        {
            return serialNum;
        }
        
};

template <typename T>
class ListNode
{
    private:
        Cart itemInfo;
        ListNode *next;
        ListNode *previous;
    
    public:
        ListNode getItem () const
        {
            return this->itemInfo;
        }

        ListNode getNext () const
        {
            return this->next;
        }

        ListNode getPrevious () const
        {
            return this->previous;
        }

        ListNode setData (Cart nodeItem)
        {
            itemInfo = nodeItem;
            next = NULL;
            previous = NULL;
        }

        void nextNode (ListNode* head, ListNode* tail)
        {
            if (head != NULL)
            {
                cout << head->data << endl;

                nextNode (head->next);
            }

            else 
            {
                cout << "At the beginning of the cart\n";
                next->data = tail->data;
            }
        }

};
#endif