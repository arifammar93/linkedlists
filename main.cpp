/**
    Author: Ammar Arif
    Feb 2018
    Purpose: The file contains implementation of Ordered Singly and Doubly linked list classes.
    Doubly Linked List inherits from Singly lists.
    Contains implementation of sorted insert, delete and search functions for both lists.
*/
#include "iostream"

using namespace std;

struct node {
    double data;
    node* next = nullptr;
    node* prev = nullptr;
};

class singleLinkedList
{
private:

public:
    node* head = nullptr;

    // Prints list data to screen
    void Read()
    {
        node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " " ;
            temp = temp->next;
        }
    }

    // Searches and returns the node containing desired data. If not present, returns Not Found.
    node* Search(double data)
    {
        node* current = head;
        while (current->next != nullptr)
        {
            if (current->data == data)
            {
                return current;
            }
            current = current->next;

        }

        cout << data << " Not Found." << endl;

        return nullptr;
    }

    // Inserts node in a sorted order
    void Insert(double data)
    {
        if (head == nullptr) // if list is empty
        {
            node* temp;
            node* n = new node;
            head = n;
            head->data = data;
            temp = n;
        }
        else if (data < head->data) // if to be inserted before head node
        {
            node* temp;
            node* n = new node;
            n->data = data;
            n->next = head;
            head = n;
        }
        else // in case to be added after head node
        {
            node* n = new node;
            n->data = data;

            node* trailing = head;
            node* current = head->next;
            while (current != nullptr && data > current->data)
            {
                trailing = current;
                current = current->next;
            }
            trailing->next = n;
	        n->next = current;

        }

    }
};

class doubeLinkedList: public singleLinkedList
{

public:

    // Inserts node in doubly linked list in a sorted order
    void Insert(double data)
    {
        if (head == nullptr) // if list is empty
        {
            node* n = new node;
            n->data = data;
            head = n;
        }
        else if (data < head->data) // if to be added before head node
        {
             node* temp = head;
             node* n = new node;
             n->data = data;
             n->next = head;
             head = n;
             temp->prev = n;
        }
        else // in case to be added after head node
        {
            node* current = head;
            node* n = new node;
            n->data = data;
            while (current->next != nullptr && current->next->data < n->data)
            {
                current = current->next;
            }
            n->next = current->next;


            if (current->next != nullptr)
            {
                n->next->prev = n;
            }

            current->next = n;
            n->prev = current;
        }
    }

    // Deletes node containing desired data. If not found, prints Not Found.
    void Delete(double data)
    {
        node* current = Search(data);
        if (current == nullptr)
        {
            return;
        }
        else
        {
            cout << "Deleting " << current->data << endl;
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }


    }

};

int main()
{
    doubeLinkedList L;
    L.Insert(54.15);
    L.Insert(11.42);
    L.Insert(12.19);
    L.Insert(83.40);
    L.Insert(15.27);
    L.Insert(60.17);
    L.Insert(-63.81);
    L.Insert(-1.394);
    L.Insert(-22.60);

    L.Read();
    cout<< endl;
    L.Delete(12.19);
    L.Delete(27.33);
    L.Read();


}