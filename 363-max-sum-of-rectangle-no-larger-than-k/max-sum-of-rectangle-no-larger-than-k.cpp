class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
     int m=matrix.size();
     int n=matrix[0].size();
     vector<vector<int>>prefix(m+1,vector<int>(n+1));
     for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+matrix[i-1][j-1];
        }
     }
     int sum=INT_MIN;
     for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int r2=i;r2<=m;r2++){
                for(int c2=j;c2<=n;c2++){
                    int curr = prefix[r2][c2];
                    if (i > 0)
                            curr -= prefix[i-1][c2];

                        if (j > 0)
                            curr -= prefix[r2][j-1];

                        if (i > 0 && j > 0)
                            curr += prefix[i-1][j-1];

                    if(curr<=k){
                   sum=max(sum,curr);
                   if(sum==k) return k;
                    }
                }
            }

        }
     }



 return sum;


    }
};