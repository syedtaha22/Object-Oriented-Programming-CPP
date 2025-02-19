# Queues

A **queue** is a linear data structure that follows the **First In, First Out (FIFO)** principle. This means that the first element added to the queue is the first one to be removed.

## Key Characteristics of a Queue  
1. **FIFO Order** – The earliest added element is removed first.
2. **Restricted Access** – Elements are added (enqueued) at the back and removed (dequeued) from the front.
3. **Fixed or Dynamic Size** – Can be implemented using a fixed-size array or a dynamically growing structure.
4. **Operations in Constant Time** – Enqueue and dequeue operations take **O(1)** time complexity in a properly managed queue.

## Real-World Applications of Queues  
Queues are widely used in various applications, including:

### 1. Process Scheduling  
Operating systems use queues for scheduling tasks. For example, a **CPU scheduler** maintains a queue of processes waiting to be executed.

### 2. Print Spooling  
When multiple documents are sent to a printer, they are stored in a queue and printed in the order they were received.

### 3. Breadth-First Search (BFS)  
Graph traversal algorithms, such as BFS, utilize a queue to explore nodes level by level.

### 4. Network Packet Processing  
Routers and switches use queues to manage data packets, ensuring they are processed in the order they arrive.

### 5. Customer Service Systems  
Call centers and service desks use queues to manage customer requests, ensuring they are attended to in the order received.

## Queue Operations  
1. **Enqueue(x)** – Adds element `x` to the back of the queue.
2. **Dequeue()** – Removes and returns the front element.
3. **Front()** – Returns the front element without removing it.
4. **isEmpty()** – Checks if the queue is empty.
5. **Size()** – Returns the number of elements in the queue.

---

## Next Steps  
Now that we understand what a queue is and its applications, we will explore its **implementation** using a **resizing array**.

Continue reading: [Queue Implementation using a Resizing Array](Resizing_Array_Queue.md).  
Or: [Queue Implementation using a Linked List](Linked_List_Queue.md).  

Or look at a comparison between Linked List Implementation of Stack/Queues and Array Implementation of Stack/Queues: [Comparison of Linked List and Array Implementations](Linked_List_vs_Array_Stack_Queue.md).

