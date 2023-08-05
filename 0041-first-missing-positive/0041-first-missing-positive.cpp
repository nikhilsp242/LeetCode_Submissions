class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxNum)
                maxNum = nums[i];
        }
        
        if (maxNum <= 0)
            return 1; 
            
        unordered_set<int> present;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                present.insert(nums[i]);
        }
        
        for (int i = 1; i <= maxNum; i++) {
            if (present.find(i) == present.end()) //find() returns end() if not found
                return i;
        }
        
        return maxNum + 1;
    }
};