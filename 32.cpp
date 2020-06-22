class Solution {
public:
    int longestValidParentheses(string s) {
        int size = (int)s.size();
        int* dp = new int[size];
        for(int i = 0; i < size; ++i)
            dp[i] = 0;
        
        int mx = 0;
        for(int i = 1; i < size; ++i) {
            if(s[i] == ')') {
                if(s[i-1] == '(') 
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                else if(i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') 
                    dp[i] = dp[i-1] + 2 + (i-dp[i-1] >= 2 ? dp[i-dp[i-1]-2] : 0);
                mx = (mx < dp[i] ? dp[i] : mx);
            }
        }
        
        delete[] dp;
        
        return mx;
    }
};