#ifndef ALLOC
#define ALLOC

#include <iostream>
using namespace std;

/**********************************************************************************
 ** $Class Name: Alloc
 ** $Description: The class has following members:
                    1. void *mem_ptr
                    2. size_t size
                    3. static size_t totalDeAllocByteSize
                    4. static int no_allocs
 **********************************************************************************/
class Alloc
{
    private:
        void *mem_ptr;
        size_t size;
    public:
        Alloc();
        virtual ~Alloc() = default;
        static size_t totalAllocByteSize;
        static int no_allocs;
        Alloc(void *ptr);
        void *getMemPointer();
        void setMemPointer(void *ptr);
        void setAllocSize(size_t size);
        size_t getAllocSize();
};

#endif //ALLOC