#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node {
    string title;
    int pages;
    vector<Node*> children;
    Node(string t, int p) : title(t), pages(p) {} // sách->chương->trang
};
int soChuong(Node* root) {
    if (root == NULL) return 0;
    return root->children.size();
}
int soTrang(Node* node) {
    int total = node->pages;
    for (Node* child : node->children) {
        total += soTrang(child);
    }
    return total;
}
Node* chuongDaiNhat(Node* root) {
    if (root == NULL || root->children.empty()) return NULL;
    Node* longest = root->children[0];
    int Max = soTrang(longest);
    for (size_t i = 1; i < root->children.size(); i++) {
        int current = soTrang(root->children[i]);
        if (current > Max) {
            Max = current;
            longest = root->children[i];
        }
    }
    return longest;
}
bool Xoa(Node* parent, string TenMuc) {
    for (auto it = parent->children.begin(); it != parent->children.end(); ++it) {
        if ((*it)->title == TenMuc) {
            delete *it;
            parent->children.erase(it);
            return true;
        }
        if (Xoa(*it, TenMuc)) return true;
    }
    return false;
}
void TenMuc(Node* chapter, int level = 0) {
    if (chapter == NULL) return;
    for (int i = 0; i < level; i++) cout << "  ";
    cout << "+ " << chapter->title << " (" << chapter->pages << " trang)" << endl;
    for (Node* child : chapter->children) {
        TenMuc(child, level + 1);
    }
}
