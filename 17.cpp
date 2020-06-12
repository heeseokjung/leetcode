class Solution {
public:
    vector<string> m;
    
    Solution() {
        m = vector<string>(10);
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
    }
    
    void append(vector<string>& v, string& digits, string s, int pos) {
        if(pos == (int)digits.size()) {
            v.push_back(s);
            return;
        }
        int num = digits[pos]-'0';
        for(int i = 0; i < (int)m[num].size(); ++i)
            append(v, digits, s + m[num][i], pos + 1);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty())
            return ans;
        append(ans, digits, "", 0);
        return ans;
    }
};