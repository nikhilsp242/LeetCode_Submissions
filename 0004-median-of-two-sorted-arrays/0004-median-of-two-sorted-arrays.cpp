class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        double median;
        if(nums1.size() % 2 == 1){
            median = nums1[nums1.size()/2];
            return median;
        }
        else{
            median = nums1[(nums1.size()-1)/2] + nums1[nums1.size()/2];
            return median/2;
        }
    }
};