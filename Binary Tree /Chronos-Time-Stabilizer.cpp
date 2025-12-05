#include <iostream>
#include <string>
#include <limits> // For numeric limits if needed

using namespace std;

// 1. THE NODE: A Single Time Capsule

struct TimeCapsule {
    int year;              
    string eventName;       
    TimeCapsule* left;      
    TimeCapsule* right;     

    TimeCapsule(int y, string n) : year(y), eventName(n), left(nullptr), right(nullptr) {}
};

// 2. THE BST CLASS: Chronos Time Tree
class TimeTree {
private:
    TimeCapsule* root;

// Insert helper
    TimeCapsule* insertHelper(TimeCapsule* node, int year, const string& name) {
        if (node == nullptr) return new TimeCapsule(year, name);

        if (year < node->year)
            node->left = insertHelper(node->left, year, name);
        else if (year > node->year)
            node->right = insertHelper(node->right, year, name);

        return node;
    }

// Search helper
    TimeCapsule* searchHelper(TimeCapsule* node, int year) {
        if (!node) return nullptr;
        if (year == node->year) return node;
        if (year < node->year) return searchHelper(node->left, year);
        return searchHelper(node->right, year);
    }

// Find min node
    TimeCapsule* findMin(TimeCapsule* node) {
        while (node && node->left) node = node->left;
        return node;
    }

// Delete helper
    TimeCapsule* deleteHelper(TimeCapsule* node, int year, bool &removed) {
        if (!node) return nullptr;

        if (year < node->year) 
            node->left = deleteHelper(node->left, year, removed);
        else if (year > node->year) 
            node->right = deleteHelper(node->right, year, removed);
        else {
            removed = true;

      // Case 1: No children
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
      // Case 2: One child
            else if (!node->left || !node->right) {
                TimeCapsule* child = node->left ? node->left : node->right;
                delete node;
                return child;
            }
       // Case 3: Two children
            else {
                TimeCapsule* successor = findMin(node->right);
                node->year = successor->year;
                node->eventName = successor->eventName;

                bool dummy = false;
                node->right = deleteHelper(node->right, successor->year, dummy);
            }
        }
        return node;
    }

  // In-order traversal
    void inOrder(TimeCapsule* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->year << ": " << node->eventName << endl;
        inOrder(node->right);
    }

    void destroyTree(TimeCapsule* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    TimeTree() : root(nullptr) {}
    ~TimeTree() { destroyTree(root); }

    // ---------------- INJECT ----------------
    void inject(int year, string name) {
        cout << "> System: Injecting " << year << "... ";
        root = insertHelper(root, year, name);
        cout << "Timeline stable." << endl;
    }

    // ---------------- PARADOX (DELETE) ----------------
    void resolveParadox(int year) {
        cout << "> Alert: Paradox detected at " << year << "!" << endl;
        bool removed = false;
        root = deleteHelper(root, year, removed);

        if (removed)
            cout << "> System: Year " << year << " removed. Timeline stabilized." << endl;
        else
            cout << "> System: Year " << year << " not found. No action taken." << endl;
    }

    // ---------------- SEARCH ----------------
    void search(int year) {
        cout << "> Query: Searching for " << year << "..." << endl;

        TimeCapsule* result = searchHelper(root, year);
        if (result)
            cout << "> Result: Event Found! [" << result->year << ": " << result->eventName << "]" << endl;
        else
            cout << "> Result: Year " << year << " not found in current timeline." << endl;
    }

    // ---------------- REPORT ----------------
    void report() {
        cout << "> COMMAND: CHRONOLOGICAL REPORT" << endl;
        cout << "-------------------------------" << endl;
        inOrder(root);
        cout << "-------------------------------" << endl;
    }
};


// 3. MAIN INTERFACE

int main() {
    TimeTree chronos;
    string command;
    int year;
    string eventName;

    cout << "--- CHRONOS TIME STABILIZER V1.0 ---" << endl;
    cout << "Waiting for Time Stream Inputs..." << endl << endl;

    while (cin >> command) {
        if (command == "INJECT" ||"inject") {
            cin >> year;
            getline(cin >> ws, eventName);
            chronos.inject(year, eventName);
        }
        else if (command == "PARADOX" || "paradox") {
            cin >> year;
            chronos.resolveParadox(year);
        }
        else if (command == "SEARCH" || "search") {
            cin >> year;
            chronos.search(year);
        }
        else if (command == "REPORT" || "report") {
            chronos.report();
        }
        else if (command == "EXIT" || "exit") break;
        else {
            cout << "> Unknown Command." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl;
    }
    
    

    return 0;
}
