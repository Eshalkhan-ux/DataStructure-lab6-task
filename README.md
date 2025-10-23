Doubly Linked List – Practical Tasks

Course: Data Structures & Algorithms
Instructor: Sir Syed Shayan Ali Shah
Student: Eshal Khan

🧩 Overview

This project implements a Doubly Linked List (DLL) in C++.
Each node stores an integer value along with pointers to both the next and previous nodes.
The project helped me understand pointer manipulation, traversal, insertion, deletion, and destructor logic in depth.

🧠 Tasks Completed

🧱 Task 1 – Destructor
I created a destructor to properly release all dynamically allocated nodes at the end of the program.
It also prints messages like:

Deleting Node: [data]
All nodes deleted successfully!


📍 Task 2 – insertAtPos()
Fixed the logic so nodes can be correctly inserted at any valid position, including the end of the list.
Now all 5 elements appear correctly when displayed.

🗑️ Task 3 – deleteFB()
Adjusted the function so after deleting the first node, the head pointer correctly points to the next node and no invalid memory access occurs.

🔍 Task 4 – DisplayNode()
Modified the function so it displays details of only the single node passed to it, rather than printing the whole list.

💻 Example Output
------------------------------------------------------
     Prev Address        |   Data   |     Next Address |   Node Address
------------------------------------------------------
0x0000000000000000       |    10    |   0x0000000000AA |   0x0000000000BB
------------------------------------------------------
Deleting Node: 50
Deleting Node: 40
Deleting Node: 30
Deleting Node: 20
Deleting Node: 10
All nodes deleted successfully!

🧾 Learning Outcomes

Through this project, I learned how to:

Manage dynamic memory using destructors

Debug pointer-related issues

Use head and tail references properly

Build confidence with C++ linked list implementation

