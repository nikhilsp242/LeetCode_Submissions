class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        queue<int> q;
        unordered_map<int,int> mp;
        for(int num : nums){
            if(q.empty()) {
                q.push(num);
                mp[num]++;
            }
            else if(mp[num] <2 ){
                q.push(num);
                mp[num]++;
            } 
        }
        int k = q.size();
        int i = 0;
        while(!q.empty()){
            nums[i++] = q.front();
            q.pop();
        }
        return k;
    }
};