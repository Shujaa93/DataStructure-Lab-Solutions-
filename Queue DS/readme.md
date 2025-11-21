#                                         Queue Data Structure in C++

This repository contains an implementation and explanation of the Queue data structure using C++.
A queue follows the FIFO (First In, First Out) principle, meaning the first element added is the first to be removed.
Queues are widely used in computer science, operating systems, AI algorithms, simulations, and real-time data processing.

# What is a Queue?

A Queue is a linear data structure in which operations are performed in a specific order:
Enqueue → Add element to the rear
Dequeue → Remove element from the front
Front/Peek → Check the front element
isEmpty → Check if queue is empty
Size → Number of elements
Queues maintain order and ensure fairness in processing tasks.

# Queue Operations :
✔ Enqueue
Adds a new element to the rear of the queue.
✔ Dequeue
Removes the element from the front of the queue.
✔ Front
Returns the value of the front element without removing it.
✔ isEmpty
Returns true if the queue contains no elements.
✔ Size
Returns the total number of elements in the queue.

# Types of Queues :
1. Simple Queue
Basic FIFO queue with fixed size.

2. Circular Queue
Prevents unused space by connecting end of array back to the start.

3. Priority Queue
Elements are removed based on priority, not order.

4. Double-Ended Queue (Deque)
Insertion and deletion allowed from both front and rear.

5. Dynamic Queue
Automatically resizes when full (using dynamic arrays or linked lists).

Why Queues Are Important in DSA
# Queues are essential in solving many real-world problems :
CPU scheduling
Task/Job management
Breadth-First Search (BFS)
Handling requests in networks
Message passing between processes
Simulation of waiting lines
Printing tasks (printer queue)
Real-time systems and OS kernels

Queue Implementation Methods in C++
Queues can be implemented using:

# Arrays :
Fast and simple
Can use circular indexing
May require resizing (dynamic array)

# Linked Lists :
No need for resizing
Efficient memory usage
Perfect for dynamic queues

# Learning Goals :
By studying this project, you will understand:
FIFO concept
Front and rear pointer logic
Circular array behavior
Queue resizing strategies
Efficient queue operations
Practical usage of queues in algorithms
