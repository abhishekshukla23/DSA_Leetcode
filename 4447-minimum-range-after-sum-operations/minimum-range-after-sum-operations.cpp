class Solution {
public:
    int minRange(int a, int b, int c) {
        int ans=INT_MAX;
        int suma=b+c;
        int sumb=a+c;
        int sumc=b+a;
        return min({max({a,b,sumc})-min({a,b,sumc}),max({a,c,sumb})-min({a,c,sumb}),max({b,c,suma})-min({b,c,suma}),max({a,b,c})-min({a,b,c})});
    }
};