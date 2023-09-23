class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size()<=1) return s;
        string rev = s;
        reverse(rev.begin(),rev.end());
        if(s==rev) return s;
        
        int k = computeKMP(s + "#" + rev);
        string p = s.substr(k);
        reverse(p.begin(),p.end());

        return p + s;
    }

private:
    int computeKMP(const string& s){
        int n = s.size();
        vector<int> kmp(n,0);

        int j = 0;
        for(int i=1;i<n;i++){
            while(j>0 && s[i]!=s[j]) j = kmp[j-1];
            if(s[i] == s[j]) j++;
            kmp[i] = j;
        }
        return kmp.back();
    }
};
