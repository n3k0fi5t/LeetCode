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
