                               Pointer-Based C++ Programs

This repository contains four C++ programs demonstrating the use of pointers, function pointers, and dynamic memory allocation in practical scenarios.

                             1️⃣ Clean Attendance Register
Scenario:
You are designing an attendance register for a workshop.
Highlights:
User enters the number of participants.
Memory is allocated dynamically for attendance (1 = present, 0 = absent).
Initially, all participants are marked absent by default.
User can mark selected participants as present.
Final attendance list is displayed and memory is released.


                                2️⃣ Custom Score Tracker
Scenario:
You are developing a sports score tracker for a local tournament.
Highlights:
User enters the number of players at runtime.
Dynamic memory is allocated to store scores.
Scores are taken as input and displayed back.
Memory is freed at the end to prevent leaks.


                              3️⃣ Pointer Café – Coffee Billing System

Scenario:
A café sells Espresso, Latte, and Cappuccino. Billing must be calculated using pointers.
Highlights:
Prices and quantities stored in pointer variables.
User inputs quantities via pointers.
Subtotal for each item and total bill computed using pointers only.
Final bill displayed in tabular format.

 
                              4️⃣ Secret Code Machine

Scenario:
A spy agency requires a secret code generator. The code is created by multiplying numbers from n down to 1 (factorial).
Highlights:
Algorithm stored inside a function.
Function pointer used to call the algorithm (no direct calls).
Handles special case when input is 0 (outputs 1).
Final secret code displayed to the agent.
