class Solution {
public:
    string digitSum(string s, int k) {
        string temp=s;
        while(temp.size()>k){
            string temp1="";
            int l=0,h=k;
            while(l<temp.size()){
            int sum=0;
               while(l<temp.size()&&l<h){
                 sum+=(temp[l]-'0');
                l++;
               }
                if(l==h || l==temp.size()){
                    temp1+=to_string(sum);
                    l=h;
                    h=h+k;
                }
            
            }
            temp=temp1;
        
        }
        return temp;
    }
};