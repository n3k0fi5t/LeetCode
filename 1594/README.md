# Solution
## Question
You are given a rows x cols matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (rows - 1, cols - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative return -1.

Notice that the modulo is performed after getting the maximum product.

## Constrains
- 1 <= rows, cols <= 15
- -4 <= grid[i][j] <= 4

## Example
```
Input: grid = [[-1,-2,-3],
               [-2,-3,-3],
               [-3,-3,-2]]
Output: -1
Explanation: It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
```
```
Input: grid = [[1,-2,1],
               [1,-2,1],
               [3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is in bold (1 * 1 * -2 * -4 * 1 = 8).
```

## Analysis
- 題目分析
    - partial result 有正負數的狀況下**沒有local optimal solution必定存在於global optimal solution的性質**
        - 從Example 2來看
        ```
        Input: grid =
              [[1,-2,1],
               [1,-2,1],
               [3,-4,1]]
        ```
        (1, 1)的optimal solution是4, 不是-2
        但global optimal solution 使用的是-2的那條path
        
    - 我們保存從上一個step path的maximum, 以及minimum value
    - optimal solution 必然會從這兩種case 選一種出來用
        - grid[i][j] > 0==> prev_path_max * grid[i][j] will still be maximum
        - grid[i][j] < 0
            maximum will be either prev_path_max * grid[i][j] or prev_path_min * grid[i][j]

```cpp
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
```
