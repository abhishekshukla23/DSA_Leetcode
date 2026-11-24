class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd1=nums[0];
        for(int i=0;i<nums.size();i++){
            gcd1=gcd(gcd1,nums[i]);
            if(gcd1==1) return true;
        }
    return false;
    }
};