class Solution {
public:
//Using DP optimal solution
int dp[101][101];
int paths(int m,int n,int i,int j){
    if(i == m-1 and j == n-1)
    return 1;
    if(i >= m or j >= n) 
    return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j]=paths(m,n,i+1,j)+paths(m,n,i,j+1);
}

    int uniquePaths(int m, int n) {
       memset(dp ,-1,sizeof(dp));
       return paths(m,n,0,0);
    }
};


// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         int N=n+m-2;
//         int r=m-1;
//         double res=1;
//         for(int i=0;i<=r;i++){
//             res=res*(N-r+i)/i;
//         }
//         int ans= res;
//         return ans;
//     }
// };
