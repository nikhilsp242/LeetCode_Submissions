class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        int end = LongestPalindrome(s);
        string p = s.substr(end+1);
        reverse(p.begin(),p.end());

        return p + s;
    }

private:
    int LongestPalindrome(string& s){
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(isPalindrome(s,0,i)) return i;
        }
        return 0;
    }

    bool isPalindrome(const string& s,int left,int right){
        while(left<right){
            if(s[left]!= s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};