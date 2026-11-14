class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        for (int low = 0; low < n; low++) {
            for (int high = low + l; high <= min(n, low + r); high++) {
                int sum = pref[high] - pref[low];

                if (sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};