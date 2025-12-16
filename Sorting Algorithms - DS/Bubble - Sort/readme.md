# Selection & Bubble Sort
---

##  Objective

The objective of this assignment is to:
- Implement **Bubble Sort** and **Selection Sort** in C++
- Download a dataset (`numbers.txt`) from GitHub
- Apply both sorting algorithms on the dataset
- Optimize the algorithms for best possible time
- Measure and compare execution time

---

##  Dataset

- The input numbers were taken from a text file named:
numbers.txt
- The file was downloaded from GitHub
- The dataset contains unsorted integers used for testing performance

---

##  Algorithms Implemented

### 🔵 Bubble Sort
Bubble Sort works by repeatedly comparing adjacent elements and swapping them if they are in the wrong order.  
An **optimized version** was used that stops early if no swaps occur during a pass.

### 🔵 Selection Sort
Selection Sort works by selecting the smallest element from the unsorted portion of the array and placing it at the beginning.  
This algorithm performs fewer swaps but still compares all elements.

---

##  Optimization Techniques Used

- Early termination in Bubble Sort (stop if array is already sorted)
- Efficient loop boundaries
- Avoiding unnecessary swaps
- Accurate time measurement using system clock

---

## ⏱ Execution Time Results Example like :

| Algorithm | Execution Time |
|---------|----------------|
| Bubble Sort | **4 milliseconds** |
| Selection Sort | **13 milliseconds** |

---

##  Analysis

- Bubble Sort performed faster due to early termination optimization
- Selection Sort always takes O(n²) time, regardless of input order
- Bubble Sort is adaptive, while Selection Sort is not

---

##  Conclusion

- Bubble Sort was more efficient for the given dataset
- Selection Sort required more time due to constant comparisons
- Optimization significantly improved performance
- The assignment objectives were successfully achieved
