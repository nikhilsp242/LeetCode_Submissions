class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<lcp.size()){
                if(lcp[j]!=strs[i][j]) lcp = strs[i].substr(0,j);
                j++;
            }
            if(lcp.size()==0) return lcp;
        }
        return lcp;
    }
};