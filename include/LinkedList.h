/********************************************************************************************
 ** $File: linkedlist.h
 ** $Version: #1.0
 ** $DateTime: 22/09/2022
 ** $Description: Header File for the Linked List Utility Functions
 ** $Author: Ibrahim Koicha
********************************************************************************************/
#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <iostream>
#include <string>
#include "Alloc.h"
#include "Dealloc.h"
using namespace std;

/**********************************************************************************
 ** $Class Name: LinkedList
 ** $Description: The class has following members:
                    1. LinkedList *head = NULL
                    2. LinkedList *curr = NULL
                    3. LinkedList *next = NULL
                    4. int size = 0
                    5. Class alloc_ptr
                    6. size_t t_alloc_size
**********************************************************************************/
template <class C>
class LinkedList
{
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

#endif