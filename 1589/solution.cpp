class Solution {
public:
    const int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int ans = 0;
        int n = nums.size();
        vector<int> pref(n+1, 0);

        for (int i = 0; i < requests.size(); i++) {
            pref[requests[i][0]]++;
            pref[requests[i][1]+1]--;
        }
        
        for (int i = 0, sum = 0; i < n; i++)
            pref[i+1] += pref[i];
        
        sort(pref.begin(), pref.end());
        sort(nums.begin(), nums.end());
        
        for (int i = n-1; ~i; i--) {
            if (!pref[i+1]) break;
            ans = (ans + (pref[i+1]*nums[i])%mod) % mod;
        }
        
        return ans;
    }
};
