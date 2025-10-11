#include <iostream>
using namespace std;

class node{
public:
    string name;
    int id;
    node *next;
    node(string n,int i){
        name=n;
        id=i;
        next=nullptr;
    }
};

class linkedList{
public:
    node *head;
    node *tail;

    linkedList(){
        head=nullptr;
        tail=nullptr;
    }

    void addStudent(string name,int id){
        node *newnode=new node(name,id);
        if(head==nullptr){
            head=newnode;
            tail=newnode;}
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cout<<"Student "<<name<<"(ID:"<<id<<") added to queue"<<endl;
    }

    void serveStudent(){
        if(head==nullptr){
            cout<<"No students in queue"<<endl;
            return;
        }
        node *temp=head;
        cout<<"Student "<<temp->name<<"(ID:"<<temp->id<<") has been served"<<endl;
        head=head->next;
        if(head==nullptr) tail=nullptr;
        delete temp;
    }

    void removeStudentByID(int id){
        if(head==nullptr){
            cout<<"Queue empty"<<endl;
            return;
        }
        node *temp=head;
        node *prev=nullptr;
        if(head->id==id){
            cout<<"Student "<<head->name<<"(ID:"<<head->id<<") left the queue"<<endl;
            head=head->next;
            if(head==nullptr) tail=nullptr;
            delete temp;
            return;
        }
        while(temp!=nullptr && temp->id!=id){
            prev=temp;
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"Student with ID "<<id<<" not found"<<endl;
            return;
        }
        cout<<"Student "<<temp->name<<"(ID:"<<temp->id<<") left the queue"<<endl;
        prev->next=temp->next;
        if(temp==tail) tail=prev;
        delete temp;
    }

    void display(){
        if(head==nullptr){
            cout<<"Queue is empty"<<endl;
            return;
        }
        node *temp=head;
        int pos=1;
        cout<<"\nCurrent Queue:"<<endl;
        while(temp!=nullptr){
            cout<<pos<<". "<<temp->name<<"(ID:"<<temp->id<<")"<<endl;
            temp=temp->next;
            pos++;
        }
    }

    void countStudents(){
        int c=0;
        node *temp=head;
        while(temp!=nullptr){
            c++;
            temp=temp->next;
        }
        cout<<"Total students in queue: "<<c<<endl;
    }
};

int main(){
    linkedList q;
    int ch,id;
    string name;

    cout<<"===== Code-a-Thon Queue System ====="<<endl;
    do{
        cout<<"\n1.Add Student\n2.Serve Student\n3.Student Leaves\n4.Display Queue\n5.Count Students\n6.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter name: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter ID: ";
            cin>>id;
            q.addStudent(name,id);
            break;
        case 2:
            q.serveStudent();
            break;
        case 3:
            cout<<"Enter ID to remove: ";
            cin>>id;
            q.removeStudentByID(id);
            break;
        case 4:
            q.display();
            break;
        case 5:
            q.countStudents();
            break;
        case 6:
            cout<<"Exiting..."<<endl;
            break;
        default:
            cout<<"Invalid choice"<<endl;
        }
    }while(ch!=6);

    return 0;
}
