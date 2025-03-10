#ifndef MEMORY_TRACKER_HPP
#define MEMORY_TRACKER_HPP

#include <iostream>
#include <cstdlib>

class MemoryTracker {
public:
    /**
     * @brief Tracks the total memory allocated and deallocated by the program.
     */
    static inline size_t allocatedMemory = 0;

    /**
     * @brief Tracks the total memory deallocated by the program.
     */
    static inline size_t deallocatedMemory = 0;

    /**
     * @brief Reports the memory allocated and deallocated by the program.
     */
    static void report() {
        std::cout << "Allocated Memory: " << allocatedMemory << " bytes\n";
        std::cout << "Deallocated Memory: " << deallocatedMemory << " bytes\n";
        if (allocatedMemory == deallocatedMemory) {
            std::cout << "No memory leaks detected.\n";
        }
        else {
            std::cout << "Memory leak detected: " << (allocatedMemory - deallocatedMemory) << " bytes not freed.\n";
        }
    }
};

//--------------- Macros for platform-specific memory allocation functions ---------------//
#if defined(_WIN32)  // Windows
#include <malloc.h>
#define GET_ALLOCATED_SIZE(ptr) _msize(ptr)
#elif defined(__linux__)  // Linux
#include <malloc.h>
#define GET_ALLOCATED_SIZE(ptr) malloc_usable_size(ptr)
#else
#error "Unsupported platform"
#endif
//----------------------------------------------------------------------------------------//

// Overload the new operator to log memory allocation for single objects
void* operator new(size_t size) {
    MemoryTracker::allocatedMemory += size;
    return malloc(size);
}

// Overload the new[] operator to log memory allocation for arrays
void* operator new[](size_t size) {
    MemoryTracker::allocatedMemory += size;
    return malloc(size);
}

// Overload the delete operator to log memory deallocation for single objects
void operator delete(void* memory, size_t size) noexcept {
    if (!memory) return;
    MemoryTracker::deallocatedMemory += size;
    free(memory);
}

// Overload the delete[] operator to log memory deallocation for arrays
void operator delete[](void* memory) noexcept {
    if (!memory) return;
    size_t size = GET_ALLOCATED_SIZE(memory);
    MemoryTracker::deallocatedMemory += size;
    free(memory);
}

#endif  // MEMORY_TRACKER_HPP