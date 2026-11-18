class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size())
    return s;
    if(numRows == 2) {
    string ans = "";
    for(int i = 0; i < s.size(); i += 2)
        ans += s[i];

    for(int i = 1; i < s.size(); i += 2)
        ans += s[i];

    return ans;
}
      int col=0, j=0;
        while(j<s.size()){
            j+=numRows;
            if(j<s.size()) col++;
            j++;
            if(j<s.size()) col++;
        }
        col+=1;
        vector<vector<char>>temp(numRows,vector<char>(col,'0'));
        int indx=0;
       for(int i=0;i<col;i++){

        for(int j=0;j<numRows;j++){
            if(indx>=s.size()) break;
            if(i%2!=0){
               if(numRows-j-2>=0 && j<numRows-2) temp[numRows-j-2][i]=s[indx++];
                else continue;
            }
            else{
                 if(indx>=s.size()) break;
                temp[j][i]=s[indx++];
            }
        }
       }
       string ans="";
       for(int i=0;i<numRows;i++){
        for(int j=0;j<col;j++){
            if(temp[i][j]!='0'){
                ans+=temp[i][j];
            }
        }
       }
       return ans;
    }
};