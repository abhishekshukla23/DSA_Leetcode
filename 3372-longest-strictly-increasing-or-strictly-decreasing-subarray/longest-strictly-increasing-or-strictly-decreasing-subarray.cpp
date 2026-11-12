class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
         int cntInc=1;
         int cntDec=1;
         int globalCnt=1;
         for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) {
                cntInc++;
                cntDec=1;
            }
            else if(nums[i]<nums[i-1]){
                cntDec++;
                cntInc=1;
            }
            else{
                cntInc=1;
                cntDec=1;
            }
            globalCnt=max({globalCnt,cntInc,cntDec});
         }
         return globalCnt;
    }
};