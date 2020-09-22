# Solution
## Question

Given an array of positive integers nums, remove the smallest **subarray** (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

## Constrains
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^9
- 1 <= p <= 10^9

## Example
```
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
```
```
Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
```

## Analysis
- 題目分析
    - total sum 減去某個subarray 後可以被p整除, 找出minimum subarray length

1. total sum is multiple of p ==> ans = 0
2. 假設total (sum%p = k)
    - 答案就是minimum one of subarrays whose (sum%p = k)
    - 從第一個元素開始掃(prefix sum), 並記錄每個subarray (sum%p) 的值, 以及index
    - 假設某個subarray[1..m] (sum%p = r), 也就是說, 如果扣掉這個subarray, 會讓remaining subarray (sum%p = **(k-r)**)
        - 如果 r == k, 我們找到一個可能的subarray
        - 如果 r != k, 則要看能不能找到另一個subarray[1..j], j < m (sum%p = **-(k-r)**), 如此remaining subarray (sum%p = k-r + (-(k-r)) = 0)
    - 對於每個subarray 有相同的餘數, 我們只要記住最新的即可, 因為才會讓答案的subarray minimize

- time complexity: O(N)
- space complexity: O(N)

- Source
```cpp=
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
```
