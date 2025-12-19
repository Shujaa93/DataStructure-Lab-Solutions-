#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student {
    int id;
    string name;
    string dept;
    int semester;
    float cgpa;
    int credits;
    int year;
};

struct Node {
    Student data;
    Node* next;
};

/* ---------------- BASIC LINKED LIST OPS ---------------- */

Node* insertEnd(Node* head, Student s) {
    Node* temp = new Node;
    temp->data = s;
    temp->next = NULL;

    if (!head) return temp;

    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;
    return head;
}

Node* copyList(Node* head) {
    Node* newHead = NULL;
    while (head) {
        newHead = insertEnd(newHead, head->data);
        head = head->next;
    }
    return newHead;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

/* ---------------- FILE READING ---------------- */

Node* readFile() {
    ifstream fin("students_data.txt");
    if (!fin) return NULL;

    int n;
    fin >> n;

    Node* head = NULL;
    Student s;

    for (int i = 0; i < n; i++) {
        fin >> s.id;
        fin.ignore();
        getline(fin, s.name, ' ');
        fin >> s.dept >> s.semester >> s.cgpa >> s.credits >> s.year;
        head = insertEnd(head, s);
    }

    fin.close();
    return head;
}

/* ---------------- BUBBLE SORT (CGPA) ---------------- */

void bubbleSortCGPA(Node* head) {
    if (!head) return;

    bool swapped;
    Node* ptr;
    Node* last = NULL;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data.cgpa < ptr->next->data.cgpa ||
               (ptr->data.cgpa == ptr->next->data.cgpa &&
                ptr->data.credits < ptr->next->data.credits)) {

                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

/* ---------------- SELECTION SORT (GENERIC) ---------------- */

void selectionSortEnrollment(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->data.year < min->data.year ||
               (j->data.year == min->data.year &&
                j->data.id < min->data.id)) {
                min = j;
            }
        }
        swap(i->data, min->data);
    }
}

void selectionSortDept(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->data.dept < min->data.dept ||
               (j->data.dept == min->data.dept &&
                j->data.semester < min->data.semester) ||
               (j->data.dept == min->data.dept &&
                j->data.semester == min->data.semester &&
                j->data.cgpa > min->data.cgpa)) {
                min = j;
            }
        }
        swap(i->data, min->data);
    }
}

void selectionSortName(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->data.name < min->data.name)
                min = j;
        }
        swap(i->data, min->data);
    }
}

/* ---------------- OUTPUT 1 ---------------- */

void writeRankedByCGPA(Node* head) {
    ofstream fout("ranked_by_cgpa.txt");
    fout << "Rank | ID | Name | Dept | Sem | CGPA | Credits | Year\n";

    int rank = 1;
    while (head) {
        fout << setw(4) << rank++ << " | "
             << head->data.id << " | "
             << head->data.name << " | "
             << head->data.dept << " | "
             << head->data.semester << " | "
             << fixed << setprecision(2) << head->data.cgpa << " | "
             << head->data.credits << " | "
             << head->data.year << endl;
        head = head->next;
    }
    fout.close();
}

/* ---------------- OUTPUT 2 ---------------- */

void writeEnrollment(Node* head) {
    ofstream fout("sorted_by_enrollment.txt");
    int currentYear = -1;
    float sum = 0;
    int count = 0;

    while (head) {
        if (head->data.year != currentYear) {
            if (count > 0)
                fout << "Average CGPA: " << sum / count << "\n\n";

            currentYear = head->data.year;
            fout << "Enrollment Year: " << currentYear << endl;
            sum = 0;
            count = 0;
        }
        fout << head->data.id << " "
             << head->data.name << " "
             << head->data.cgpa << endl;

        sum += head->data.cgpa;
        count++;
        head = head->next;
    }
    if (count > 0)
        fout << "Average CGPA: " << sum / count << endl;

    fout.close();
}

/* ---------------- OUTPUT 3 ---------------- */

void writeDepartment(Node* head) {
    ofstream fout("department_analysis.txt");

    string currDept = "";
    int count = 0;
    float sum = 0, max = 0, min = 4.0;

    while (head) {
        if (head->data.dept != currDept) {
            if (count > 0) {
                fout << "Students: " << count << endl;
                fout << "Avg CGPA: " << sum / count << endl;
                fout << "Max CGPA: " << max << endl;
                fout << "Min CGPA: " << min << endl << endl;
            }
            currDept = head->data.dept;
            fout << "Department: " << currDept << endl;
            count = 0;
            sum = 0;
            max = 0;
            min = 4.0;
        }
        fout << head->data.name << " "
             << head->data.semester << " "
             << head->data.cgpa << endl;

        sum += head->data.cgpa;
        if (head->data.cgpa > max) max = head->data.cgpa;
        if (head->data.cgpa < min) min = head->data.cgpa;
        count++;
        head = head->next;
    }
    fout.close();
}

/* ---------------- OUTPUT 4 ---------------- */

string tier(float c) {
    if (c >= 3.7) return "Elite";
    if (c >= 3.3) return "High Achievers";
    if (c >= 3.0) return "Good Standing";
    if (c >= 2.5) return "Satisfactory";
    return "Needs Improvement";
}

void writeTiers(Node* head) {
    ofstream fout("performance_tiers.txt");
    while (head) {
        fout << tier(head->data.cgpa) << " | "
             << head->data.name << " | "
             << head->data.cgpa << endl;
        head = head->next;
    }
    fout.close();
}

/* ---------------- MAIN ---------------- */

int main() {
    Node* original = readFile();
    if (!original) return 0;

    Node* cgpaList = copyList(original);
    bubbleSortCGPA(cgpaList);
    writeRankedByCGPA(cgpaList);

    Node* enrollList = copyList(original);
    selectionSortEnrollment(enrollList);
    writeEnrollment(enrollList);

    Node* deptList = copyList(original);
    selectionSortDept(deptList);
    writeDepartment(deptList);

    Node* tierList = copyList(original);
    selectionSortName(tierList);
    writeTiers(tierList);

    freeList(original);
    freeList(cgpaList);
    freeList(enrollList);
    freeList(deptList);
    freeList(tierList);

    return 0;
}
