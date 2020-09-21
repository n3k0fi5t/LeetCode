# LeetCode

# Solution
## Question

Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

## Constrains
- 1 <= s.length <= 16
- s contains only lower case English letters.

## Example
```
Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
```
```
Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
```

## Analysis
- 題目分析
    - length <= 16 ==> exponential time solution
    - 列舉所有可能找答案
    - time complexity
        - T(N) = T(N-1)+T(N-2)+ ... +T(1)
        - T(N-1) = T(N-2)+T(N-3)+ ... +T(1)

        - T(N)
        = 2\*T(N-2)+2\*T(N-3)+ ... + T(1)
        = 4\*T(N-3)+4\*T(N-4)+ ... + T(1)
        = ...
        = 2^(N-2)T(1) = T(2^(N-2)) = **O(2^N)**

- Solution
```cpp
class Solution {
public:
    unordered_set<string> st;
    int maxUniqueSplit(string s) {
        return solve(s, 0);
    }
    
    int solve(string &s, int idx) {
        int mx = 0;
        if (idx == s.size()) return 0;
        
        for (int i = 1; i <= s.size()-idx; i++) {
            int res;
            string sub = s.substr(idx, i);
            if (st.count(sub)) continue;
            
            st.insert(sub);
            
            res = 1 + solve(s, idx+i);
            if (res > mx)
                mx = res;
            
            st.erase(sub);
        }
        
        return mx;
    }
};
```
