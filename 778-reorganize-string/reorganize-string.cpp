class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for(char c:s){
          freq[c-'a']++;
        }
        string ans="";
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++){
            if(freq[i]) pq.push({freq[i],i});
        }
        while(!pq.empty()){
           auto top1=pq.top();
           top1.first--;
           pq.pop();
             ans+=top1.second+'a';
           if(!pq.empty()){
            auto top2=pq.top();
            pq.pop();
            ans+=top2.second+'a';
            top2.first--;
            if(top2.first) pq.push(top2);
             if(top1.first) pq.push(top1);
           }
           else {
           if(top1.first>0) return "";
           }
           
        }
        // for(int i=1;i<ans.size();i++) if(ans[i-1]==ans[i]) return "";
        if(!pq.empty()) return "";

return ans;

    }
};