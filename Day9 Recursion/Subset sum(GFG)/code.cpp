//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private://Using recursion
 void solve(vector<int> &arr,int sum,int n,int ind,vector<int> &ans){
     if(ind == n){
         ans.push_back(sum);
         return;
     }//pick the element
     solve(arr,sum+arr[ind],n,ind + 1,ans);
     //donot pick the element
     solve(arr,sum,n,ind + 1,ans);
 }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr,0,N,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
