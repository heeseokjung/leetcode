class Solution {
public:
    string longestPalindrome(string s) {
        int size = (int)s.size();
        if(size == 0)
            return s;
        
        bool dp[1000][1000];
        for(int i = 0; i < size; ++i)
            for(int j = 0; j < size; ++j)
                dp[i][j] = false;
        
        int mx = 0, ii, jj;
        for(int len = 1; len <= size; ++len) {
            for(int i = 0; i+len-1 < size; ++i) {
                int j = i+len-1;
                if(i == j) 
                    dp[i][j] = true;
                else if(i+1 == j && s[i] == s[j]) 
                    dp[i][j] = true;
                else if(dp[i+1][j-1] && s[i] == s[j])
                    dp[i][j] = true;
                
                if(dp[i][j] && mx < j-i+1) {
                    mx = j-i+1;
                    ii = i; jj = j;
                }
            }
        }
        
        return s.substr(ii, jj-ii+1);
    }
};