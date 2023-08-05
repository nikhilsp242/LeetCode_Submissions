class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)    
            return 1.0;
        if(n<0){
            x = 1/x;
            n = abs(n);
        }
        double res = 1;
        double base = x;
        while(n>0){
            if(n%2==1)
                res *= base;
            base *= base;
            n /= 2;
        }
        return res;
    }
};