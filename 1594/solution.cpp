#define ll long long
#define ar array
class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<ar<ll, 2>>> dp;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<ar<ll, 2>>(m));
        
        dp[0][0] = {grid[0][0], grid[0][0]};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 || j > 0)
                    dp[i][j] = {-(ll)(1e9+8), (ll)1e9+8};
                if (i > 0) {
                    for (int k = 0; k < 2; k++)
                        dp[i][j][0] = max(dp[i][j][0], (1LL*dp[i-1][j][k] * grid[i][j]));
                    for (int k = 0; k < 2; k++)
                        dp[i][j][1] = min(dp[i][j][1], (1LL*dp[i-1][j][k] * grid[i][j]));
                }
                
                if (j > 0) {
                    for (int k = 0; k < 2; k++)
                        dp[i][j][0] = max(dp[i][j][0], (1LL*dp[i][j-1][k] * grid[i][j]));
                    for (int k = 0; k < 2; k++)
                        dp[i][j][1] = min(dp[i][j][1], (1LL*dp[i][j-1][k] * grid[i][j]));
                }
            }
        }
        
        return dp[n-1][m-1][0] < 0 ? -1 : dp[n-1][m-1][0] % mod;
    }
};
