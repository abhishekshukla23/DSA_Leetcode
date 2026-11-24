class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string smaller="";
        int m1=str1.size(),m2=str2.size();
        if(m1<m2){
            smaller=str1;
           
              for(int i=m1-1;i>=0;i--){
                int sz=smaller.size();
                int cnt1=0,cnt2=0;
                for(int j=0;j<m2;j+=sz){
                    if(str2.substr(j,sz)==smaller) cnt1++;
                }
                for(int j=0;j<m1;j+=sz){
                    if(str1.substr(j,sz)==smaller) cnt2++;
                }
                if(cnt1*sz==m2 && cnt2*sz==m1) return smaller;
                smaller.pop_back();
              }
            
            

        }
        else{
            smaller=str2;
           
              for(int i=m2-1;i>=0;i--){
                int sz=smaller.size();
                int cnt1=0,cnt2=0;
                for(int j=0;j<m1;j+=sz){
                    if(str1.substr(j,sz)==smaller) cnt1++;
                }
                  for(int j=0;j<m2;j+=sz){
                    if(str2.substr(j,sz)==smaller) cnt2++;
                }
                if(cnt1*sz==m1 && cnt2*sz==m2) return smaller;
                smaller.pop_back();
              }
            

        }
        return "";
    }
};