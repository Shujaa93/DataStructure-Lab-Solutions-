                                                          Code-a-Thon Queue Management System (C++)
       
The Code-a-Thon Queue Management System is a C++ console-based application that simulates a real-world queue scenario using a Linked List.
It is designed to efficiently manage participants (students) waiting for their limited-edition T-shirts at a university event.

This project demonstrates dynamic memory management, node-based queue operations, and menu-driven interaction — all implemented manually using C++.

⚙️ Core Functionalities
Feature	Description
Add Student	Adds a new student (name + ID) to the end of the queue.
Serve Student	Removes the first student (front of the queue) who receives their T-shirt.
Student Leaves	Removes a student from any position in the queue using their ID.
Display Queue	Displays all students currently in line (front → back).
Count Students	Displays the total number of students currently waiting.


===== Code-a-Thon Queue System =====

1. Add Student
2. Serve Student
3. Student Leaves
4. Display Queue
5. Count Students
6. Exit

Enter your choice: 1
Enter name: Ali Khan
Enter ID: 101
Student added successfully!

Enter your choice: 1
Enter name: Sara Ahmed
Enter ID: 102
Student added successfully!

Enter your choice: 2
Ali Khan(ID:101) has been served.

🧬 System Behavior Summary
Operation	Time Complexity	Description
Add Student	O(1)	Directly insert at tail
Serve Student	O(1)	Remove from head
Student Leaves (by ID)	O(n)	Traverse to locate and remove
Display Queue	O(n)	Sequential traversal
Count Students	O(n)	Simple counter
🧑‍💻 Developer Information


Institute: IMSciences, Peshawar
Program: BS Artificial Intelligence
Project Type: Code-a-Thon Submission (C++ Data Structures)
