/********************************************************************************************
 ** $File: LinkedList.cpp
 ** $Version: #1.0
 ** $DateTime: 22/09/2022
 ** $Description: val Structure for Keeping Track for Allocations and Deallocations
    HMT/08: Tracker shall track all delete calls  and maintain the  deallocation  details 
            in a val structure which  can be queried to serve the  user requests.
 ** $Author: Ibrahim Koicha
********************************************************************************************/
#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <iostream>
#include <string>
#include "Alloc.h"
#include "Dealloc.h"
#include "debuglogger.h"
using namespace std;

// Class
// To represent LinkedList using template by class
// taking class in template
template <class C>
class LinkedList
{
    // Public access modifier
    private:
        // Taking data member head
        LinkedList *head = NULL;
        LinkedList *curr = NULL;
        LinkedList *next = NULL;
        int size = 0;

    // Public access modifier
    public:
        C allocs_ptr;
        size_t t_alloc_size;
        LinkedList(); // Default constructor
        virtual ~LinkedList() = default; //Default Destructor
        int getSize(); // To get the size of linkedlist
        int insert(C k);// To add element to LinkedList which can be any type using LinkedList insert() operation
        void displayList(); //Display the LinkedList
        bool isEmpty(); // To check whether LinkedList is empty using isEmpty() method
        int getTotalHeapAllocatedSize(); //Generic function for to get total heap allocation/deallocation size
        void clearList(); //Generic function for to clear list
};


/********************************************************************************************
 ** Default Constructor
*********************************************************************************************/
template <class C> LinkedList<C>::LinkedList()
{
    head = NULL;
    size = 0;
}

/********************************************************************************************
 ** $Function Name:- getSize()
 ** $Description:- Function to return the size of the Linked List
 ** $Parameters:- void
 ** $Return Type:- int size
*********************************************************************************************/
template <class C> int LinkedList<C>::getSize()
{
    return size;
}

/********************************************************************************************
 ** $Function Name:- insert()
 ** $Description:- Insert node in the Linked List
 ** $Parameters:- T val
 ** $Return Type:- EXIT_FAILURE/EXIT_SUCCESS
*********************************************************************************************/
template <class C> int LinkedList<C>::insert(C k)
{
    // Now, adding element to LinkedList
    if (head == NULL)
    {
        try
        {
            head = (LinkedList *)malloc(sizeof(LinkedList));
            if (head == NULL)
            {
                throw bad_alloc();
            }
            head->allocs_ptr = k;
            curr = head;
            size++;
        }
        catch (const std::bad_alloc &e)
        {
            DEBUG_LOG(3, e.what());
            return EXIT_FAILURE;
        }
    }
    else
    {
        try
        {
            curr->next = (LinkedList *)malloc(sizeof(LinkedList));
            if (curr == NULL)
            {
                throw bad_alloc();
            }
            curr = curr->next;
            curr->allocs_ptr = k;
            curr->next = NULL;
            size++;
        }
        catch (const std::exception &e)
        {
            DEBUG_LOG(3, e.what());
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

/********************************************************************************************
 ** $Function Name:- getTotalHeapAllocatedSize() for Alloc Class
 ** $Description:- Function to get the Total Heap Allocation
 ** $Parameters:- void
 ** $Return Type:- EXIT_SUCCESS/EXIT_FAILURE
*********************************************************************************************/
template <> int LinkedList<Alloc *>::getTotalHeapAllocatedSize()
{
    if (isEmpty())
    {
        DEBUG_LOG(2, "Allocation list in empty");
    }
    else
    {
        LinkedList *temp = head;
        while (temp != NULL)
        {
            cout << "INFO: [Allocation at address] " << temp->allocs_ptr->getMemPointer()
                 << " is done of size " << temp->allocs_ptr->getAllocSize() << " bytes." << endl;
            temp = temp->next;
        }
    }
    return EXIT_SUCCESS;
}

/********************************************************************************************
 ** $Function Name:- getTotalHeapAllocatedSize() for Dealloc Class
 ** $Description:- Function to get the Total Heap Allocation
 ** $Parameters:- void
 ** $Return Type:- EXIT_SUCCESS/EXIT_FAILURE
*********************************************************************************************/
template <> int LinkedList<DeAlloc *>::getTotalHeapAllocatedSize()
{
    if (isEmpty())
    {
        DEBUG_LOG(2, "Deallocation list in empty");
    }
    else
    {
        LinkedList *temp = head;
        while (temp != NULL)
        {
            cout << "INFO: [Deallocation at address] " << temp->allocs_ptr->getMemPointer()
                 << " is done of size " << temp->allocs_ptr->getDeAllocSize() << " bytes." << endl;
            temp = temp->next;
        }
    }
    return EXIT_SUCCESS;
}

/********************************************************************************************
 ** $Function Name:- clearList()
 ** $Description:- Function to Clear the Linked List
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
template <class C> void LinkedList<C>::clearList()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        LinkedList *current = head;
        LinkedList *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
            size--;
        }

        head = NULL;
    }
}

/********************************************************************************************
 ** $Function Name:- isEmpty()
 ** $Description:- Check if the Linked List is Empty
 ** $Parameters:- C val(Class Object)
 ** $Return Type:- 0/1
*********************************************************************************************/
template <class C> bool LinkedList<C>::isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

/********************************************************************************************
 ** $Function Name:- displayList()
 ** $Description:- Display Contents of the Linked List
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
template <class C> void LinkedList<C>::displayList()
{
    if (isEmpty())
    {
        DEBUG_LOG(1, "Allocation list is empty!");
    }
    else
    {
        LinkedList *temp = head;
        while (temp != NULL)
        {
            cout << temp->allocs_ptr << endl;
            temp = temp->next;
        }
    }
}

#endif