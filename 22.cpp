class Solution {
public:
    void run(vector<string>& v, string& s, int pos, int count) {
        if(pos == (int)s.size()-1) {
            v.push_back(s + string(count, ')'));
            return;
        }
        string h = s.substr(0, pos+1);
        string t = s.substr(pos+1, (int)s.size()-pos);
        for(int i = 0; i <= count; ++i) {
            string k = h + string(i, ')') + t;
            run(v, k, pos+i+1, count-i+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = string(n, '(');
        run(v, s, 0, 1);
        return v;
    }
};