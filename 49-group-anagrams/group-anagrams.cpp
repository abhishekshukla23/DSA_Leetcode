class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>>str1;
        for(int i=0;i<strs.size();i++){
            str1.push_back({strs[i],i});
        }
        for(auto &[a,b]:str1){
            sort(a.begin(),a.end());
        }
        vector<vector<string>>ans;
        sort(str1.begin(),str1.end());
         vector<string>temp;
         temp.push_back(strs[str1[0].second]);
        for(int i=1;i<str1.size();i++){
            if(str1[i-1].first==str1[i].first){
               temp.push_back(strs[str1[i].second]);
            }
            else{
                ans.push_back(temp);
                temp.clear();
                temp.push_back(strs[str1[i].second]);
            }
        }
        ans.push_back(temp);
        return ans;

    }
};