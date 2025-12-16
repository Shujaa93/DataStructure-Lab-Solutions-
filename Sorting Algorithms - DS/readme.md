# Sorting Algorithms in C++ (DSA)

This repository contains implementations of **basic sorting algorithms** using **C++**.  
It is created for **learning Data Structures & Algorithms (DSA)** and strengthening core programming concepts.

---

##  Algorithms Included

-  Bubble Sort  
-  Selection Sort  

##  Bubble Sort

Bubble Sort is a simple comparison-based sorting algorithm.  
It works by repeatedly comparing **adjacent elements** and swapping them if they are in the wrong order.
After each pass, the **largest element moves to the end** of the array, just like a bubble rising to the surface.

Array:
[5, 3, 2]

Pass 1:
5 > 3 → swap → [3, 5, 2]  
5 > 2 → swap → [3, 2, 5]

Pass 2:
3 > 2 → swap → [2, 3, 5]

Sorted Array:
[2, 3, 5]

---

##  Selection Sort

Selection Sort is a comparison-based sorting algorithm.  
It works by **selecting the smallest element** from the unsorted part of the array and placing it at the beginning.
The array is divided into a sorted and an unsorted part, and the sorted part grows one element at a time.

Array:
[5, 3, 2]

Pass 1:
Smallest = 2  
Swap with first element → [2, 3, 5]

Pass 2:
Smallest = 3  
Already in correct position

Sorted Array:
[2, 3, 5]

(More algorithms will be added soon)

---

##  Purpose of This Repository

- To understand **fundamental sorting techniques**
- To practice **array manipulation and loops**
- To prepare for **DSA exams and interviews**
- To build a **DSA portfolio on GitHub**

------

## Time Complexity Overview
Algorithm	Best	Average	Worst
Bubble Sort	O(n)	O(n²)	O(n²)
Selection Sort	O(n²)	O(n²)	O(n²)

