class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l=0,r=0;
        int mini=INT_MAX,maxi=0,mx=0;
        multiset<int>ms;
        while(r<nums.size()){
            ms.insert(nums[r]);
             mini=*ms.begin();
             maxi=*ms.rbegin();
            while(maxi-mini>limit) {
                ms.erase(ms.find(nums[l]));
                l++;
                mini=*ms.begin();
                maxi=*ms.rbegin();
            }
            
            r++;
            mx=max(mx,r-l);
        }
        return mx;
    }
};