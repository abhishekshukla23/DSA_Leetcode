class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long opt1=1LL*cost1*need1+1LL*cost2*need2;
         long long opt2=0,opt3=0;
         long long mini=min(need1,need2);
         if(mini==need1){
            opt2=1LL*mini*costBoth+1LL*(need2-mini)*cost2;
         }
         else{
            opt2=1LL*mini*costBoth+1LL*(need1-mini)*cost1;
         }
        long long maxi=max(need1,need2);
        opt3=1LL*maxi*costBoth;

        return min({opt1,opt2,opt3});
        
    }
};