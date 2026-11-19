class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
       temp[0]=temp[n-1];
        temp[1]=temp[n-1];
        sort(temp.begin(),temp.end());
        int mini= temp[n-1]-temp[0];
        temp=nums;
        sort(temp.begin(),temp.end());
        temp[n-1]=temp[0];
        temp[n-2]=temp[0];
        sort(temp.begin(),temp.end());
        mini=min(mini,temp[n-1]-temp[0]);
        sort(nums.begin(),nums.end());
        nums[0]=nums[1];
        nums[n-1]=nums[n-2];
        mini=min(mini,nums[n-1]-nums[0]);
        return mini;


    }
};