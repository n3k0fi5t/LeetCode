#define ll long long
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
