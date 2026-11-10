class Solution {
public:
    int compress(vector<char>& chars) {
       int cnt=1;
       string s="";
       for(int i=1;i<chars.size();i++){
        if(chars[i-1]==chars[i]) {
            cnt++;
        }
        else{
            s+=chars[i-1];
            if(cnt>1)
            s += to_string(cnt);
            cnt=1;

        }
       }
        s+=chars[chars.size()-1];
        if(cnt>1)
        s+=to_string(cnt);
        chars.clear();
        for(int i=0;i<s.size();i++){
            chars.push_back(s[i]);
        }
        
      

       
        return s.size();
    }
};