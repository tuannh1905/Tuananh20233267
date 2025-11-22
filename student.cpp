#include <iostream>
#include <string>
using namespace std;
struct Student{
    string name;
    string mssv;
    int year;
    float gpa;
};

struct Node{
    Student data;
    Node* next;
};

struct LinkedList{
    Node * head;
    LinkedList(){
        //khởi tạo
        head = nullptr;
    }
    void AddStudent(Student s){
    Node *p = new Node{s, nullptr};
    if(head == nullptr){
        head = p;
        return;
    }
    Node * temp = head;
    while(temp ->next != nullptr){
        temp = temp -> next;
    }
    temp -> next = p;
}

    void Print(){
        Node* temp = head;
        if(!temp){
            cout << "Danh sach rong";
            return;
        }
        while(temp != nullptr){
            cout << temp -> data.name<<" "<< temp -> data.mssv<< " " << temp -> data.year <<" "<< temp -> data.gpa << endl;
            temp = temp -> next;
        }
    }

    int ListSize(){
        int countt = 0;
        Node* temp = head;
        while(temp != nullptr){
            countt++;
            temp = temp-> next;
        }
        return countt;
    }

    int GoodGpa(){
        int countt = 0;
        Node* temp = head;
        while(temp != nullptr){
            if(temp-> data.gpa > 3.2) countt++;
            temp = temp -> next;
        }
        return countt;
    }

    void SortbyGpa(){
        if(!head) return;
        bool swapped;
        do{
            swapped = false;
            Node* p = head;
            while(p -> next != nullptr){
                if(p -> data.gpa > p -> next -> data.gpa){
                    swap(p -> data, p -> next -> data);
                    swapped = true;
                }
                p = p -> next;
            }
       }while(swapped);
    }

    void InsertInOrder(Student s){
        Node* newNode = new Node{s, nullptr};
        // nếu thêm vào đầu danh sách
        if(head == nullptr || head -> data.gpa > s.gpa){
            newNode -> next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp -> next != nullptr && temp -> next -> data.gpa < s.gpa){
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
};

int main(){
    LinkedList List;
    Student s1 = {"Karina", "12345", 2000, 3.5};
    Student s2 = {"Giselle", "12567", 2000, 4.0};
    Student s3 = {"Winter", "14689", 2001, 3.0};
    Student s4 = {"Ning", "19197", 2002, 2.8};
    List.AddStudent(s1);
    List.AddStudent(s2);
    List.AddStudent(s3);
    List.AddStudent(s4);

    cout << "Danh sach sinh vien:\n";
    List.Print();
    cout << "Chieu dai danh sach:" << List.ListSize() << endl;
    cout << "So sinh vien dat GPA > 3.2:" << List.GoodGpa() << endl;
    cout << "Danh sach sap xep theo GPA:\n";
    List.SortbyGpa();
    List.Print();
    // test thêm sinh viên gpa 2.4
    Student newStudent = {"Lee", "10281", 2004, 2.4};
    List.InsertInOrder(newStudent);
    List.Print();
    return 0;
}



