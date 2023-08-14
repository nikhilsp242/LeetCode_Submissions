class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(),nums.end());           //69 ms    //45.64 mb
        nth_element(nums.begin(),nums.begin() + nums.size() - k,nums.end());      //61 ms    //45.56 mb
        return nums[nums.size()-k];
    }
};
