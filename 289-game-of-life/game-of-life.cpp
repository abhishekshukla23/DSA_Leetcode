class Solution {
public:
       vector<int>dr = {-1, 1,  0, 0, -1, -1,  1, 1};
  vector<int>dc= { 0, 0, -1, 1, -1,  1, -1, 1};

    void gameOfLife(vector<vector<int>>& board) {
         int m=board.size();
         int n=board[0].size();
         vector<vector<int>>temp(m,vector<int>(n,-1));
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt1=0;
                for(int k=0;k<8;k++){
                    int c=0;
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                         if(board[nr][nc]==1) cnt1++;
                    }
                    
                }
                if(board[i][j]==1){
                    if(cnt1<2 || cnt1>3){
                        temp[i][j]=0;
                    }
                     
                }
                else{
                    if(cnt1==3){
                        temp[i][j]=1;
                    }
                }
            }
         }
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j]!=-1)
                board[i][j]=temp[i][j];
            }
         }
    }
};