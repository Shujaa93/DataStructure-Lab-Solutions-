                                               Loading and Displaying IP Addresses Using a Doubly Linked List in C++

📖 Problem Description :

This project demonstrates how to handle file input, string tokenization, and linked list operations in C++ without using STL containers.
You are given a text file named ips.txt containing 15 IP addresses separated by commas (,).

Your task is to:
Read all IP addresses from the file ips.txt.
Insert each IP address into a doubly linked list, where each node stores a single IP address.
Traverse and display the list in forward direction (from head to tail).
Traverse and display the list in reverse direction (from tail to head).
Free all allocated memory before the program exits.

📂 File Format
File name: ips.txt
Example content (single line):
192.168.1.10,10.0.0.5,172.16.0.1,203.0.113.5,198.51.100.23,8.8.8.8,8.8.4.4,192.0.2.45,
10.10.10.10,172.20.14.2,52.214.10.7,34.102.136.180,185.199.108.153,13.35.66.1,44.240.20.10

🧩 Expected Output Example
Forward traversal:
192.168.1.10 -> 10.0.0.5 -> 172.16.0.1 -> ... -> 44.240.20.10

Backward traversal:
44.240.20.10 -> 13.35.66.1 -> ... -> 192.168.1.10

⚙️ Implementation Details
🏗️ Node Structure

Each node in the doubly linked list contains:
string ip — to store an IP address.
Node* prev — pointer to the previous node.
Node* next — pointer to the next node.

💻 Functions Implemented
Function	Description
insertBeginning(string val)	Inserts a new node at the beginning of the list.
displayForward()	Displays the list from head to tail.
displayBackward()	Displays the list from tail to head.
freeList()	Deletes all nodes to free allocated memory.

🗂️ Code Flow Summary
Open file:
ifstream file("ips.txt");
Read one line containing all IPs:
getline(file, line);
Tokenize using stringstream (split by comma):
stringstream ss(line);
while(getline(ss, ip, ',')) {
    dl.insertBeginning(ip);
}
Display forward and backward traversal.
Free memory before program exits.

📘 Author
👤 Shujaa
