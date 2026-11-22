class Solution {
public:
    bool checkString(string s) {
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='a'){
            a++;
            if(b>0) return false;
           }
           else b++;
        }
        return true;
    }
};