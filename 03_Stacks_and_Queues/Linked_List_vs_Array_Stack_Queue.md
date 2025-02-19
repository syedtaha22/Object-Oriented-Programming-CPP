# Linked List vs. Array-Based Stack & Queue

This document compares linked list and array-based implementations of stacks and queues in terms of **time complexity** and **memory usage**.

## Time Complexity Comparison

### Push (Stack) / Enqueue (Queue)

| Operation          | Linked List (Stack/Queue) | Resizable Array (Stack/Queue) |
|--------------------|:-------------------------:|:-----------------------------:|
| **Best Case**      | O(1)                      | O(1)                          |
| **Amortized Case** | O(1)                      | O(1)                          |
| **Worst Case**     | O(1)                      | O(N) (resize needed)          |

- **Linked List:** Adding an element requires allocating memory and updating pointers.
- **Resizable Array:** If the array is full, resizing to a larger array (copying N elements) takes O(N) time.


### Pop (Stack) / Dequeue (Queue)

| Operation          | Linked List (Stack/Queue) | Resizable Array (Stack/Queue) |
|--------------------|:-------------------------:|:-----------------------------:|
| **Best Case**      | O(1)                      | O(1)                          |
| **Amortized Case** | O(1)                      | O(1)                          |
| **Worst Case**     | O(1)                      | O(N) (resizing)               |

- **Linked List:** Removing the first element is always O(1), but freeing memory may take additional time.
- **Resizable Array** If the array is resized, copying N elements takes O(N) time.

## Memory Usage Comparison

### Linked List Implementation
Each node in a linked list consists of:
- **Data field** (`m` bytes)
- **Pointer to next node** (8 bytes for a pointer in a 64-bit system)

**Total memory per node:** `(m + 8) bytes`

For **N** elements, total memory usage:`(m + 8) * N` or O(N) memory.

This results in extra memory overhead due to the pointer storage and fragmentation in dynamic allocation.

### Array-Based Implementation
A contiguous array for a stack or queue consists of:
- **Data field** (`m` bytes per element in the array)
- **Wasted memory** (unutilized space due to resizing)

**Total memory usage for N elements:**`m * N` or O(N) memory.

In the worst case, only 1/4th of the array is utilized, leading to ~75% wasted memory.

## Summary
| Aspect                         | Linked List   | Resizable Array              |
|--------------------------------|:-------------:|:----------------------------:|
| **Push/Enqueue Complexity**    | O(1)          | O(1), (O(N) if resized)      |
| **Pop/Dequeue Complexity**     | O(1)          | O(1)                         |
| **Memory Usage (Per Element)** | `m + 8`       | `m`                          |
| **Memory Growth**              | Linear `O(N)` | Linear `O(N)` + wasted space |

### Conclusion
- **Linked List is preferable when:** Memory is not a concern, and fast O(1) insertions/removals are required without worrying about resizing.
- **Array-Based Stack/Queue is preferable when:** Memory efficiency is more critical, and resizing overhead is manageable.

By understanding these trade-offs, you can choose the appropriate data structure based on your application's requirements.

Refer to [practice questions](practice_questions/practice.md) to test your understanding of stacks and queues.
And for full implementations, refer to [examples/](examples/).