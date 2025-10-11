#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int value, int pos) {
        if (pos <= 1 || head == nullptr) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(101);
    list.insertAtEnd(102);
    list.insertAtEnd(103);
    cout << "Initial Queue after adding passengers:\n";
    list.display();

    list.insertAtBeginning(999);
    cout << "After adding an emergency passenger at beginning:\n";
    list.display();

    list.insertAtPosition(555, 2);
    cout << "After inserting special booking passenger at position 2:\n";
    list.display();

    list.deleteFromBeginning();
    cout << "After first passenger boards (deletion):\n";
    list.display();

    return 0;
}
