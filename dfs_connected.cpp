#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODES = 10;

int a[MAX_NODES][MAX_NODES], n;
bool visited[MAX_NODES];

void dfs(int node) {
    visited[node] = true;

    for (int j = 1; j <= n; j++) {
        if (a[node][j] == 1 && !visited[j]) {
            dfs(j);
        }
    }
}

bool isConnected() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    dfs(1); // Start DFS traversal from node 1 (you can start from any node)

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false; // There's an unvisited node, the graph is not connected
        }
    }
    return true; // All nodes were visited, the graph is connected
}

int main() {
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix:" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    if (isConnected()) {
        cout << "Graph is connected." << endl;
    } else {
        cout << "Graph is not connected." << endl;
    }

    return 0;
}
