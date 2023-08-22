class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod(nums.size(),1);
        int left = 1,right = 1;
        for(int i=0;i<nums.size();i++){
            prod[i] *= left;
            left *= nums[i];
            prod[prod.size()-1-i] *= right;
            right *= nums[nums.size()-1-i];
        }
        return prod;
    }
};