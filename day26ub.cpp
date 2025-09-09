#include <vector>
#include <iostream>
using namespace std;

class Graph 
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) 
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) 
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCyclicUtil(int v, vector<bool> &visited, int parent) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, v))
                    return true;
            } 
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V1 = 5;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {2,3}, {3,4}, {4,0}};
    Graph g1(V1);
    for (auto &e : edges1) g1.addEdge(e[0], e[1]);
    cout << (g1.isCyclic() ? "true" : "false") << endl;  // Expected: true

    int V2 = 3;
    vector<vector<int>> edges2 = {{0,1}, {1,2}};
    Graph g2(V2);
    for (auto &e : edges2) g2.addEdge(e[0], e[1]);
    cout << (g2.isCyclic() ? "true" : "false") << endl;  // Expected: false

    int V3 = 4;
    vector<vector<int>> edges3 = {{0,1}, {1,2}, {2,0}};
    Graph g3(V3);
    for (auto &e : edges3) g3.addEdge(e[0], e[1]);
    cout << (g3.isCyclic() ? "true" : "false") << endl;  // Expected: true

    int V4 = 4;
    Graph g4(V4);
    cout << (g4.isCyclic() ? "true" : "false") << endl;  // Expected: false

    int V5 = 2;
    vector<vector<int>> edges5 = {{0,1}, {0,1}};
    Graph g5(V5);
    for (auto &e : edges5) g5.addEdge(e[0], e[1]);
    cout << (g5.isCyclic() ? "true" : "false") << endl;  // Expected: true

    return 0;
}
