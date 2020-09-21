class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int ans = 1e9;
        int sum = 0;
        int k;
        map<int, int> mp;
        
        for (int i = 0; i < n; i++)
            sum = (sum + nums[i]%p) % p;
        
        if (!sum) return 0;
        
        k = sum;
        mp[0] = -1;
        for (int i = 0, sum = 0; i < n; i++) {
            int target;
            sum = (sum + nums[i]%p) % p;
            
            target = (sum - k + p)%p;
            if (mp.count(target))
                ans = min(ans, i - mp[target]);
            
            mp[sum] = i;
        }
        if (ans >= n) return -1;
        return ans;
    }
};
