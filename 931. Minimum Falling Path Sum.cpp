class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a, b, c;
                if (j > 0) {
                    a = matrix[i][j] + dp[i - 1][j - 1];
                } else {
                    a = INT_MAX;
                }
                b = matrix[i][j] + dp[i - 1][j];
                if (j < n - 1) {
                    c = matrix[i][j] + dp[i - 1][j + 1];
                } else {
                    c = INT_MAX;
                }
                dp[i][j] = min(a, min(b, c));
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        
        return ans;
    }
};
