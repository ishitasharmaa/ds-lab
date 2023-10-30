#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool>& visited, vector<int>& ans, vector<int> adj[], int node) {
    visited[node] = true;
    ans.push_back(node);

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(visited, ans, adj, neighbor);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(visited, ans, adj, i);
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

    vector<int> ans = dfsOfGraph(V, adj);

    cout << "DFS Traversal of the Graph: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
