/***************************************************************************************************************************
** $File: TrackDeallocation.cpp
** $Version: #1.0
** $DateTime: 23/09/2022
** $Description:
   HMT_07:
   Library containing interface to query and display the details of all deallocations in a formatted way consisting of:
   1. Deallocation Size (bytes)
   2. Total number of deallocations
   3. Total deallocation size (bytes)
   HMT_08:
   Library provides utility functions to:
   1.empty the deallocation list
** $Author: Nandini Jadi
************************************************************************************************************************/
#include <iostream>
#include <string.h>
#include "LinkedList.cpp"
#include "trackDealloc.h"
#include "debuglogger.h"
using namespace std;

LinkedList<DeAlloc *> DeAlloc_list; // Deallocation list

/********************************************************************************************
 ** $Function Name:- trackDeAlloc
 ** $Description:- Function to Track Deallocation
 ** $Parameters:- size_t size, void *ptr
 ** $Return Type:- void
*********************************************************************************************/
void trackDeAlloc(size_t size, void *ptr)
{
    std::time_t result = std::time(nullptr);
    cout << "INFO: delete is called for " << size << " bytes of memory "
         << "at timestamp: " << std::asctime(std::localtime(&result));
}

/********************************************************************************************
 ** $Function Name:- AppendDeAllocNode
 ** $Description:- DeAllocate the reference to the already created memory node and 
                   handle exceptions
 ** $Parameters:- void *ptr, size_t Size
 ** $Return Type:- EXIT SUCCESS/EXIT FAILURE
*********************************************************************************************/
int appendDeAllocNode(void *ptr, size_t size)
{
    try
    {
        DeAlloc *dealloc = (DeAlloc *)malloc(sizeof(DeAlloc));
        if (dealloc == NULL)
        {
            DEBUG_LOG(3, "Memory not allocated, bad alloc occurs");
            throw bad_alloc();
        }
        dealloc->setMemPointer(ptr);
        dealloc->totalDeAllocByteSize += size;
        dealloc->no_deAllocs++;
        dealloc->setDeAllocSize(size);
        DeAlloc_list.insert(dealloc);
    }
    catch (bad_alloc &e)
    {
        DEBUG_LOG(4, e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/********************************************************************************************
 ** $Function Name:- DisplayDeAllocationDetails
 ** $Description:- Menu Driven case for DeAllocation Detail
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void displayDeAllocationDetails()
{
    char ch;
    string str;
    do
    {
        cout << "\n-------------------- MENU FOR DEALLOCATION DETAILS --------------------" << endl;
        cout << "a.Deallocation size(bytes)\nb.Total number of deallocations\nc.Total deallocation size(bytes)\nd.Show all(bytes)\n " << endl;
        cout << "\nEnter a choice: ";
        cin >> str;
        if (str.size() > 1)
        {
            ch = 'm';
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
            DeAlloc_list.getTotalHeapAllocatedSize();
            break;

        case 'b':
        case 'B':
            cout << endl;
            cout << "Total Number of deallocations: " << DeAlloc::no_deAllocs << endl;
            break;

        case 'c':
        case 'C':
            cout << endl;
            cout << "Total deallocation size(bytes): " << DeAlloc::totalDeAllocByteSize << endl;
            break;
        case 'd':
        case 'D':
            cout << endl;
            DeAlloc_list.getTotalHeapAllocatedSize();
            cout << "\nTotal Number of deallocations: " << DeAlloc::no_deAllocs << endl;
            cout << "\nTotal deallocation size(bytes): " << DeAlloc::totalDeAllocByteSize << endl;
            break;
        default:
            DEBUG_LOG(2, "Invalid input");
            break;
        }
        cout << "\nDo you want to continue?(y/n)" << endl;
        cin >> ch;
        // getchar();

    } while (ch == 'Y' || ch == 'y');
}

/********************************************************************************************
 ** $Function Name:- DeleteDeAllocList
 ** $Description:- Delete List After Execution
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void deleteDeallocList()
{
    cout << endl
         << "-------------------- DEALLOCATION LIST IS EMPTIED --------------------" << endl;
    DeAlloc_list.clearList();
}
