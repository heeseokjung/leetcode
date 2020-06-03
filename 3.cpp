class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = (int)s.size(), mx = 0;
        for(int i = 0; i < size; ++i) {
            set<char> st;
            int count = 0;
            for(int j = i; j < size; ++j) {
                if(st.find(s[j]) != st.end()) {
                    int count = (int)st.size();
                    mx = (mx < count ? count : mx);
                    break;
                }
                st.insert(s[j]);
            }
            if(mx < (int)st.size())
                mx = (int)st.size();
        }
        return mx;
    }
};