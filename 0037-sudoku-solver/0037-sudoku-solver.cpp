class Solution {
public:
    //to check if a number is present in a row or a col or a 3x3 sub box
    bool isPresent(vector<vector<char>>& board,int row,int col,int num){
        for(int i=0;i<9;i++){
            if(board[row][i]==num || board[i][col]==num) return true;
        }
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[startRow + i][startCol + j] == num) return true;  //number is present, cannot be used
            }
        }
        return false;
    }
    bool sudokuSolver(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char num = '1';num <= '9';num++){
                        if(!isPresent(board,row,col,num)){
                            board[row][col] = num;
                            if(sudokuSolver(board)) return true;
                            board[row][col] = '.';  //backtrack and try next number
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board);
    }
};