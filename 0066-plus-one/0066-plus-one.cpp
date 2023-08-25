class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> sum;
        for(int i=digits.size()-1;i>=0;i--){
            int add = digits[i] + carry;
            sum.push_back(add%10);
            carry = add/10;
        }
        if(carry>0) sum.push_back(carry);
        reverse(sum.begin(),sum.end());
        return sum;
    }
};