class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        for(int num : nums2) s2.insert(num);

        vector<vector<int>> diff(2);

        for(int num : nums1){
            if(s2.find(num) == s2.end()) {
                diff[0].push_back(num);
                s2.insert(num);
            }
            s1.insert(num);
        }

        for(int num : nums2){
            if(s1.find(num) == s1.end()){
                diff[1].push_back(num);
                s1.insert(num);
            }
        }
        return diff;
    }
};