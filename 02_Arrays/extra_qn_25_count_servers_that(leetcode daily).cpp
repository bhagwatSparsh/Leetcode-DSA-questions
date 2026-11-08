class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int communicatingServers = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Only inspect if there is a server at (r, c)
                if (grid[r][c] == 1) {
                    bool canCommunicate = false;

                    // 1. Scan the rest of row 'r'
                    for (int j = 0; j < n; ++j) {
                        if (j != c && grid[r][j] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // 2. Scan the rest of column 'c' (if row check didn't already succeed)
                    if (!canCommunicate) {
                        for (int i = 0; i < m; ++i) {
                            if (i != r && grid[i][c] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }
                    }

                    if (canCommunicate) {
                        communicatingServers++;
                    }
                }
            }
        }

        return communicatingServers;
    }
};