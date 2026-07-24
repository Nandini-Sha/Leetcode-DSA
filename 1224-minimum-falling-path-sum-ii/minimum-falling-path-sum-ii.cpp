class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> prev = grid[0];

        for (int i = 1; i < n; i++) {
            int min1 = INT_MAX, min2 = INT_MAX;
            int col1 = -1, col2 = -1;

            // Find smallest and second smallest values in previous DP row
            for (int j = 0; j < n; j++) {
                if (prev[j] < min1) {
                    min2 = min1;
                    col2 = col1;
                    min1 = prev[j];
                    col1 = j;
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                    col2 = j;
                }
            }

            vector<int> curr(n);

            // Compute current DP row
            for (int j = 0; j < n; j++) {
                if (j == col1)
                    curr[j] = grid[i][j] + min2;
                else
                    curr[j] = grid[i][j] + min1;
            }

            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};