/* 
 * File:   LinkedList.h
 * Author: Anh (Andrew) Tran
 *
 * Created on May 22, 2017
 * 
 * BASIC LINKED LIST TEMPLATE CLASS
 * - add(value)         | appends a value to the end of the list
 *                      |
 * - add(index, value)  | adds a value to the specified index
 *                      |
 * - clear()            | removes every element from the list
 *                      |
 * - isEmpty()          | returns true if the list is empty
 *                      |
 * - print()            | prints the list using ostream << operator
 *                      |
 * - remove()           | retrieves the value at the beginning of the list
 *                      | then remove it from the list
 *                      |
 * - remove(value)      | retrieves matching value from the list then remove
 *                      | it from the list
 *                      |
 * - search(value)      | finds the index of the specified value in the list
 *                      |
 * - size()             | returns the size of the list
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
    struct ListNode
    {
        T payload;
        ListNode* next;
        
        ListNode (T value) 
        { 
            payload = value; 
            next = nullptr; 
        }
    };
    
    ListNode* head;
    int Size;
public:
    /*-----CONSTRUCTORS-----*/
    LinkedList()
    {
        head = nullptr;
        Size = 0;
    }
    
    // clears the list then delete the head
    ~LinkedList()
    {
        clear();
        delete head;
    }

    /*-----MODIFIERS-----*/
    // appends value to the end of the list by passing the index as the size
    void add(T value)
    {
        add (Size, value);
    }
    
    // add value to the specified index in the list
    void add(int index, T value)
    {
        Size++;                                     // increments the size
        
        // creates the new node
        ListNode* newNode = new ListNode(value); 
        if (isEmpty())          // if the list is empty then just set the head
                                // and finish
        {
            head = newNode;
            return;
        }
        
        // trackers
        ListNode* traverse = head;
        ListNode* previous = nullptr;
        int count = 0;
        
        // loop to find the specified index
        while (count != index && traverse != nullptr)
        {
            previous = traverse;
            traverse = traverse->next;
            count++;
        }
        
        if (index == 0)                 // if the index is 0 then manipulate the head
        {
            newNode->next = traverse;
            head = newNode;
        }
        else if (traverse == nullptr)   // if the index was not found then simply append
        {
            previous->next = newNode;
        }
        else                            // if the index is found 
        {
            newNode->next = traverse;
            previous->next = newNode;
        }
    }

    // removes the first the fist node of the list
    T remove()
    {
        if (isEmpty())
        {
            throw -1;
        }
        
        return remove (head->payload);
    }
    
    T remove(T value)
    {
        Size--;                         // decrease the size
        
        // trackers 
        ListNode* traverse = head;
        ListNode* previous = nullptr;
        
        // look for the value
        while (traverse != nullptr && traverse->payload != value)
        {
            previous = traverse;
            traverse = traverse->next;
        }
        
        // if the value is not found or the list is empty
        if (traverse == nullptr)
        {
            throw -1;
        }
        else if (traverse == head)          // if the value is right at the beginning
        {
            head = traverse->next;
        }
        else                                // if the value is in the middle
        {
            previous->next = traverse->next;
        }
        
        delete traverse;
        return value;
    }

    /*-----TRAVERSERS-----*/
    // prints the list using the ostream << operator
    void print()
    {
        // if the list is empty 
        if (isEmpty())
        {
            cout << "[]" << endl;
            return;
        }
        
        // tracker 
        ListNode* traverse = head;
        
        while (traverse->next != nullptr)
        {
            cout << traverse->payload;
            
            traverse = traverse->next;
        }
        cout << traverse->payload << endl;
    }
    
    // returns the index of the value if found
    int search(T value)
    {
        int count = 0;                  // tracker for index 
        ListNode* traverse = head;
        
        // finds the value 
        while (traverse != nullptr && traverse->payload != value)
        {
            traverse = traverse->next;
            count++;
        }
        
        if (traverse == nullptr)        // if it's not found 
        {
            return -1;
        }
        
        return count;
    }
    
    // clears the list's contents 
    void clear()
    {
        // tracker
        ListNode* traverse = head;
        
        // the old listnode swapperoo 
        while (traverse != nullptr)
        {
            ListNode* after = traverse->next;
            
            delete traverse;
            
            traverse = after;
        }
        
        head = nullptr;
    }
    
    /*-----HELPERS-----*/
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        
        return false;
    }
    
    int size()
    {
        return Size;
    }
};



#endif /* LINKEDLIST_H */
