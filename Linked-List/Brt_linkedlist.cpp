#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int pos);
    bool deleteFromBeginning(int* removedValue = nullptr);
    void display() const;
};

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::insertAtPosition(int value, int pos) {
    if (pos <= 1) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp) {
        insertAtEnd(value);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

bool LinkedList::deleteFromBeginning(int* removedValue) {
    if (!head) return false;
    Node* temp = head;
    if (removedValue) *removedValue = head->data;
    head = head->next;
    delete temp;
    return true;
}

void LinkedList::display() const {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << "\n";
}

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

    int removed;
    list.deleteFromBeginning(&removed);
    cout << "After first passenger boards (deletion):\n";
    list.display();

    return 0;
}
