/********************************************************************************************
 ** $File: trackAlloc
 ** $Version: #1.0
 ** $DateTime: 22/09/2022
 ** $Description: Tracking newly allocated memory records
 ** $Author: Dixit Dobariya
********************************************************************************************/
#include <iostream>
#include <string.h>
#include "LinkedList.cpp"
#include "trackAlloc.h"
#include "debuglogger.h"
using namespace std;

LinkedList<Alloc *> alloc_list; //Allocation Linked List

/********************************************************************************************
 ** $Function Name:- trackAlloc
 ** $Description:- Function to Track Allocation
 ** $Parameters:- size_t size, void *ptr
 ** $Return Type:- void
*********************************************************************************************/
void trackAlloc(size_t size, void *ptr)
{
    time_t result = time(nullptr);

    cout << "INFO: new is called for " << size << " bytes of memory"
         << " at timestamp: " << asctime(localtime(&result));
}

/********************************************************************************************
 ** $Function Name:- AppendAllocNode
 ** $Description:- Allocate the reference to the newly created memory node and 
                   handle exceptions
 ** $Parameters:- void *ptr, size_t Size
 ** $Return Type:- EXIT SUCCESS/EXIT FAILURE
*********************************************************************************************/
int appendAllocNode(void *ptr, size_t size)
{
    try
    {
        Alloc *alloc = (Alloc *)malloc(sizeof(Alloc));
        if (alloc == NULL)
        {
            DEBUG_LOG(3, "Memory not allocated, bad alloc occurs");
            throw bad_alloc();
        }
        alloc->setMemPointer(ptr);
        alloc->totalAllocByteSize += size;
        alloc->no_allocs++;
        alloc->setAllocSize(size);
        alloc_list.insert(alloc);
    }
    catch (std::exception &e)
    {
        DEBUG_LOG(3, e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/********************************************************************************************
 ** $Function Name:- DisplayAllocationDetails
 ** $Description:- Menu Driven case for Allocation Detail
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void displayAllocationDetails()
{
    char ch;
    string str;
    do
    {
        cout << endl
             << "-------------------- MENU FOR ALLOCATION DETAILS --------------------" << endl;
        cout << "a.Allocation size(bytes)\nb.Total number of allocations\nc.Total allocation size(bytes)\nd.Show all(bytes)\n " << endl;
        cout << "\nEnter a choice: ";
        cin >> str;
        if (str.size() > 1)
        {
            ch = 'k';
        }
        else
        {
            ch = str[0];
        }
        switch (ch)
        {
        case 'a':
        case 'A':
            cout << endl;
            alloc_list.getTotalHeapAllocatedSize();
            break;

        case 'b':
        case 'B':
            cout << endl;
            cout << "Total number of allocations: " << Alloc::no_allocs << endl;
            break;

        case 'c':
        case 'C':
            cout << endl;
            cout << "Total allocation size(bytes): " << Alloc::totalAllocByteSize << endl;
            break;
        
        case 'd':
        case 'D':
            cout << endl;
            alloc_list.getTotalHeapAllocatedSize();
            cout << endl;
            cout << "Total number of allocations: " << Alloc::no_allocs << endl;
            cout << endl;
            cout << "Total allocation size(bytes): " << Alloc::totalAllocByteSize << endl;
            break;
        
        default:
            DEBUG_LOG(2, "Invalid input");
            break;
        }

        cout << "\nDo you want to continue:? (y/n)" << endl;
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');
}

/********************************************************************************************
 ** $Function Name:- DeleteAllocList
 ** $Description:- Delete List After Execution
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void deleteAllocList()
{
    alloc_list.clearList();
    cout << endl
         << "--------------------- ALLOCATION LIST IS EMPTIED ---------------------" << endl;
}