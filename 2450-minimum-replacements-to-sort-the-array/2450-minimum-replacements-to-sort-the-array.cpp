class Solution {
public:
    long long minimumReplacement(vector<int>& nums) { 
        long long op = 0;
        int prev = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>prev){
                int splits = ceil(static_cast<double>(nums[i]) / prev);
                op += splits - 1;
                prev = nums[i]/splits;
            }
            else prev = nums[i];
        }
        return op;
    }
};