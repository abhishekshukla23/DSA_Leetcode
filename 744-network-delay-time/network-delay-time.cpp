class Solution {
public:
    void dfs( vector<vector<pair<int,int>>>&adj,int k,int time,vector<int>&dist){
        for(auto [node,wt]:adj[k]){
            if(time+wt<dist[node]){
                dist[node]=time+wt;
                dfs(adj,node,time+wt,dist);
            }
            
        }
        return;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            auto temp=times[i];
            int src=temp[0],dest=temp[1],wt=temp[2];
            adj[src].push_back({dest,wt});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        dfs(adj,k,0,dist);
        int mini=*max_element(dist.begin()+1,dist.end());
        return mini==INT_MAX?-1:mini;
    }
};