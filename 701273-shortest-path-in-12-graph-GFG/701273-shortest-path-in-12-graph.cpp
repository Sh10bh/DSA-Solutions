class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        deque<int> dq;
        dq.push_back(src);
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    if (w == 1) dq.push_front(v);
                    else dq.push_back(v);
                }
            }
        }
        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna