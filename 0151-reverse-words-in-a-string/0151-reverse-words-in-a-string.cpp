class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;
        for(char c : s){
            if(c!=' ') word+=c;
            else if(!word.empty()){
                st.push(word);
                word.clear();
            }
        }
        if(!word.empty()) st.push(word);
        string rev;
        while(!st.empty()){
            rev += st.top() + " ";
            st.pop();
        }
        return rev.substr(0,rev.size()-1);
    }
};