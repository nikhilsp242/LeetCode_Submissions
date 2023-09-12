class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1]) continue; // skip duplicates
            int j = i + 1;
            int k = n - 1;
            while(j<k){
                int triplets = nums[i] + nums[j] + nums[k];
                if(triplets==0){
                    vector<int> row;
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++; // Skip duplicates
                    while (j < k && nums[k] == nums[k - 1]) k--; // Skip duplicates
                    j++;
                    k--;
                }
                else if(triplets>0) k--;
                else if(triplets<0) j++;
            }
        }
        
        return res;
    }
};