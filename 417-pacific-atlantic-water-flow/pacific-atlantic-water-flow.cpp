class Solution {
public:
vector<int>dr={0,-1,0,1};
vector<int>dc={-1,0,1,0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>pacific(m,vector<int>(n)),atlantic(m,vector<int>(n));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            q.push({i,0});
            pacific[i][0]=1;
        }
        for(int i=0;i<n;i++){
            q.push({0,i});
            pacific[0][i]=1;
        }
        while(!q.empty()){
            auto node=q.front();
            int r=node.first;
            int c=node.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr<0|| nr>=m || nc<0 || nc>=n){
                    continue;
                }
                if(!pacific[nr][nc] && heights[nr][nc]>=heights[r][c]){
                     pacific[nr][nc]=1;
                     q.push({nr,nc});
                }
            }

        }
         for(int i=0;i<m;i++){
            q.push({i,n-1});
            atlantic[i][n-1]=1;
        }
        for(int i=0;i<n;i++){
            q.push({m-1,i});
            atlantic[m-1][i]=1;
        }
        while(!q.empty()){
            auto node=q.front();
            int r=node.first;
            int c=node.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr<0|| nr>=m || nc<0 || nc>=n){
                    continue;
                }
                if(!atlantic[nr][nc] && heights[nr][nc]>=heights[r][c]){
                     atlantic[nr][nc]=1;
                     q.push({nr,nc});
                }
            }

        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                  if(atlantic[i][j]==1 && pacific[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};