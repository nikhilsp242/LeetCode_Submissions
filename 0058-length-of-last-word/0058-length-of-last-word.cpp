class Solution {
public:
    int lengthOfLastWord(string s) {
        string chars,word ;
        int l = 0;
        for(char c : s){
            if(c!=' ') chars+=c;
            else if(!chars.empty()){
                word = chars;
                chars.clear();
            }
        }
        if(!chars.empty())  return chars.size();
        if(!word.empty()) return word.size();
        return 0;
    }
};