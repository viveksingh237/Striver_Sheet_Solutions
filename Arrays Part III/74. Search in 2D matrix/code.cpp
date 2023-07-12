class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Brute force
        // for(int i = 0;i < matrix.size();i++)
        //     for(int j = 0;j < matrix[0].size();j++)
        //       if(matrix[i][j] == target) return true;
        
        // return false;

        //*** Kind of binary search in matrix
        int i = 0;
        int j = matrix[0].size()-1; // to start from right-top most corner
        while(j >= 0 and i < matrix.size()){
            if(matrix[i][j] == target)
            return true;
            else if(matrix[i][j] > target)
            j--;                             //shift toward left
            else
            i++;                              //shift toward downwards
        }
        return false;
    }
};
