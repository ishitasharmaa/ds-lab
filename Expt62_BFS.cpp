#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    queue<int> q;
    q.push(0);
    vector<bool> visited(V, false); // Changed to use vector
    vector<int> ans;
    visited[0] = true; // Use 'true' instead of '1'
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (int i = 0; i < adj[front].size(); i++) { // Use a traditional for loop
            int neighbour = adj[front][i];
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = bfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
