class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()){
                res.push_back(mp[complement]);
                res.push_back(i);
                return res;
            }

            mp[nums[i]] = i;
        }
        return res;
    }
};