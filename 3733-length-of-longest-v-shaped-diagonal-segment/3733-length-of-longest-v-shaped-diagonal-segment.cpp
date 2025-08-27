#include <vector>
#include <algorithm>

class Solution {
public:
    int lenOfVDiagonal(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        int maxL = 0;

        std::vector<std::vector<int>> dp1_dr(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dp1_dl(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dp1_ul(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dp1_ur(n, std::vector<int>(m, 0));

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) {
                    dp1_dr[r][c] = 1;
                } else if (r > 0 && c > 0) {
                    int prev_len = dp1_dr[r - 1][c - 1];
                    if (prev_len > 0 && grid[r][c] == ((prev_len % 2 == 1) ? 2 : 0)) {
                        dp1_dr[r][c] = prev_len + 1;
                    }
                }
                maxL = std::max(maxL, dp1_dr[r][c]);
            }
        }

        for (int r = 0; r < n; ++r) {
            for (int c = m - 1; c >= 0; --c) {
                if (grid[r][c] == 1) {
                    dp1_dl[r][c] = 1;
                } else if (r > 0 && c < m - 1) {
                    int prev_len = dp1_dl[r - 1][c + 1];
                    if (prev_len > 0 && grid[r][c] == ((prev_len % 2 == 1) ? 2 : 0)) {
                        dp1_dl[r][c] = prev_len + 1;
                    }
                }
                maxL = std::max(maxL, dp1_dl[r][c]);
            }
        }

        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                if (grid[r][c] == 1) {
                    dp1_ul[r][c] = 1;
                } else if (r < n - 1 && c < m - 1) {
                    int prev_len = dp1_ul[r + 1][c + 1];
                    if (prev_len > 0 && grid[r][c] == ((prev_len % 2 == 1) ? 2 : 0)) {
                        dp1_ul[r][c] = prev_len + 1;
                    }
                }
                maxL = std::max(maxL, dp1_ul[r][c]);
            }
        }

        for (int r = n - 1; r >= 0; --r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) {
                    dp1_ur[r][c] = 1;
                } else if (r < n - 1 && c > 0) {
                    int prev_len = dp1_ur[r + 1][c - 1];
                    if (prev_len > 0 && grid[r][c] == ((prev_len % 2 == 1) ? 2 : 0)) {
                        dp1_ur[r][c] = prev_len + 1;
                    }
                }
                maxL = std::max(maxL, dp1_ur[r][c]);
            }
        }

        std::vector<std::vector<int>> dp2_dr(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dp2_dl(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dp2_ul(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dp2_ur(n, std::vector<int>(m, 0));

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (r > 0 && c > 0) {
                    int prev_len = std::max(dp2_dr[r - 1][c - 1], dp1_ur[r - 1][c - 1]);
                    if (prev_len > 0 && grid[r][c] == ((prev_len % 2 == 1) ? 2 : 0)) {
                        dp2_dr[r][c] = prev_len + 1;
                    }
                }
                maxL = std::max(maxL, dp2_dr[r][c]);
            }
        }

        for (int r = 0; r < n; ++r) {
            for (int c = m - 1; c >= 0; --c) {
                if (r > 0 && c < m - 1) {
                    int prev_len = std::max(dp2_dl[r - 1][c + 1], dp1_dr[r - 1][c + 1]);
                    if (prev_len > 0 && grid[r][c] == ((prev_len % 2 == 1) ? 2 : 0)) {
                        dp2_dl[r][c] = prev_len + 1;
                    }
                }
                maxL = std::max(maxL, dp2_dl[r][c]);
            }
        }

        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                if (r < n - 1 && c < m - 1) {
                    int prev_len = std::max(dp2_ul[r + 1][c + 1], dp1_dl[r + 1][c + 1]);
                    if (prev_len > 0 && grid[r][c] == ((prev_len % 2 == 1) ? 2 : 0)) {
                        dp2_ul[r][c] = prev_len + 1;
                    }
                }
                maxL = std::max(maxL, dp2_ul[r][c]);
            }
        }

        for (int r = n - 1; r >= 0; --r) {
            for (int c = 0; c < m; ++c) {
                if (r < n - 1 && c > 0) {
                    int prev_len = std::max(dp2_ur[r + 1][c - 1], dp1_ul[r + 1][c - 1]);
                    if (prev_len > 0 && grid[r][c] == ((prev_len % 2 == 1) ? 2 : 0)) {
                        dp2_ur[r][c] = prev_len + 1;
                    }
                }
                maxL = std::max(maxL, dp2_ur[r][c]);
            }
        }
        
        return maxL;
    }
};