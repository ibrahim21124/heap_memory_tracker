#ifndef DEALLOC
#define DEALLOC

#include <iostream>

/**********************************************************************************
 ** $Class Name: DeAlloc
 ** $Description: The class has following members:
                    1. void* mem_ptr
                    2. size_t size
                    3. static size_t totalDeAllocByteSize
                    4. static int no_deAllocs
 **********************************************************************************/
using namespace std;
class DeAlloc
{
    private:
        void *mem_ptr;
        size_t size;
    public:
        DeAlloc();
        virtual ~DeAlloc() = default;
        static size_t totalDeAllocByteSize;
        static int no_deAllocs;
        DeAlloc(void *ptr);
        void *getMemPointer();
        void setMemPointer(void *ptr);
        void setDeAllocSize(size_t size);
        size_t getDeAllocSize();
};

#endif //DEALLOC