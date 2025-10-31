#include <iostream>
using namespace std;

class Node {
public:
    int patientID;
    Node* next;
    Node* prev;

    Node(int id) {
        patientID = id;
        next = prev = NULL;
    }
};

class ERQueue {
    Node* head;
    Node* tail;

public:
    ERQueue() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int id) {
        cout << "\ninsertAtBeginning(" << id << ")";
        Node* newNode = new Node(id);

        if (head==nullptr) {
            head = tail = newNode;
            cout << " -> OK (first node)";
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << " -> Inserted at beginning";
    }

    void insertAtEnd(int id) {
        cout << "\ninsertAtEnd(" << id << ")";
        Node* newNode = new Node(id);

        if (head==nullptr) {
            head = tail = newNode;
            cout << " -> OK (first node)";
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        cout << " -> Inserted at end";
    }

    void insertAtPosition(int id, int pos) {
        cout << "\ninsertAtPosition(" << id << ", " << pos << ")";
        if (pos <= 1 || head==nullptr) {
            insertAtBeginning(id);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next; i++)
            temp = temp->next;

        if (temp==temp->next) {
            insertAtEnd(id);
            return;
        }

        Node* newNode = new Node(id);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << " -> Inserted at position " << pos;
    }

    void deleteFromBeginning() {
        cout << "\ndeleteFromBeginning()";
        if (head==nullptr) {
            cout << " -> List empty";
            return;
        }

        Node* temp = head;
        cout << " -> Deleted " << head->patientID;

        if (head == tail)
            head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    void displayForward() {
        cout << "\nCurrent List: ";
        if (head==nullptr) {
            cout << "Empty";
            return;
        }
        Node* temp = head;
        while (temp!=nullptr) {
            cout << temp->patientID;
            if (temp->next) cout << " ⇄ ";
            temp = temp->next;
        }
    }

    void displayBackward() {
        cout << "\nReverse List: ";
        if (tail==nullptr) {
            cout << "Empty";
            return;
        }
        Node* temp = tail;
        while (temp!=nullptr) {
            cout << temp->patientID;
            if (temp->prev) cout << " ⇄ ";
            temp = temp->prev;
        }
    }

    Node* getHead()
     { return head; }
    Node* getTail()
     { return tail; }
};

int main() {
    ERQueue er;

    er.insertAtEnd(101);
    er.displayForward();

    er.insertAtEnd(102);
    er.displayForward();

    er.insertAtBeginning(200);
    er.displayForward();

    er.insertAtPosition(150, 2);
    er.displayForward();

    er.deleteFromBeginning();
    er.displayForward();

    er.insertAtEnd(300);
    er.displayForward();

    cout << "\n\nHead: " << er.getHead()->patientID;
    cout << "\nTail: " << er.getTail()->patientID;
    er.displayForward();
    er.displayBackward();

    return 0;
}
