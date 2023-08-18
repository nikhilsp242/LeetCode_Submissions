class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> st;
        st.push(-1); 
        int maxLength = 0;

        for (int i = 0; i < len; i++) {
            if (s[i] == '(') st.push(i);
            else { 
                st.pop();

                if (st.empty()) st.push(i);
                else maxLength = max(maxLength, i - st.top());
            }
        }
        return maxLength;
    }
};