/********************************************************************************************
 ** $File: DeAlloc.cpp
 ** $Version: #1.0
 ** $DateTime: 22/09/2022
 ** $Description: deDeAllocation Utility Functions
 ** $Author: Ibrahim Koicha
********************************************************************************************/
#include <iostream>
#include "Dealloc.h"

using namespace std;

DeAlloc::DeAlloc()
{
    //Default Constructor
}

// Setting default values of static variables
size_t DeAlloc::totalDeAllocByteSize = 0;
int DeAlloc::no_deAllocs = 0;

/********************************************************************************************
 ** Constructor with Parameters
*********************************************************************************************/
DeAlloc::DeAlloc(void *ptr)
{
    totalDeAllocByteSize += sizeof(DeAlloc);
    mem_ptr = ptr;
    no_deAllocs++;
}

/********************************************************************************************
 ** $Function Name:- setMemPointer()
 ** $Description:- Function to set Memory Pointer/Reference
 ** $Parameters:- void pointer
 ** $Return Type:- void
*********************************************************************************************/
void DeAlloc::setMemPointer(void *ptr)
{
    this->mem_ptr = ptr;
}

/********************************************************************************************
 ** $Function Name:- getMemPointer()
 ** $Description:- Function to return the Memory Pointer/Reference
 ** $Parameters:- void
 ** $Return Type:- void pointer
*********************************************************************************************/
void *DeAlloc::getMemPointer()
{
    return mem_ptr;
}

/********************************************************************************************
 ** $Function Name:- getDeAllocSize()
 ** $Description:- Function to Set DeAllocation Size
 ** $Parameters:- size_t
 ** $Return Type:- void
*********************************************************************************************/
void DeAlloc::setDeAllocSize(size_t size)
{
    this->size = size;
}

/********************************************************************************************
 ** $Function Name:- getDeAllocSize()
 ** $Description:- Function to return the size
 ** $Parameters:- void
 ** $Return Type:- size_t
*********************************************************************************************/
size_t DeAlloc::getDeAllocSize()
{
    return size;
}