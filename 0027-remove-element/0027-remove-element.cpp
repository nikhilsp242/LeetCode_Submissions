class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int> q;
        for(int num : nums){
            if(q.empty() && num!=val) q.push(num);
            else if(num!=val) q.push(num);
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