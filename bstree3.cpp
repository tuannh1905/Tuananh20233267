#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int v, Node* l = NULL, Node* r = NULL){
        value = v;
        left = l;
        right = r;
    }
};
void preOrder(Node* t){
        if (t != NULL) {
            cout << t->value << " ";
            preOrder(t->left);
            preOrder(t->right);
        }
}
class BSTree{
private:
    Node *root;
    void makeEmpty(Node*& t){
        if (t != NULL){
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = NULL;
        }
    }
    void Insert(int val1, Node*& t){
        if (t == NULL){
            t = new Node(val1);
        }
        else if (val1 < t->value){
            Insert(val1, t->left);
        }
        else if (val1 > t->value){
            Insert(val1, t->right);
        }
    }
    Node* Search(int val2, Node* t){
        if (t == NULL) return NULL;
        if (val2 == t->value) return t;
        if (val2 < t->value) return Search(val2, t->left);
        return Search(val2, t->right);
    }
public:
    BSTree(){
        root = NULL;
    }
    ~BSTree(){
        makeEmpty(root);
    }
    bool isEmpty(){
        return root == NULL;
    }
    void makeEmpty(){
        makeEmpty(root);
    }
    void Insert(int val1){
        Insert(val1, root);
    }
    Node* Search(int val2){
        return Search(val2, root);
    }
};
int main() {
    BSTree bst;
    bst.Insert(5);
    bst.Insert(6);
    bst.Insert(3);
    bst.Insert(8);
    bst.Insert(7);
    bst.Insert(4);
    bst.Insert(2);
    Node *root = bst.Search(5);
    cout << "duyet cay thu tu truoc" << endl;
    preOrder(root);
    cout << endl;
    Node* n1 = bst.Search(4);
    Node* n2 = bst.Search(9);
    if (n1 != NULL)
        cout << "Node co gia tri = 4 la " << n1->value << endl;
    if (n2 == NULL)
        cout << "Khong tim thay node co gia tri = 9" << endl;
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;
    return 0;
}
