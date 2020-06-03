class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = (int)s.size(), mx = 0;
        set<char> st;
        deque<char> dq;
        for(int i = 0; i < size; ++i) {
            if(st.find(s[i]) == st.end()) {
                st.insert(s[i]);
                dq.push_back(s[i]);
            } else {
                while(true) {
                    char f = dq.front();
                    dq.pop_front();
                    st.erase(f);
                    if(f == s[i])
                        break;
                }
                st.insert(s[i]);
                dq.push_back(s[i]);
            }
            
            if(mx < (int)dq.size())
                mx = (int)dq.size();
        }
        
        return mx;
    }
};