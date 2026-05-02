#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    // Distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distance to self is 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    cout << "Enter edges (u v w):\n";
    cout << "(0-based indexing)\n";

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // If multiple edges exist, keep the smallest weight
        dist[u][v] = min(dist[u][v], w);
    }

    // Floyd–Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Output result
    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}