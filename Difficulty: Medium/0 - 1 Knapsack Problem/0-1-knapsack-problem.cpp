class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        int m = W;  
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(wt[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
                }
            }
        }

        return dp[n][m];
    }
};
