class Solution {
public:
   vector<int>dr={-1, -1, -1,  0, 0,  1, 1, 1};
   vector<int>dc={-1,  0,  1, -1, 1, -1, 0, 1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        queue<pair<int,int>>q;
        q.push({click[0],click[1]});
        int m=board.size();
        int n=board[0].size();
        vector<vector<char>>vis(m,vector<char>(n,0));
        vis[click[0]][click[1]]=1;
        while(!q.empty()){
            auto nd=q.front();
            q.pop();
            int r=nd.first;
            int c=nd.second;
            if(board[r][c]=='M'){
                board[r][c]='X';
            }
            else if(board[r][c]=='E'){
                int cnt=0;
                for(int i=0;i<8;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        
                            if(board[nr][nc]=='M') cnt++;
                    
                    }
                }
                if(cnt==0){
                    board[r][c]='B';
                   for(int i=0;i<8;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            
                }
                else {
                    board[r][c]=cnt+'0';
                }
               

            }
        }
        return board;
    }
};