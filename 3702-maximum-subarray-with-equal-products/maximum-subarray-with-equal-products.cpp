class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long prod = 1;
            long long lcm1 = nums[i];
            long long gcd1 = nums[i];

            for(int j = i; j < n; j++) {
                prod *= nums[j];

                gcd1 = gcd(gcd1, (long long)nums[j]);

                long long g = gcd((long long)lcm1, (long long)nums[j]);
                lcm1 = (lcm1 / g) * nums[j];
                 if(prod>=1e6) break;
                if(prod == gcd1 * lcm1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};