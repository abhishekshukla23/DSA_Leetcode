class Solution {
public: 

    int climb(int step,int n,vector<int>&costs,vector<int>&dp){
       if(step==n){
        return 0;
       }
       if(dp[step]!=-1) return dp[step];
       int step1=1e7,step2=1e7,step3=1e7;
    if(step+1<=n)
     step1=costs[step]+1+climb(step+1,n,costs,dp);
     if(step+2<=n)
       step2=costs[step+1]+4+climb(step+2,n,costs,dp);
       if(step+3<=n)
         step3=costs[step+2]+9+climb(step+3,n,costs,dp);
     return dp[step]=min({step1,step2,step3});

    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,1e7);
        dp[n]=0;
        for(int step=n-1;step>=0;step--){
            int step1=1e7,step2=1e7,step3=1e7;
            if(step+1<=n)
     step1=costs[step]+1+dp[step+1];
     if(step+2<=n)
       step2=costs[step+1]+4+dp[step+2];
       if(step+3<=n)
         step3=costs[step+2]+9+dp[step+3];
     dp[step]=min({step1,step2,step3});
        }
        return dp[0];

    }
};