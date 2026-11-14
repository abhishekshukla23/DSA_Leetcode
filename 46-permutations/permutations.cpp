class Solution {
public:
    void permutations(vector<int>&nums,int ind,vector<vector<int>>&ans,vector<int>&vis,vector<int>temp){
        // vector<int>temp;
        if(temp.size()==nums.size()){
             ans.push_back(temp);
             return;
        }
             for(int i=0;i<nums.size();i++){
                if(!vis[i]){
                    temp.push_back(nums[i]);
                    vis[i]=1;
                    permutations(nums,i,ans,vis,temp);
                    temp.pop_back();
                    vis[i]=0;
                }

             }
        }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>vis(nums.size(),0);
        vector<int>temp;
        permutations(nums,0,ans,vis,temp);
        return ans;
    }
};