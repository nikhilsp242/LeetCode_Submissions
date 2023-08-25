class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        queue<int> q;
        for(int num : nums){
            if(q.empty()) q.push(num);
            else if(num!=q.back()) q.push(num);
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