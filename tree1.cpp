//cài đặt cây bằng lưu trữ tuần tự
#include<iostream>
using namespace std;
#define MAX 1000
int tree[MAX];
void init(){
    for(int i = 0; i < MAX; i++){
        tree[i] = -1;
    }
}
bool isEmpty(){
    return tree[1] == -1;
}
void them_goc(int n){
    tree[1] = n;
}
void them_trai(int goc, int n){
    int tmp = 2*goc;
    if(tmp < MAX) tree[tmp] = n;
}
void them_phai(int goc, int n){
    int tmp = 2*goc + 1;
    if(tmp < MAX) tree[tmp] = n;
}
void preorder(int i){
    if(i >= MAX || tree[i] == -1) return;
    cout << tree[i] << " ";
    preorder(2*i);
    preorder(2*i +1);
}
void inorder(int i){
    if(i >= MAX || tree[i] == -1) return;
    inorder(2*i);
    cout << tree[i] << " ";
    inorder(2*i +1);
}
void postorder(int i){
    if(i >= MAX || tree[i] == -1) return;
    postorder(2*i);
    postorder(2*i +1);
    cout << tree[i] << " ";
}
int main(){
    init();
    them_goc(1);
    them_trai(1,7);
    them_phai(1,9);
    them_trai(7,10);
    them_phai(9,12);
    cout << "duyet truoc: ";
    preorder(1);
    cout << endl;
    cout << "duyet giua: ";
    inorder(1);
    cout << endl;
    cout << "duyet sau : ";
    postorder(1);
    cout << endl;
}
