class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0,j = 0;
        while(i<haystack.size() && j<needle.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                i = i-j+1;
                j = 0;
            } 
            if(j==needle.size()) return i-j;
        }
        return (j == needle.size()) ? i - j : -1;
    }
};