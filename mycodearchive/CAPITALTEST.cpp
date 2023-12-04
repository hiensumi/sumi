#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10000; // Số đỉnh tối đa
vector<int> adj[N]; // Danh sách kề

int n; // Số đỉnh
int m; // Số cạnh
int num[N]; // Số thứ tự của đỉnh
int low[N]; // Giá trị low của đỉnh
bool isArticulation[N]; // Mảng đánh dấu đỉnh khớp
int f[N]; // Mảng f[u] - số đỉnh nhận đỉnh u làm khớp

int dfsCounter; // Biến đếm số thứ tự

void findArticulations(int u) {
    num[u] = low[u] = dfsCounter++;
    for (int v : adj[u]) {
        if (num[v] == -1) {
            findArticulations(v);

            if (low[v] >= num[u]) {
                isArticulation[u] = true;
            }

            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    if(fopen(".inp", "r")){
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsCounter = 0;
    fill(num + 1, num + n + 1, -1);
    fill(low + 1, low + n + 1, -1);
    fill(isArticulation + 1, isArticulation + n + 1, false);
    fill(f + 1, f + n + 1, 0);

    for (int u = 1; u <= n; ++u) {
        if (num[u] == -1) {
            findArticulations(u);
        }
    }

    for (int u = 1; u <= n; ++u){
        cout << u << ": ";
        if (isArticulation[u]) {
            for (int v : adj[u]) {
                if (!isArticulation[v]) {
                    f[u]++;
                    cout << v << " ";
                }
            }
        }
        cout << endl;
    }

    for (int u = 1; u <= n; ++u) {
        // cout << "f[" << u << "] = " << f[u] << endl;
    }

    return 0;
}
