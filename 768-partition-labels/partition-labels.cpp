class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>mp;
        for(char c:s){
            mp[c]++;
        }
        int l=0,h=0;
       set<char>st;
        vector<int>ans;
        while(h<s.size()){
            char ch=s[h];
           mp[ch]--;
           if(mp[ch]==0) {
            st.erase(ch);
            mp.erase(ch);
            if(st.size()==0){
                    ans.push_back(h-l+1);
             l=h+1;
            }
             
           }
           else{
            st.insert(ch);
           }
          h++;
        }
        return ans;



    }
};