class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        if(s==t) return t;

        unordered_map<char,int> mp1,mp2;
        
        for(char c : t) {
            mp1[c]++;
        }
        
        queue<int> q;
        string res = s+'a';
        
        for (int i = 0; i < s.size(); i++) {
            if (mp1.find(s[i]) != mp1.end()) {
                mp2[s[i]]++;
                q.push(i);
                while (!q.empty() && mp2[s[q.front()]] > mp1[s[q.front()]]) {
                    mp2[s[q.front()]]--;
                    q.pop();
                }
                bool valid = true;
                char f = s[q.front()];
                for(const auto& pair : mp1){
                    char c = pair.first;
                    if(c!=f){
                        if(mp2[c]<mp1[c]) {
                            valid = false;
                            break;
                        }    
                    }
                    else if(c==f){
                        if(mp2[c]!=mp1[c]){
                            valid = false;
                            break;
                        }
                    }
                }
                if (valid ) {
                    int length = i - q.front() + 1; 
                    if (length < res.size()) {
                        res = s.substr(q.front(), length);
                    }
                }
            }
        }

        if(res.size()>s.size()) return "";
        else return res; 
    }
};