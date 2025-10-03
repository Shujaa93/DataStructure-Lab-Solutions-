                                                         #1   Linked List (BRT Peshawar Use Case)

This project simulates a passenger queue system for 
BRT Peshawar using a singly linked list in C++.

### Features
- Emergency passenger joins at beginning.
- Normal passenger joins at end.
- Special booking passenger joins at a given position.
- First passenger boards (deletion from beginning).

### Example Output
Initial Queue after adding passengers:
101 -> 102 -> 103
After adding an emergency passenger at beginning:
999 -> 101 -> 102 -> 103
After inserting special booking passenger at position 2:
999 -> 101 -> 555 -> 102 -> 103
After first passenger boards (deletion):
101 -> 555 -> 102 -> 103
