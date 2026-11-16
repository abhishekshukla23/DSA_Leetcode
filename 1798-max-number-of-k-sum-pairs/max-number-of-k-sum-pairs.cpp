class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,h=nums.size()-1;
        int cnt=0;
        while(l<h){
            if(nums[l]+nums[h]==k){
                l++;
                h--;
                cnt++;
            }
            else if(nums[l]+nums[h]<k){
                l++;
            }
            else{
                h--;
            }
        }
        return cnt;
    }
};