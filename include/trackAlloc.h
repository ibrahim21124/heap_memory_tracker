/********************************************************************************************
 ** $File: trackalloc.h
 ** $Version: #1.0
 ** $Date: 22/09/2022
 ** $Description: Header File for Tracking Allocations
 ** $Author: DIXIT DOBARIYA
********************************************************************************************/
#ifndef TRACK_ALLOC
#define TRACK_ALLOC

#include <bits/stdc++.h>
#include "Alloc.h"

using namespace std; 

void trackAlloc(size_t size, void *ptr); //to keep the track for the user updated of memory allocations.
int appendAllocNode(void *ptr, size_t size); //To Append the given Linked List memory pointer
void displayAllocationDetails(); //Displaying menu for allocation details
void deleteAllocList(); //Deleting the list after execution

#endif //TRACK_ALLOC