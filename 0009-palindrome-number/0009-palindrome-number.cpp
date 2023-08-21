class Solution {
public:
    bool isPalindrome(int x) {
        if(x>=0){
            long long y = 0;
            int c = x;
            while(c>0){
                y = y*10 + c%10;
                c /= 10;
            }
            if(x==y) return true;
        }
        return false;
    }
};