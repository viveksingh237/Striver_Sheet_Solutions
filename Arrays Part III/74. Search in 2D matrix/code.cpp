class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Brute force
        // for(int i = 0;i < matrix.size();i++)
        //     for(int j = 0;j < matrix[0].size();j++)
        //       if(matrix[i][j] == target) return true;
        
        // return false;

        //*** In linera time O(m+n)
        // int i = 0;
        // int j = matrix[0].size()-1; // to start from right-top most corner
        // while(j >= 0 and i < matrix.size()){
        //     if(matrix[i][j] == target)
        //     return true;
        //     else if(matrix[i][j] > target)
        //     j--;                             //shift toward left
        //     else
        //     i++;                              //shift toward downwards
        // }
        // return false;


//******** Binary search considering it as 1D array of m*n size
        int low = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int high = m*n - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2; //calc mid
            //if found return ture
            if(matrix[mid/m][mid%m] == target)
            return true;
            //if target is less reduce the high
            else if(matrix[mid/m][mid%m] > target)
            high = mid - 1;
            //if target is greater low if increased
            else
            low = mid + 1;
        }
      return false;
    }
};
