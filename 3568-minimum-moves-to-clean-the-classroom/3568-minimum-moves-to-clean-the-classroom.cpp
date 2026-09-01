
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1;
        int start_c = -1;
        int litter_count = 0;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_count++;
                }
            }
        }
        
        if (litter_count == 0) {
            return 0;
        }
        
        int target_mask = (1 << litter_count) - 1;
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(1 << litter_count, -1)));
        
        queue<tuple<int, int, int, int>> q;
        q.push({start_r, start_c, energy, 0});
        visited[start_r][start_c][0] = energy;
        
        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, curr_e, mask] = q.front();
                q.pop();
                
                if (curr_e == 0) {
                    continue;
                }
                
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                        int nxt_e = curr_e - 1;
                        int nmask = mask;
                        
                        if (classroom[nr][nc] == 'L') {
                            nmask |= (1 << litter_id[nr][nc]);
                        }
                        
                        if (nmask == target_mask) {
                            return moves + 1;
                        }
                        
                        if (classroom[nr][nc] == 'R') {
                            nxt_e = energy;
                        }
                        
                        if (nxt_e > visited[nr][nc][nmask]) {
                            visited[nr][nc][nmask] = nxt_e;
                            q.push({nr, nc, nxt_e, nmask});
                        }
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna