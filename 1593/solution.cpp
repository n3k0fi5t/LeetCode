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
