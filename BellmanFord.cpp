#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    // Step 1: Initialize distances
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Step 2: Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative cycle
    bool hasNegativeCycle = false;
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    // Output
    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle!\n";
    } else {
        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                cout << "Vertex " << i << " : INF\n";
            else
                cout << "Vertex " << i << " : " << dist[i] << "\n";
        }
    }

    return 0;
}