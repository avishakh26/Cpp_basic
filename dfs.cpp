#include <iostream>
#include <vector>
using namespace std;

// DFS function
void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;          // mark current node as visited
    cout << node << " ";           // print node

    for (int next : graph[node]) { // visit all adjacent nodes
        if (!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}


int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        // undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    dfs(start, graph, visited);

    return 0;
}
