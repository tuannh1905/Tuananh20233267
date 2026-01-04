#include <iostream>
#include <string>
using namespace std;
struct NodeBook {
    int index;
    string tenMuc;
    NodeBook *left;
    NodeBook *right;
    NodeBook(int idx, string name) : index(idx), tenMuc(name), left(NULL), right(NULL) {}
};
bool isCopy(NodeBook* r1, NodeBook* r2) {
    if (r1 == NULL && r2 == NULL) return true;
    if (r1 == NULL || r2 == NULL) return false;
    if (r1->index != r2->index || r1->tenMuc != r2->tenMuc) return false;
    return isCopy(r1->left, r2->left) && isCopy(r1->right, r2->right);
}
// ở đây khi số mục con tăng N cấp ta có N sẽ là tổng số nút tăng thêm trên cây, thuật toán cần so sánh mọi nts trên cây, như vậy độ phức tạp là O(n)
