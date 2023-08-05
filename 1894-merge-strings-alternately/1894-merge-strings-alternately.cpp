class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0 , j=0;
        int length = word1.length() + word2.length();
        string mergedStr;
        for(int k = 0;k < length;k++){
            if(i<word1.length())
                mergedStr += word1[i++];
            if(j<word2.length())
                mergedStr += word2[j++];
        }
        return mergedStr;
    }
};