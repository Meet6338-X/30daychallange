#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int shortestPath(int V, const vector<vector<int>>& edges, int start, int end) 
{
    vector<vector<int>> adj(V);
    for (const auto& edge : edges) 
    {
        int u = edge[0];
        int v = edge[1];
        if (u != v) 
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    if (start == end) return 0;

    vector<bool> visited(V, false);
    queue<pair<int, int>> q;

    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        auto [node, dist] = q.front();
        q.pop();

        for (int neighbor : adj[node]) 
        {
            if (!visited[neighbor]) 
            {
                if (neighbor == end)
                    return dist + 1;
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
    return -1;
}
int main() 
{
    int V1 = 5;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    cout << "Test Case 1 Output: " << shortestPath(V1, edges1, 0, 4) << endl; // Expected: 3

    int V2 = 3;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}};
    cout << "Test Case 2 Output: " << shortestPath(V2, edges2, 0, 2) << endl; // Expected: 2

    int V3 = 4;
    vector<vector<int>> edges3 = {{0, 1}, {1, 2}};
    cout << "Test Case 3 Output: " << shortestPath(V3, edges3, 2, 3) << endl; // Expected: -1

    int V4 = 1;
    vector<vector<int>> edges4 = {};
    cout << "Edge Case 1 Output: " << shortestPath(V4, edges4, 0, 0) << endl; // Expected: 0

    int V5 = 4;
    vector<vector<int>> edges5 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    cout << "Edge Case 2 Output: " << shortestPath(V5, edges5, 0, 3) << endl; // Expected: 1

    int V6 = 3;
    vector<vector<int>> edges6 = {};
    cout << "Edge Case 3 Output: " << shortestPath(V6, edges6, 0, 2) << endl; // Expected: -1

    return 0;
}