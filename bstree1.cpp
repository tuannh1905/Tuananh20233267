#include <iostream>
#include <cmath>
using namespace std;
struct Tree {
    int Data[100];
    int n;
};
void preOrder(Tree* T, int i) {
    if (i >= T->n) return;
    cout << T->Data[i] << " ";
    preOrder(T, 2 * i + 1);
    preOrder(T, 2 * i + 2);
}
void inOrder(Tree* T, int i) {
    if (i >= T->n) return;
    inOrder(T, 2 * i + 1);
    cout << T->Data[i] << " ";
    inOrder(T, 2 * i + 2);
}
void postOrder(Tree* T, int i) {
    if (i >= T->n) return;
    postOrder(T, 2 * i + 1);
    postOrder(T, 2 * i + 2);
    cout << T->Data[i] << " ";
}
void TaoDong(Tree* T, int i, int n) {
    int j = (2 * i) + 1;
    int key = T->Data[i];
    while (j <= (n - 1)) {
        if ((j < n - 1) && (T->Data[j] < T->Data[j + 1])) {
            j = (j + 1);
        }
        if (key >= T->Data[j]) {
            break;
        } else {
            T->Data[(j - 1) / 2] = T->Data[j];
            T->Data[j] = key;
        }
        i = j;
        j = i * 2 + 1;
    }
}
void VunDong(Tree* T) {
    for (int i = (T->n / 2) - 1; i >= 0; i--) {
        TaoDong(T, i, T->n);
    }
}
int main() {
    Tree myTree;
    int values[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    myTree.n = 10;
    for(int i = 0; i < 10; i++) myTree.Data[i] = values[i];
    cout << "duyet truoc:  "; preOrder(&myTree, 0); cout << endl;
    cout << "duyet giua:   "; inOrder(&myTree, 0);  cout << endl;
    cout << "duyet sau: "; postOrder(&myTree, 0); cout << endl;
    VunDong(&myTree);
    cout << "Duyet truoc sau khi vun dong: " << endl;
    preOrder(&myTree, 0);
    return 0;
}

