class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowRow = 0;
        int highRow = matrix.size()-1;
        int rowSize = matrix[0].size();


        while(lowRow <= highRow){
            int midRow = lowRow + (highRow - lowRow) / 2;
            int midFirst = matrix[midRow][0];
            int midLast = matrix[midRow][rowSize-1];

            if(midLast < target){
                lowRow = midRow+1;
            }else if(midFirst > target){
                highRow = midRow-1;
            }else{
                for(size_t i = 0; i<rowSize; i++){
                    if(matrix[midRow][i] == target){
                        return true;
                    }
                }
                return false;
            }
        }

        return false;
    }
};
