class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Deque to store indices of elements

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements from the front that are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements from the back that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Start adding maximum elements to the result once the window size reaches k
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};