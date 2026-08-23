class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#') {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        deque<pair<int, int>> dq;

        dq.push_front({r, c});
        dist[r][c] = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] != '#') {
                    int cost = (i == 0) ? 1 : 0;

                    if (dist[nx][ny] > dist[x][y] + cost) {
                        dist[nx][ny] = dist[x][y] + cost;

                        if (cost == 1) {
                            dq.push_back({nx, ny});
                        } else {
                            dq.push_front({nx, ny});
                        }
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dist[i][j] != 1e9) {
                    int up_moves = dist[i][j];
                    int down_moves = up_moves + (i - r);

                    if (up_moves <= u && down_moves <= d) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna