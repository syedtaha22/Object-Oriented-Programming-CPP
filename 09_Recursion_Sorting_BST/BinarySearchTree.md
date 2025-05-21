# Binary Search Trees (BSTs)

A **Binary Search Tree (BST)** is a fundamental data structure in computer science, representing a special type of **binary tree** that organizes its elements in a sorted manner. This inherent ordering makes BSTs incredibly efficient for various operations, particularly searching, insertion, and deletion.

Each **node** within a BST holds a **key** (or value) and adheres to specific properties that define the tree's sorted structure:

* The **left subtree** of any given node contains only nodes whose keys are **less than** the key of the current node.
* The **right subtree** of any given node contains only nodes whose keys are **greater than** the key of the current node.
* Crucially, both the left and right subtrees must themselves also be valid binary search trees.

These properties ensure that an in-order traversal of a BST will always yield the keys in ascending order. When a BST remains relatively **balanced** (meaning its height is proportional to the logarithm of the number of nodes), these operations typically execute in **O(log n)** time, offering significantly better performance than linear data structures for large datasets. However, in their simplest form, BSTs can become **skewed** (resembling a linked list), degrading performance to **O(n)** in the worst case.

---

## Core BST Operations

Working with a BST involves several key operations, each leveraging the tree's unique ordering properties.

### 1. Insertion

Inserting a new value into a BST involves a straightforward recursive (or iterative) process. You start at the root and compare the value to be inserted with the current node's key. If the new value is smaller, you insert at the left child; if larger, you insert at the right child. This continues until an empty spot (a `null` child pointer) is found, where the new node is then placed.

**Conceptual Process:**

* **Start at the Root:** Begin the insertion process from the tree's root node.
* **Compare and Descend:**
    * If the value you want to insert is less than the current node's key, attempt to insert it into the left subtree.
    * If the value is greater than the current node's key, attempt to insert it into the right subtree.
* **Base Case (Found Spot):** If you encounter a `null` pointer (meaning there's no child in that direction), you've found the correct position; create a new node with your value and attach it there.

**Pseudocode Structure:**
```
insert(node, value):
    if node is null:
        create a new node with value, and assign it to node
    if value < node.value:          // If the value is less than the current node's value
        insert(node.left, value)    // Insert into the left subtree
    
    else if value > node.value:     // If the value is greater than the current node's value
        insert(node.right, value)   // Insert into the right subtree
    
    // If the value is equal, do nothing (BSTs typically do not allow duplicates)
```

* **Time Complexity:**
    * **Best/Average Case: O(log n)**. This occurs when the tree is balanced, and the path from the root to the insertion point is short.
    * **Worst Case: O(n)**. This happens when the tree becomes completely skewed (e.g., if elements are inserted in strictly ascending or descending order), effectively turning the tree into a linked list.
* **Space Complexity:** **O(h)**, where `h` is the height of the tree. This accounts for the recursion stack depth during the traversal.

---

### 2. Deletion

Deleting a node from a BST is the most complex operation, as it must maintain the BST properties after removal. There are three main cases to consider:

1.  **Leaf Node (No Children):** This is the simplest case. Just remove the node and set its parent's corresponding child pointer to `null`.
2.  **Node with One Child:** Replace the node to be deleted with its single child. The child's subtree then takes the deleted node's place.
3.  **Node with Two Children:** This is the trickiest case. You cannot simply remove the node as it would disconnect two subtrees. Instead:
    * Find the **inorder successor** of the node to be deleted. The inorder successor is the smallest node in its right subtree (or the largest node in its left subtree, known as the inorder predecessor).
    * Copy the key of the inorder successor to the node being deleted.
    * Recursively delete the inorder successor from the right subtree (which will fall into one of the first two simpler deletion cases).

**Conceptual Process (for node with two children):**

* Locate the node to be deleted.
* If it has two children, find its inorder successor (the leftmost node in its right subtree).
* Copy the inorder successor's value to the current node.
* Recursively call the delete function on the right subtree to remove the actual inorder successor node.

**Pseudocode Structure:**
```
function delete(node, value):
    if node is null:                // Base case: If the current node is null, the value isn't found, so stop.
        return 
    
    if value < node.value:          // If the value to delete is smaller, go left.
        delete(node.left, value)                                 
    
    else if value > node.value:     // If the value to delete is larger, go right.
        delete(node.right, value) 
    
    else:                           // The current node holds the value to be deleted.
        
        // Case 1: Node has no children (it's a leaf).
        if node.left is null and node.right is null:
            Just remove the node.

        // Case 2a: Node has only a right child.
        else if node.left is null:
            Replace this node with its right child.

        // Case 2b: Node has only a left child.
        else if node.right is null:
            Replace this node with its left child.

        // Case 3: Node has two children.
        else: 
            successor = findMin(node.right)         // Find the inorder successor (smallest node in the right subtree).
            node.value = successor.value            // Copy the successor's value to the current node.
            
            // Delete the successor from the right subtree.
            // The recursive call will handle deleting the successor (which will be Case 1 or 2).
            delete(node.right, successor.value) 
```

* **Time Complexity:**
    * **Best/Average Case: O(log n)**. Similar to insertion, this depends on tree balance.
    * **Worst Case: O(n)**. Occurs in a skewed tree.
* **Space Complexity:** **O(h)** due to the recursion stack.

---

### 3. Searching

Searching for a key in a BST is highly efficient because of its sorted structure. You start at the root and compare the target key with the current node's key. If they match, you've found it. If the target key is smaller, you move to the left child; if larger, you move to the right child. This process continues until the key is found or a `null` pointer is encountered (meaning the key isn't in the tree).

**Conceptual Process:**

* **Start at the Root:** Begin the search from the tree's root.
* **Compare and Descend:**
    * If the target key matches the current node's key, the search is successful.
    * If the target key is less than the current node's key, continue searching in the left subtree.
    * If the target key is greater than the current node's key, continue searching in the right subtree.
* **Base Case (Not Found):** If you reach a `null` pointer, the key is not in the tree.

**Pseudocode Structure:**
```
function search(node, key):
    if node is null or node.value == key: // Base cases: reached end or found key
        return node // Return the node if found, or null if not
    
    if key < node.value: // Key might be in the left subtree
        return search(node.left, key)
    else: // Key might be in the right subtree
        return search(node.right, key)
```

* **Time Complexity:**
    * **Best/Average Case: O(log n)**. Achieved when the tree is balanced.
    * **Worst Case: O(n)**. Occurs in a skewed tree.
* **Space Complexity:** **O(h)** due to recursion stack (or O(1) if implemented iteratively).

---

## BST Traversals

**Tree traversals** are methods for visiting each node in a tree exactly once. For BSTs, these traversals are particularly useful because they can extract elements in a specific order. They are typically implemented recursively, though iterative versions using a stack are also common.

### 1. Inorder Traversal (Left → Node → Right)

This traversal visits the left subtree, then the current node, then the right subtree.

**Characteristic:** When applied to a BST, an **inorder traversal always retrieves the elements in sorted (ascending) order**.

**Pseudocode Structure:**
```
function inorder(node):
    if node is null:
        return
    inorder(node.left) // Visit left subtree
    process(node.value) // Process current node
    inorder(node.right) // Visit right subtree
```

### 2. Preorder Traversal (Node → Left → Right)

This traversal visits the current node first, then its left subtree, then its right subtree.

**Characteristic:** Preorder traversal is useful for copying a tree's structure (you can recreate the tree by inserting elements in preorder sequence) or for expressing its hierarchical organization.

**Pseudocode Structure:**
```
function preorder(node):
    if node is null:
        return
    process(node.value) // Process current node
    preorder(node.left) // Visit left subtree
    preorder(node.right) // Visit right subtree
```

### 3. Postorder Traversal (Left → Right → Node)

This traversal visits the left subtree, then the right subtree, then the current node.

**Characteristic:** Postorder traversal is often used for deleting nodes in a tree (ensuring children are deleted before parents) or for evaluating expressions in an expression tree.

**Pseudocode Structure:**
```
function postorder(node):
    if node is null:
        return
    postorder(node.left) // Visit left subtree
    postorder(node.right) // Visit right subtree
    process(node.value) // Process current node
```

* **Time Complexity for All Traversals:** **O(n)**, as each node in the tree is visited exactly once.
* **Space Complexity for All Traversals:** **O(h)** due to the recursion stack, where `h` is the height of the tree. In the worst case (a skewed tree), this can be O(n).

---

## Summary of Time and Space Complexities for BST Operations

Understanding the complexity of BST operations is crucial for choosing the right data structure for your application. The performance heavily depends on the tree's balance.

| Operation    | Average Time | Worst Time | Space (Recursion Stack) |
| :----------- | :----------- | :--------- | :---------------------- |
| **Insertion** | O(log n)     | O(n)       | O(h)                    |
| **Deletion** | O(log n)     | O(n)       | O(h)                    |
| **Search** | O(log n)     | O(n)       | O(h)                    |
| **Traversals** | O(n)         | O(n)       | O(h)                    |

*Where **n** represents the number of nodes in the BST, and **h** represents the height of the tree.*

In practice, to consistently achieve the average-case logarithmic time complexities, **self-balancing binary search trees** like AVL trees or Red-Black trees are often used. These trees automatically adjust their structure during insertions and deletions to maintain a balanced height, guaranteeing O(log n) performance for all major operations.
