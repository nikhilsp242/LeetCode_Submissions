class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startRow = 0 , startColumn = 0;
        int endRow = matrix.size() - 1, endColumn = matrix[0].size()-1;
        vector<int> spiral;

        while(startRow<=endRow && startColumn<=endColumn){
            //right to left
            for(int col = startColumn;col <= endColumn;col++){
                spiral.push_back(matrix[startRow][col]);
            }
            startRow++;
            
            //top to bottom
            for(int row = startRow;row <= endRow; row++){
                spiral.push_back(matrix[row][endColumn]);
            }
            endColumn--;

            //right to left
                // Check if there's still a valid row to traverse
                if (startRow <= endRow) {
                    // Traverse bottom row
                    for (int col = endColumn; col >= startColumn; col--) {
                        spiral.push_back(matrix[endRow][col]);
                    }
                    endRow--;
                }
            
            //bottom to top
                // Check if there's still a valid column to traverse
                if (startColumn <= endColumn) {
                    // Traverse left column
                    for (int row = endRow; row >= startRow; row--) {
                        spiral.push_back(matrix[row][startColumn]);
                    }
                    startColumn++;
                }
        }
        return spiral;
    }
};