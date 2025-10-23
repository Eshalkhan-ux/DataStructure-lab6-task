
// Topic: Doubly Linked List (C++ Implementation)
// -----------------------------------------------
// Tasks Completed:
// ✅ Task 1 – Destructor
// ✅ Task 2 – Fix insertAtPos()
// ✅ Task 3 – Fix deleteFB()
// ✅ Task 4 – Fix DisplayNode()

#include <iostream>
#include <iomanip>
using namespace std;

//-------------------------------------
// Node Class
//-------------------------------------
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

//-------------------------------------
// DLL Class
//-------------------------------------
class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    // 🔹 Task 1: Destructor – delete all nodes when program ends
    ~DLL() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Deleting Node with data: " << temp->data << endl;
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        cout << "All nodes deleted successfully!" << endl;
    }

    //-------------------------------------
    // Display complete list
    //-------------------------------------
    void Display() {
        Node* temp = head;
        if (!temp) {
            cout << "\nList is Empty!\n";
            return;
        }

        cout << "\n------------------------------------------------------\n";
        cout << "     Prev Address        |   Data   |     Next Address |   Node Address\n";
        cout << "------------------------------------------------------\n";

        while (temp != nullptr) {
            cout << setw(20) << temp->prev
                << " | " << setw(7) << temp->data
                << " | " << setw(18) << temp->next
                << " | " << setw(20) << temp
                << endl;
            temp = temp->next;
        }
        cout << "------------------------------------------------------\n";
        cout << "Tail: " << tail << endl;
        cout << "------------------------------------------------------\n";
    }

    //-------------------------------------
    // Insert node at beginning
    //-------------------------------------
    void insertAtBegin(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;

        if (head != nullptr)
            head->prev = newNode;

        head = newNode;

        if (head->next == nullptr)
            tail = newNode;
    }

    //-------------------------------------
    // Insert node at end
    //-------------------------------------
    void insertAtEnd(int value) {
        if (tail == nullptr) {
            insertAtBegin(value);
            return;
        }

        Node* newNode = new Node(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    //-------------------------------------
    // 🔹 Task 2: Fix insertAtPos()
    //-------------------------------------
    void insertAtPos(int position, int value) {
        if (position <= 0) {
            cout << "Invalid Position!" << endl;
            return;
        }

        // Case 1: Insert at beginning
        if (head == nullptr || position == 1) {
            insertAtBegin(value);
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }

        // Case 2: Insert at end
        if (current->next == nullptr) {
            insertAtEnd(value);
            return;
        }

        // Case 3: Insert in middle
        Node* newNode = new Node(value);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    //-------------------------------------
    // 🔹 Task 3: Fix deleteFB()
    //-------------------------------------
    void deleteFB() {
        if (head == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            cout << "First (and only) node deleted successfully." << endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr; // ✅ Fix: reset previous pointer of new head
            delete temp;
            cout << "First node deleted successfully." << endl;
        }
    }

    //-------------------------------------
    // 🔹 Task 4: Fix DisplayNode()
    //-------------------------------------
    void DisplayNode(Node* node) {
        if (node == nullptr) {
            cout << "Node not found!" << endl;
            return;
        }

        cout << "\n------------------------------------------------------\n";
        cout << "     Prev Address        |   Data   |     Next Address |   Node Address\n";
        cout << "------------------------------------------------------\n";

        cout << setw(20) << node->prev
            << " | " << setw(7) << node->data
            << " | " << setw(18) << node->next
            << " | " << setw(20) << node
            << endl;

        cout << "------------------------------------------------------\n";
    }

    //-------------------------------------
    // Search and display specific node
    //-------------------------------------
    void search(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                cout << "Node found!\n";
                DisplayNode(current);
                return;
            }
            current = current->next;
        }
        cout << "Node not found!" << endl;
    }
};

//-------------------------------------
// MAIN FUNCTION
//-------------------------------------
int main() {
    DLL list;

    cout << "\n--- Inserting Nodes ---\n";
    list.insertAtBegin(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtPos(5, 50); // Insert 50 at position 5
    list.Display();

    cout << "\n--- Deleting First Node ---\n";
    list.deleteFB();
    list.Display();

    cout << "\n--- Searching for Node (30) ---\n";
    list.search(30);

    cout << "\n--- Program End: Destructor will run automatically ---\n";

    return 0;
}
