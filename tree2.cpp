#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* Init(int n){
    Node* p = new Node;
    p-> data = n;
    p-> left = p-> right = nullptr;
    return p;
}
bool isEmpty(Node* goc){
    return goc == nullptr;
}
void them_trai(Node* goc, int n){
    if(goc != nullptr) goc-> left = Init(n);
}
void them_phai(Node* goc, int n){
    if(goc != nullptr) goc-> right = Init(n);
}
void preorder(Node* goc){
    if(goc == nullptr) return;
    cout << goc-> data << " ";
    preorder(goc-> left);
    preorder(goc-> right);
}
void inorder(Node* goc){
    if(goc == nullptr) return;
    inorder(goc-> left);
    cout << goc-> data << " ";
    inorder(goc-> right);
}
void postorder(Node* goc){
    if(goc == nullptr) return;
    postorder(goc-> left);
    postorder(goc-> right);
    cout << goc-> data << " ";
}
int main(){
    Node* goc = Init(1);
    them_trai(goc, 3);
    them_phai(goc, 7);
    them_trai(goc-> left, 10);
    them_phai(goc-> left, 11);
    them_phai(goc-> right, 17);
    cout << "Duyet truoc:";
    preorder(goc);
    cout << endl;
    cout << "Duyet giua:";
    inorder(goc);
    cout << endl;
    cout << "Duyet sau:";
    postorder(goc);
    cout << endl;
    return 0;
}
