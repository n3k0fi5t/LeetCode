# Solution
## Question
You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.



## Constrains
- 1 <= scores.length, ages.length <= 1000
- scores.length == ages.length
- 1 <= scores[i] <= 106
- 1 <= ages[i] <= 1000

## Example
```
Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.
```
```
Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
```

## Analysis
- 題目分析
    - 特殊條件限制下的knapsack problem
        - 如果選了某個球員, 則比該球員年長且得分數strictly lower的球員就不可選
        - 不可greedy
    - Naive solution
        - sort by age, 從大到小去選擇
        - 計算每個球員挑或不挑的max score
        - time complexity O(2^N) ==> TLE
    - DP
        - sort by age, 從小到大去選擇
        - dp[i], 選擇 index i的球員且年齡最大為age[i] 的最大score
        - dp[i] = max(dp[i], dp[j] + score[i]) for each j in range (0,i-1)
        - time complexity O(N^2)

```cpp
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> sc;
        vector<int> dp;
        int ans = 0;
        dp.resize(1010);
        
        int n = scores.size();
        for (int i = 0; i < n; i++)
            sc.emplace_back(ages[i], scores[i]);
        
        sort(sc.begin(), sc.end());
        
        // dp[i], max scores that contains score[i] with max age age[i]
        for (int i = 0; i < n; i++) {
            dp[i] = sc[i].second;
            
            for (int j = 0; j < i; j++) {
                if (sc[j].second > sc[i].second) continue;
                dp[i] = max(dp[i], dp[j] + sc[i].second);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
```
