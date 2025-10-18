#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class Node{
public:

    string data;
    Node* next;
    Node* prew;

    Node(string value){
        data = value;
        next = nullptr;
        prew = nullptr;
    }
};

class DoublyLL{
public: 
    Node* head;
    Node* tail;

    DoublyLL(){
        head = nullptr;
        tail = nullptr;
    }

void insertBeganing(string val){
    Node* newnode = new Node(val);
    if(head == nullptr){
        head = tail = newnode; }
    else{
        newnode->next = head;
        head->prew = newnode;
        head = newnode;
    }
}

void displayFarward(){
    if(head == nullptr){
        cout<<"List is Empty :";
    }
    Node* temp = head;
    cout<<"Farward Data :  ";
    while(temp != nullptr){
        cout<<" ->  [" <<temp->data <<"] ";
        temp = temp->next;
    }
}

void displayBackward(){
    if(tail == nullptr){
        cout<<"List is Empty :";
    }
    cout<<"Backward Data : ";
    Node* temp = tail;
    while(temp != nullptr){
        cout<<" ->  [" <<temp->data<<"] ";
        temp = temp->prew;
    }
}

};

int main(){

    DoublyLL dl;
    ifstream file("ips.txt");
    string line;
    if(file.is_open()){
        getline(file, line);
        file.close();
        stringstream ss(line);
        string ip;
        while(getline(ss, ip, ',')){
            dl.insertBeganing(ip);
        }
    }

    dl.displayFarward();
    cout<<endl<<endl;
    dl.displayBackward();

    return 0;
}
