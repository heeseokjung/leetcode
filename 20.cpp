class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int size = (int)s.size();
        for(int i = 0; i < size; ++i) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if(st.empty()) {
                return false;
            } else {
                char p = st.top();
                st.pop();
                if(s[i] == ')' && p != '(')
                    return false;
                else if(s[i] == '}' && p != '{')
                    return false;
                else if(s[i] == ']' && p != '[')
                    return false;
            }
        }
        
        if(st.size())
            return false;
        else
            return true;
    }
};