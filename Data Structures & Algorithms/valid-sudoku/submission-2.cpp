class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row_occurency(9, vector<bool>(9));
        vector<vector<bool>> col_occurency(9, vector<bool>(9));
        vector<vector<bool>> squares_occurency(9, vector<bool>(9));

        for(size_t i = 0; i<9; i++){
            for(size_t j = 0; j<9; j++){
                if(isdigit(board[i][j])){
                    int num = board[i][j] - '0' - 1;
                    if(row_occurency[i][num] == 1) return false;
                    else row_occurency[i][num] = 1;

                    if(col_occurency[j][num] == 1) return false;
                    else col_occurency[j][num] = 1;

                    int squareX = i/3;
                    int squareY = j/3;
                    if(squares_occurency[squareX + 3 * squareY][num] == 1) return false;
                    else squares_occurency[squareX +  3 * squareY][num] = 1;
                }

            }
        }



        return true;
    }
};
