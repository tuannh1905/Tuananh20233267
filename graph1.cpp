#include <iostream>
#include <string>

using namespace std;
string tenTinh[12];
int maTranKe[12][12];
int visited[12]; //Mảng đánh dấu 0: chưa thăm, 1: đã thăm
void BFS(int batDau, int n) {
    int hangDoi[12];
    int dau = 0, cuoi = 0;
    visited[batDau] = 1;
    hangDoi[cuoi++] = batDau;
    cout << "Ket qua duyet BFS (Theo thu tu so danh dau):" << endl;
    bool dauTien = true;
    while (dau < cuoi) {
        int u = hangDoi[dau++];
        if (!dauTien) cout << " -> ";
        cout << tenTinh[u] << "(" << u << ")";
        dauTien = false;
        for (int v = 1; v <= n; v++) {
            if (maTranKe[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                hangDoi[cuoi++] = v;
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 11;
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) maTranKe[i][j] = 0;
    }
    tenTinh[1] = "Ha noi";    tenTinh[2] = "Hai duong"; tenTinh[3] = "Hai phong";
    tenTinh[4] = "Uong bi";   tenTinh[5] = "Bac giang";   tenTinh[6] = "Bac ninh";
    tenTinh[7] = "Thai nguyen";
    tenTinh[10] = "Phu ly";
    tenTinh[11] = "Hung yen";
    tenTinh[8] = "Son tay";
    tenTinh[9] = "Hoa binh";
    maTranKe[1][2] = maTranKe[2][1] = 1;
    maTranKe[2][11] = maTranKe[11][2] = 1;
    maTranKe[11][10] = maTranKe[10][11] = 1;
    maTranKe[10][1] = maTranKe[1][10] = 1;
    maTranKe[1][9] = maTranKe[9][1] = 1;
    maTranKe[1][8] = maTranKe[8][1] = 1;
    maTranKe[1][7] = maTranKe[7][1] = 1;
    maTranKe[1][6] = maTranKe[6][1] = 1;
    maTranKe[6][5] = maTranKe[5][6] = 1;
    maTranKe[5][4] = maTranKe[4][5] = 1;
    maTranKe[6][4] = maTranKe[4][6] = 1;
    maTranKe[4][3] = maTranKe[3][4] = 1;
    maTranKe[2][3] = maTranKe[3][2] = 1;
    BFS(1, n);
    return 0;
}
