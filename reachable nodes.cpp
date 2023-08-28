#include <iostream>
#include <queue>
using namespace std;

const int MAX_NODES = 10;

int a[MAX_NODES][MAX_NODES], n;

void bfs(int src) {
    int q[MAX_NODES], f = 0, r = -1, vis[MAX_NODES];

    for (int j = 1; j <= n; j++) {
        vis[j] = 0;
    }
    vis[src] = 1;
    r = r + 1;
    q[r] = src;

    while (f <= r) {
        int i = q[f];
        f = f + 1;

        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 && vis[j] != 1) {
                vis[j] = 1;
                r = r + 1;
                q[r] = j;
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        if (vis[j] != 1) {
            cout << "Node " << j << " is not reachable" << endl;
        } else {
            cout << "Node " << j << " is reachable" << endl;
        }
    }
}

int main() {
    int src;

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix:" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the source node: ";
    cin >> src;

    bfs(src);

    return 0;
}
