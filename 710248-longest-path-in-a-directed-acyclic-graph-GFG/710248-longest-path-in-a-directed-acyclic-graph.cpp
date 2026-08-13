class Solution {
private:
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& st, const vector<vector<pair<int, int>>>& adj) {
        visited[v] = true;
        
        for (auto node : adj[v]) {
            if (!visited[node.first]) {
                topologicalSortUtil(node.first, visited, st, adj);
            }
        }
        st.push(v);
    }

public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, st, adj);
            }
        }
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (dist[u] != INT_MIN) {
                for (auto node : adj[u]) {
                    int v = node.first;
                    int weight = node.second;
                    if (dist[v] < dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }
        
        return dist;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna