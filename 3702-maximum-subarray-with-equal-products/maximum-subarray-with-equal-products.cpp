class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        const long long LIMIT = 2520LL * 10; // max possible gcd * lcm

        for (int i = 0; i < n; i++) {
            long long g = 0, l = 1, prod = 1;

            for (int j = i; j < n; j++) {
                g = gcdll(g, nums[j]);
                l = (l / gcdll(l, nums[j])) * nums[j];
                prod *= nums[j];

                if (prod > LIMIT) break; // can never match again; also prevents overflow

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};