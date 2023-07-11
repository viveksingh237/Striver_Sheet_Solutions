class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // *** Using extra space
        // int n=matrix.size();
        // vector<vector<int>> matrix1 = matrix;
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < n;j++){
        //         matrix[j][n-i-1] = matrix1[i][j];
        //     }
        // }

        //***** Without extra space O(1)
        //we take transpose
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++)
            swap(matrix[i][j],matrix[j][i]);
        }
        // **** reversing the rows
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size()/2;j++)
            swap(matrix[i][j],matrix[i][matrix.size()-j-1]);
        }

    }
};
