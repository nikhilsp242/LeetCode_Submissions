class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int> s;
        for(int i : nums){
            s.insert(i);
        }
        return *s.begin();
    }
};