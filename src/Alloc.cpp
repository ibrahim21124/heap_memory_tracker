/********************************************************************************************
 ** $File: alloc.cpp
 ** $Version: #1.0
 ** $DateTime: 22/09/2022
 ** $Description: Allocation Utility Functions
 ** $Author: Ibrahim Koicha
********************************************************************************************/
#include <iostream>
#include "Alloc.h"

using namespace std;

Alloc::Alloc()
{
    //Default Constructor
}

//Setting default values of static variables
size_t Alloc::totalAllocByteSize = 0;
int Alloc::no_allocs = 0;

/********************************************************************************************
 ** Constructor with Parameters
*********************************************************************************************/
Alloc::Alloc(void *ptr)
{
    totalAllocByteSize += sizeof(Alloc);
    mem_ptr = ptr;
    no_allocs++;
}
    
/********************************************************************************************
 ** $Function Name:- setMemPointer()
 ** $Description:- Function to set Memory Pointer/Reference
 ** $Parameters:- void pointer
 ** $Return Type:- void
*********************************************************************************************/
void Alloc::setMemPointer(void *ptr)
{
    this->mem_ptr = ptr;
}

/********************************************************************************************
 ** $Function Name:- getMemPointer()
 ** $Description:- Function to return the Memory Pointer/Reference
 ** $Parameters:- void
 ** $Return Type:- void pointer
*********************************************************************************************/
void *Alloc::getMemPointer()
{
    return mem_ptr;
}

/********************************************************************************************
 ** $Function Name:- getAllocSize()
 ** $Description:- Function to Size Allocation Size
 ** $Parameters:- size_t
 ** $Return Type:- void
*********************************************************************************************/
void Alloc::setAllocSize(size_t size)
{
    this->size = size;
}

/********************************************************************************************
 ** $Function Name:- getAllocSize()
 ** $Description:- Function to return the size
 ** $Parameters:- void
 ** $Return Type:- size_t
*********************************************************************************************/
size_t Alloc::getAllocSize()
{
    return size;
}