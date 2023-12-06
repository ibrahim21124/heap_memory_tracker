/********************************************************************************************
 ** $File: trackdealloc.h
 ** $Version: #1.0
 ** $Date: 23/09/2022
 ** $Description: Header File for Tracking Deallocations.
 ** $Author: Nandini Jadi
********************************************************************************************/
#ifndef TRACK_DEALLOC
#define TRACK_DEALLOC

#include <bits/stdc++.h>
#include "Dealloc.h"

using namespace std; 

void trackDeAlloc(size_t size, void *ptr); //to keep the track for the user updated of memory deallocations.
int appendDeAllocNode(void *ptr, size_t size); //To Append the given Linked List memory pointer
void displayDeAllocationDetails(); //Displaying menu for deallocation details
void deleteDeallocList(); //Deleting the list after execution

#endif //TRACK_DEALLOC