//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    { 
    //     //******Using sorting 
    // 	sort(arr,arr + n);
    // 	sort(dep,dep + n);
    	
    // 	int cnt = 0;
    // 	int maxi = 0;
    // 	int i = 0,j = 0;
    // 	while(i < n and j < n){
    // 	    if(arr[i] <= dep[j]){
    // 	        cnt++;
    // 	        maxi = max(maxi, cnt);
    // 	        i++;
    // 	    }
    // 	    else{
    // 	        cnt--;
    // 	        j++;
    // 	    }
    // 	}
        
    //     return maxi;
    
    
           //Using Sweep Line algo
           int maxDep = 0;
           for(int i = 0;i < n;i++) maxDep =max(maxDep,dep[i]);
    
           vector<int> hash(maxDep+2, 0);
    
           for(int i = 0;i < n;i++){
               hash[arr[i]]++;
               hash[dep[i] + 1]--;
           }
           int maxi = 0;
           int sum = 0;
           for(auto& x : hash){
               sum += x;
               maxi = max(maxi, sum);
           }
           return maxi;
    
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
