class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp=nums;
        int n=nums.size();
       temp[0]=temp[n-1];
        temp[1]=temp[n-1];
        int mini=*max_element(temp.begin(),temp.end())-*min_element(temp.begin(),temp.end());
        temp=nums;
        temp[n-1]=temp[0];
        temp[n-2]=temp[0];
        mini=min(mini,*max_element(temp.begin(),temp.end())-*min_element(temp.begin(),temp.end()));
        nums[0]=nums[1];
        nums[n-1]=nums[n-2];
        mini=min(mini,nums[n-1]-nums[0]);
        return mini;


    }
};