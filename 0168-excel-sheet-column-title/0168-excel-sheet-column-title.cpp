class Solution {
public:
    string convertToTitle(int columnNumber) {
        string col;
        while(columnNumber>0){
            if(columnNumber%26==0){
                col = 'Z' + col;
                columnNumber = (columnNumber/26) - 1;
            }
            else{
                col = char(columnNumber%26 + 64) + col;
                columnNumber /= 26;
            }
        }
        return col;
    }
};