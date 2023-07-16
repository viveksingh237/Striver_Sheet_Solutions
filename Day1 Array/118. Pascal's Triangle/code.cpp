class Solution {
public:

vector<int> Row(int r){
     vector<int> row;
            int x=1;
            row.push_back(x);
            for(int i=1;i<r;i++){
                x = x*(r - i)/i; // calc n-1 C r-1
                row.push_back(x);
            }
            //row.push_back(1); it will be extra one
            return row;
        }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int n=numRows;
        for(int i=1;i<=n;i++)
        ans.push_back(Row(i));
        //reverse(ans.begin(),ans.end());  // <-- for bottom up
        return ans;


//************  without function for the row
        // vector<vector<int>> ans;
        // int n=numRows,r;
        // while(n){
        //     vector<int> row;
        //     int x=1;
        //     row.push_back(x);
        //     for(int i=1;i<n;i++){
        //         x = x*(n - i)/i; // calc n-1 C r-1
        //         row.push_back(x);
        //     }
        //     //row.push_back(1); it will be extra one
        //     ans.push_back(row);
        //     n--;
        // }
        // // since we calculated bottom up
        // reverse(ans.begin(),ans.end());
        // return ans;
    }
};
