class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int btwise=-1;
            int mini=INT_MAX;
            for(int j=i;j<nums.size();j++){
                btwise=btwise&nums[j];
                mini=min(mini,nums[j]);
                if(btwise==mini) ans++;
            }
        }
       
        return ans;
    }
};