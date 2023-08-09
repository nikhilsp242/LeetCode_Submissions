class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCan = INT_MIN;
        for(int candy : candies){
            maxCan = max(maxCan,candy);
        }
        vector<bool> greatest;
        for(int candy : candies){
            if(candy+extraCandies >= maxCan) greatest.push_back(true);
            else greatest.push_back(false);
        }
        return greatest;
    }
};