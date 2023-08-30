class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int,int> m = {0,0};
        unordered_map<int,int> mp;
        for(int num : nums){
            if(++mp[num]>m.second){
                m.second = mp[num];
                m.first = num;
                if (m.second > nums.size() / 2) return m.first;
            }
        }
        return m.first;
    }
};