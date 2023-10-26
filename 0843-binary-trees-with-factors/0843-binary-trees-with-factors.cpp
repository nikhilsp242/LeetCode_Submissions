class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        unordered_set<int> st;
        unordered_map<int, long long> dp; // Use long long for large numbers
        long long total_count = 0;

        for (int i : arr) st.insert(i);

        for (int i = 0; i < n; i++) {
            dp[arr[i]] = 1; // A single node binary tree is always possible
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && st.count(arr[i] / arr[j])) {
                    dp[arr[i]] += dp[arr[j]] * dp[arr[i] / arr[j]];
                }
            }
            total_count = (total_count + dp[arr[i]]) % (1000000007);
        }

        return total_count % (1000000007);
    }
};