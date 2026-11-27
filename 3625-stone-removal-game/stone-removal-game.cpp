class Solution {
public:
    bool canAliceWin(int n) {
        int cnt=1;
        int sum=10;
        while(true){
             if(cnt==1){
                if(sum>n) return false;
                else{
                    n-=sum;
                    sum--;
                    cnt=0;
                }
             }
             else {
                if(sum>n) return true;
                else{
                    n-=sum;
                    sum--;
                    cnt=1;
                }
             }
            
             }
        
        return true;
    }
};