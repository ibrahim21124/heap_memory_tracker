/********************************************************************************************
 ** $File:- tracker.h
 ** $Version:- #1.0
 ** $Date:- 26/09/2022
 ** $Description:- Header File for the Tracker
 ** $Author:- Divyarajsinh Rana & Ronak Vavwala
********************************************************************************************/
#ifndef TRACKER
#define TRACKER

#include <iostream>

void heap_tracker_init(void); //Function to Initialize the Heap Tracker
void *operator new(size_t); //Overrides new operator and call trackAlloc and appendAllocNode functions
void *operator new[](size_t); //Overrides new[] operator and call trackAlloc and appendAllocNode functions
void operator delete(void *, size_t); //Overrides delete operator and call trackDeAlloc and appendDeAllocNode functions
void operator delete[](void *ptr, size_t size); //Overrides delete[] operator and call trackDeAlloc and appendDeAllocNode functions
void GetTotalAllocation(void); //Prints Total memory allocated in bytes
void GetTotalFreed(void); //Prints Total freed memories in bytes
void GetMemoryInUse(void); //Prints Memory currently in use in bytes
void total_heap_usage_statistics(void); //Calls GetTotalAllocation(),GetTotalFreed(),GetMemoryInUse()
void heap_tracker_stats(void); //Displays main menu if tracker is enabled

#endif //TRACKER