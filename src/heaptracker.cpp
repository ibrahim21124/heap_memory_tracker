/********************************************************************************************
** $File: tracker.cpp
** $Version: #1.0
** $DateTime: 26/09/2022
** $Description: The main purpose of tracker file is to track the overall usage of memory
        being allocated/deallocated/freed and maintain allocation and deallocatio 
        details in a data structures.
    HMT/09: Library to provide an interface to dump of total heap usage statistics 
        which shall contain:
        a. Total memory allocated (bytes)  // cumulative sum of all allocation 
            sizes, since the start of the application
        b. Total memory freed (bytes)   // cumulative sum of all free since the 
            start of the application 
        c. Memory currently in use (bytes) // (Total allocation - Memory freed)     
** $Author: Divyarajsinh Rana & Ronak Vavwala
********************************************************************************************/
#include <iostream>
#include <memory>
#include "trackAlloc.cpp"
#include "trackDealloc.cpp"
#include "debuglogger.h"
using namespace std;

static char choice; //User Choice for the Menu Driven Program

/********************************************************************************************
 ** $Function Name:- heap_tracker_init
 ** $Description:- Function to Initialize the Heap Tracker
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void heap_tracker_init(void)
{
    cout << endl
         << "-------------------- HEAP TRACKER INITIALISED --------------------" << endl
         << endl;
    
    iferror:

        cout << "Do You want to Enable heap track ? (y/n): ";
        string str;
        cin >> str;

        if (str.size() > 1)
        {
            DEBUG_LOG(3, "Invalid choice");
            goto iferror;
        }
        if (str[0] == 'Y' || str[0] == 'y' || str[0] == 'N' || str[0] == 'n')
        {
            choice = str[0];
        }
        else
        {
            DEBUG_LOG(3, "Invalid choice");
            goto iferror;
        }
}

/********************************************************************************************
 ** $Function Name:- operator new
 ** $Description:- Overrides new operator and call trackAlloc and appendAllocNode functions
 ** $Parameters:- size
 ** $Return Type:- void
*********************************************************************************************/
void *operator new(size_t size)
{
    void *ptr;
    try
    {
        ptr = malloc(size);
        if (ptr == NULL)
        {
            throw bad_alloc();
        }

        if (choice == 'n' || choice == 'N')
        {
            return ptr;
        }

        trackAlloc(size, ptr);
        appendAllocNode(ptr, size);
    }
    catch (const std::exception &e)
    {
        DEBUG_LOG(4, e.what());
    }
    return ptr;
}

/********************************************************************************************
 ** $Function Name:- operator new[]
 ** $Description:- Overrides new[] operator and call trackAlloc and appendAllocNode functions
 ** $Parameters:- size
 ** $Return Type:- void
*********************************************************************************************/
void *operator new[](size_t size)
{
    void *ptr;
    try
    {
        ptr = malloc(size);
        if (ptr == NULL)
        {
            throw bad_alloc();
        }
        if (choice == 'n' || choice == 'N')
        {
            return ptr;
        }
        trackAlloc(size, ptr);
        appendAllocNode(ptr, size);
    }
    catch (const std::exception &e)
    {
        DEBUG_LOG(4, e.what());
    }
    return ptr;
}

/********************************************************************************************
 ** $Function Name:- operator delete
 ** $Description:- Overrides delete operator and call trackDeAlloc and appendDeAllocNode functions
 ** $Parameters:- void *ptr, size_t size
 ** $Return Type:- void
*********************************************************************************************/
void operator delete(void *ptr, size_t size)
{
    if (choice == 'N' || choice == 'n')
    {
        free(ptr);
        return;
    }

    trackDeAlloc(size, ptr);
    appendDeAllocNode(ptr, size);
    free(ptr);
}

/********************************************************************************************
 ** $Function Name:- operator delete[]
 ** $Description:- Overrides delete[] operator and call trackDeAlloc and appendDeAllocNode functions
 ** $Parameters:- void *ptr, size_t size
 ** $Return Type:- void
*********************************************************************************************/
void operator delete[](void *ptr, size_t size)
{
    cout << "Inside delete[]" << endl;
    free(ptr);
}

/********************************************************************************************
 ** $Function Name:- GetTotalAllocation
 ** $Description:- Prints Total memory allocated in bytes
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void GetTotalAllocation(void)
{
    cout << "a. Total memory allocated (bytes): " << Alloc::totalAllocByteSize << endl;
}

/********************************************************************************************
 ** $Function Name:- GetTotalFreed
 ** $Description:- Prints Total freed memories in bytes  
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void GetTotalFreed(void)
{
    cout << "b. Total memory freed (bytes): " << DeAlloc::totalDeAllocByteSize << endl;
}

/********************************************************************************************
 ** $Function Name:- GetMemoryInUse
 ** $Description:- Prints Memory currently in use in bytes   
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void GetMemoryInUse(void)
{
    cout << "c. Memory currently in use (bytes): " << (Alloc::totalAllocByteSize - DeAlloc::totalDeAllocByteSize) << endl;
}

/********************************************************************************************
 ** $Function Name:- total_heap_usage_statistics
 ** $Description:- Calls GetTotalAllocation(),GetTotalFreed(),GetMemoryInUse()  
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void total_heap_usage_statistics(void)
{
    cout << endl;
    DEBUG_LOG(1, "Interface to dump of total heap usage statistics");
    cout << endl;
    GetTotalAllocation();
    GetTotalFreed();
    GetMemoryInUse();
}

/********************************************************************************************
 ** $Function Name:- heap_tracker_stats
 ** $Description:- Displays main menu if tracker is enabled   
 ** $Parameters:- void
 ** $Return Type:- void
*********************************************************************************************/
void heap_tracker_stats(void)
{
    if (choice == 'N' || choice == 'n')
    {
        DEBUG_LOG(1, "Heap tracker is disabled");
        cout << endl
             << "-------------------- HEAP TRACKER DISABLED --------------------" << endl;
        return;
    }
    char ch;
    string str;

    do
    {
        cout << endl
             << "-------------------- DISPLAY MENU STARTS --------------------" << endl;
        cout << "\na. Display Allocation Details" << endl
             << "b. Display Deallocation Details" << endl
             << "c. Display heap usage statistics" << endl
             << endl;
        cout << "Enter choice: ";
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
            displayAllocationDetails();
            break;

        case 'b':
        case 'B':
            displayDeAllocationDetails();
            break;

        case 'c':
        case 'C':
            total_heap_usage_statistics();
            break;

        default:
            DEBUG_LOG(3, "Invalid choice");
            break;
        }
        cout << "\nDo you want to see menu again?(y/n)" << endl;
        cin >> str;
        if (str.size() > 1)
        {
            ch = 'k';
        }
        else
        {
            ch = str[0];
        }
    } while (ch == 'Y' || ch == 'y');
    cout << endl
         << "------------------------- DISPLAY MENU ENDS --------------------------" << endl;
    cout << endl
             << "----------------------- HEAP TRACKER DISABLED -----------------------" << endl;
    deleteAllocList();
    deleteDeallocList();
}
