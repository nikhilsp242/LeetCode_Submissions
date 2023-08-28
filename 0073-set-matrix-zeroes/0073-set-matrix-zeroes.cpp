class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int rows = matrix.size();
       int cols = matrix[0].size();

       unordered_set<int> zeroRows,zeroCols;

       for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
               if(matrix[i][j]==0){
                   zeroRows.insert(i);
                   zeroCols.insert(j);
               }
           }
       }
       
       for(int row : zeroRows){
           for(int col=0;col<cols;col++){
               matrix[row][col] = 0;
           }
       }
       for(int col : zeroCols){
           for(int row=0;row<rows;row++){
               matrix[row][col] = 0;
           }
       }
    }
};