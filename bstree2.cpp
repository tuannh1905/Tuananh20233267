#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};
void taoMang(Node* root, int values[], bool exist[], int &size) {
    if (root == NULL) {
        exist[size] = false;
        values[size] = 0;
        size++;
        return;
    }
    exist[size] = true;
    values[size] = root->data;
    size++;
    taoMang(root->left, values, exist, size);
    taoMang(root->right, values, exist, size);
}

bool Kiemtra(Node* root1, Node* root2) {
    int val1[1000], val2[1000];
    bool ex1[1000], ex2[1000];
    int size1 = 0, size2 = 0;
    taoMang(root1, val1, ex1, size1);
    taoMang(root2, val2, ex2, size2);
    if (size1 != size2) return false;
    for (int i = 0; i < size1; i++) {
        if (ex1[i] != ex2[i]) return false;
        if (ex1[i] == true && val1[i] != val2[i]) return false;
    }
    return true;
}
int main() {
//cây 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
//cây 2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
//cây 3
    Node* root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);
    root3->right->right = new Node(4);
    if (Kiemtra(root1, root2)) {
        cout << "cay 1 va 2: hai cay giong nhau" << endl;
    } else {
        cout << "cay 1 va 2: hai cay khác nhau" << endl;
    }
    if (Kiemtra(root1, root3)) {
        cout << "cay 1 va 3: hai cay giong nhau" << endl;
    } else {
        cout << "cay 1 va 3: hai cay khac nahu" << endl;
    }
    return 0;
}
