# Solution
## Question
You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.

You can apply either of the following two operations any number of times and in any order on s:

Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.



## Constrains
- 2 <= s.length <= 100
- s.length is even.
- s consists of digits from 0 to 9 only.
- 1 <= a <= 9
- 1 <= b <= s.length - 1

## Example
```
Input: s = "5525", a = 9, b = 2
Output: "2050"
Explanation: We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
​​​​​​​Add:    "5121"
​​​​​​​Rotate: "2151"
​​​​​​​Add:    "2050"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "2050".
```
```
Input: s = "74", a = 5, b = 1
Output: "24"
Explanation: We can apply the following operations:
Start:  "74"
Rotate: "47"
​​​​​​​Add:    "42"
​​​​​​​Rotate: "24"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "24".
```

## Analysis
- 題目分析
    - 爆搜. 
    - Time complexity = number of possible string
        - for each string
            - if b % 2 == 0, string could only be rotated ceil(N/b) times
            - if b % 2 != 0, string could be rotated N times
            - O(N)
        - for each string, there contains at most 10 different value
            - O(1)

        - Take O(N) to generate string
        - Compleity O(N^2)

```cpp
class Solution {
public:
    set<string> st;
    string findLexSmallestString(string s, int a, int b) {
        solve(s, a, b);        
        
        return *st.begin();
    }
    
    void solve(string& s, int a, int b) {
        if (st.count(s)) return;
        st.insert(s);
        
        // op1
        string s1 = op1(s, a);
        solve(s1, a, b);
        // op2
        string s2 = op2(s, b);
        solve(s2, a, b);
    }
    
    string op1(string& s, int a) {
        string res = s;
        for (int i = 1; i < s.size(); i+=2) {
            int c = res[i]-'0';
            c = (a+c)%10;
            res[i] = c + '0';
        }
        return res;
    }
    string op2(string &s, int b) {
        int n = s.size();
        string res = s.substr(b) + s.substr(0, b);
        return res;
    }
};
```
