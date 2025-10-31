                                                        (  Dryrun / Trace  )
Let’s perform each operation step by step.
Start with an empty list.

Step 1: insertAtEnd(101)
List:
[101]
head → 101 ← tail

Step 2: insertAtEnd(102)
101 ⇄ 102
head = 101, tail = 102

Step 3: insertAtBeginning(200) // critical patient
200 ⇄ 101 ⇄ 102
head = 200, tail = 102

Step 4: insertAtPosition(150, 2)
Insert after first node (200).

200 ⇄ 150 ⇄ 101 ⇄ 102
head = 200, tail = 102

Step 5: deleteFromBeginning()
Remove 200 (treated patient).

150 ⇄ 101 ⇄ 102
head = 150, tail = 102

Step 6: insertAtEnd(300)
150 ⇄ 101 ⇄ 102 ⇄ 300
head = 150, tail = 300

Final Answers :

(a) Head patientID	150
(b) Tail patientID	300
(c) Forward (Head → Tail)	150 → 101 → 102 → 300
(d) Backward (Tail → Head)	300 → 102 → 101 → 150
