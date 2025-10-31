              # Hospital Emergency Queue System using Doubly Linked List

# Project Overview
This project implements a **Hospital Emergency Room (ER) Queue System** using a **Doubly Linked List** in C++.  
Each patient in the ER is represented as a node in the linked list.  
The system supports insertion and deletion of patients based on priority — making it efficient for real-world emergency management.


# Logic Explanation (In Simple Words)
Each node in the doubly linked list contains:
- `patientID` (integer)
- `prev` (pointer to previous patient)
- `next` (pointer to next patient)

We maintain:
- `head` → Points to **first** patient  
- `tail` → Points to **last** patient  

The structure allows efficient insertion and deletion **from both ends**.

---

## 🔍 Dry Run / Execution Trace

| Step | Operation | Queue (Head → Tail) | Description |
|------|------------|---------------------|--------------|
| 1 | `insertAtEnd(101)` | [101] | First patient arrives |
| 2 | `insertAtEnd(102)` | 101 ⇄ 102 | Another normal patient |
| 3 | `insertAtBeginning(200)` | 200 ⇄ 101 ⇄ 102 | Critical patient arrives |
| 4 | `insertAtPosition(150, 2)` | 200 ⇄ 150 ⇄ 101 ⇄ 102 | Priority patient added |
| 5 | `deleteFromBeginning()` | 150 ⇄ 101 ⇄ 102 | First patient treated |
| 6 | `insertAtEnd(300)` | 150 ⇄ 101 ⇄ 102 ⇄ 300 | New patient added |

**✅ Final Queue:**  
`Head → 150 ⇄ 101 ⇄ 102 ⇄ 300 ← Tail`


# Key Concepts Used
- **Doubly Linked List**  
- **Dynamic Memory Allocation**  
- **Pointer Manipulation**  
- **Queue Simulation**  

---

#  Learning Outcomes
- Understand how **Doubly Linked Lists** work.  
- Learn how to manage **real-time queue systems**.  
- Practice **insertion and deletion logic** using pointers.  
- Simulate a **real-world hospital emergency scenario** with data structures.

---

# Example Output (Console)
Inserting patient 101 at end...
Inserting patient 102 at end...
Critical patient 200 added at beginning...
Priority patient 150 inserted at position 2...
Treated patient 200 removed from queue...
Patient 300 added at end.

Final Queue (Forward): 150 → 101 → 102 → 300
Final Queue (Backward): 300 → 102 → 101 → 150
