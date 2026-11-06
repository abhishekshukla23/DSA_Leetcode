class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int,int>>temp;
        for(int i=0;i<queries.size();i++) temp.push_back({queries[i],i});
        sort(logs.begin(),logs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        vector<int>ans(queries.size());
        int l=0,r=0;
        unordered_map<int,int>mp;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            int cnt=0;
            int start=temp[i].first-x;
            int terminate=temp[i].first;
            while(r<logs.size() && terminate>=logs[r][1]){
                  mp[logs[r][0]]++;
                r++;
            }
            while(l<r && logs[l][1]<start){
                mp[logs[l][0]]--;
                if(mp[logs[l][0]]==0) mp.erase(logs[l][0]);
                l++;
            }
            cnt+=(n-mp.size());
            ans[temp[i].second]=cnt;
        }
        return ans;
    }
};